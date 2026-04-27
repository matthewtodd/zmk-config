FROM ubuntu:noble-20250925

RUN --mount=type=bind,src=src/docker/packages.txt,dst=/tmp/packages.txt <<-END
  apt-get -y update
  apt-get -y install $(grep -v '#' /tmp/packages.txt)
END

RUN --mount=type=bind,src=src/docker/requirements.txt,dst=/tmp/requirements.txt <<-END
  pip3 install \
    --break-system-packages \
    -r https://raw.githubusercontent.com/zephyrproject-rtos/zephyr/v3.5.0/scripts/requirements-base.txt \
    -r /tmp/requirements.txt
END

ADD --unpack=true https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.3/zephyr-sdk-0.16.3_linux-aarch64_minimal.tar.xz /opt

RUN <<-END
  cd /opt/zephyr-sdk-0.16.3
  ./setup.sh -h -c -t arm-zephyr-eabi
END
