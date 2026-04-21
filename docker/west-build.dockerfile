FROM docker.io/zmkfirmware/zmk-build-arm:stable

WORKDIR /workspaces

# Cache all our dependencies!
# I like not having them spread out over my local filesystem, and I appreciate
# the controlled predictability of having them in a read-only image like this.
#
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
  west init -l /workspaces/config
  west update --fetch-opt=--filter=tree:0
  west zephyr-export
END

SHELL ["/bin/sh", "-c"]
CMD \
  west build \
    -s zmk/app \
    -d /workspaces/build \
    -b ${BOARD} \
    -- \
    -DZMK_CONFIG=/workspaces/config \
    -DSHIELD=${SHIELD} \
  && \
  cp /workspaces/build/zephyr/zmk.uf2 \
     /workspaces/firmware/${SHIELD}-${BOARD}.uf2
