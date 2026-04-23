FROM docker.io/zmkfirmware/zmk-build-arm:stable

RUN <<-END
  apt-get -y update
  apt-get -y install python3-pip
  pip install keymap-drawer --break-system-packages
END

WORKDIR /app

RUN --mount=type=bind,src=config/west.yml,dst=config/west.yml <<-END
  west init -l /app/config
  west update --fetch-opt=--filter=tree:0
  west zephyr-export
END

COPY --chmod=755 <<-"END" entrypoint
  subcommand=$1
  shift

  case ${subcommand} in
    build)
      while getopts "a:b:s:" opt; do
        case ${opt} in
          a) artifact=${OPTARG} ;;
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
         out/firmware/${artifact:-${shield}-${board}}.uf2
      ;;

    draw)
      while getopts "d:k:" opt; do
        case ${opt} in
          d)
            extra_args="--dts-layout ${OPTARG}"
            ;;
          k)
            input=config/${OPTARG}.keymap
            output=out/img/${OPTARG}.svg
            ;;
        esac
      done

      keymap -c config/keymap-drawer.yml parse -z ${input} > keymap.yml
      keymap -c config/keymap-drawer.yml draw -o ${output} ${extra_args} keymap.yml
      ;;
  esac
END

ENTRYPOINT ["/bin/bash", "/app/entrypoint"]
