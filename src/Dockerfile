FROM docker.io/zmkfirmware/zmk-build-arm:stable

RUN <<-END
  apt-get -y update
  apt-get -y install python3-pip
  pip install keymap-drawer --break-system-packages
END

WORKDIR /src/zmk

RUN --mount=type=bind,src=src/zmk/config/west.yml,dst=/src/zmk/config/west.yml <<-END
  west init -l /src/zmk/config
  west update --fetch-opt=--filter=tree:0
  west zephyr-export
END
