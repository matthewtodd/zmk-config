FROM docker.io/zmkfirmware/zmk-build-arm:stable

RUN <<-END
  apt-get -y update
  apt-get -y install python3-pip
  pip install keymap-drawer --break-system-packages
END
