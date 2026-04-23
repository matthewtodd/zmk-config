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
