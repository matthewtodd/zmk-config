FROM docker.io/zmkfirmware/zmk-build-arm:stable

RUN --mount=type=bind,src=src/docker/packages.txt,dst=/src/docker/packages.txt \
  apt-get -y update && \
  apt-get -y install $(grep -v '#' /src/docker/packages.txt)

RUN --mount=type=bind,src=src/docker/requirements.txt,dst=/src/docker/requirements.txt \
  pip install -r /src/docker/requirements.txt --break-system-packages
