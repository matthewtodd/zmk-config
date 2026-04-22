FROM docker.io/zmkfirmware/zmk-build-arm:stable

# Install keymap-drawer, too!
RUN <<-END
  apt-get -y update
  apt-get -y install python3-pip
  pip install keymap-drawer --break-system-packages
END

WORKDIR /app

# Cache all our dependencies!
# Initial run takes about 6 minutes, but subsequent runs can use Docker's layer
# cache, so long as config/west.yml hasn't changed. I expect I won't be adding
# modules (i.e. changing config/west.yml) nearly as frequently as I'm tweaking
# my keymaps (i.e. changing other things in config/), so this seems like an
# okay way to do it.
#
# Note that this config/west.yml isn't left in the image -- we're using a bind
# mount rather than COPY both in order to make the dependency explicit and
# because later calls of `docker run` are expected to mount the whole config
# directory (with keymaps, etc.) for building.
RUN --mount=type=bind,src=config/west.yml,dst=config/west.yml <<-END
  west init -l /app/config
  west update --fetch-opt=--filter=tree:0
  west zephyr-export
END

# I'm somewhat taken with this idea of being able to call the Dockerfile like a
# script. Indeed, I think I'd use
# https://github.com/JakeWharton/dockerfile-shebang if I didn't have to specify
# all these bind mounts.
COPY --chmod=755 <<-"END" entrypoint
  subcommand=$1
  shift

  case ${subcommand} in
    build)
      while getopts "b:s:" opt; do
        case ${opt} in
          b) board=${OPTARG} ;;
          s) shield=${OPTARG} ;;
        esac
      done

      west build \
        -s zmk/app \
        -d $(pwd)/build \
        -b ${board} \
        -- \
        -DZMK_CONFIG=$(pwd)/config \
        -DSHIELD=${shield}

      cp build/zephyr/zmk.uf2 \
         out/firmware/${shield}-${board}.uf2
      ;;

    draw)
      while getopts "k:" opt; do
        case ${opt} in
          k)
            input=config/${OPTARG}.keymap
            output=out/img/${OPTARG}.svg
            ;;
        esac
      done

      keymap -c config/keymap-drawer.yml parse -z ${input} | \
      keymap -c config/keymap-drawer.yml draw -o ${output} -
      ;;
  esac
END

ENTRYPOINT ["/bin/bash", "/app/entrypoint"]
