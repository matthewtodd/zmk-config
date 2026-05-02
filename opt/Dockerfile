FROM ubuntu:noble-20250925

RUN \
  --mount=type=cache,target=/var/cache/apt,sharing=locked \
  --mount=type=cache,target=/var/lib/apt,sharing=locked \
  --mount=type=bind,src=opt/packages.txt,dst=/opt/packages.txt <<-END
  rm -f /etc/apt/apt.conf.d/docker-clean
  echo 'Binary::apt::APT::Keep-Downloaded-Packages "true";' > /etc/apt/apt.conf.d/keep-cache
  apt-get -y update
  apt-get -y install $(grep -v '#' /opt/packages.txt)
END

RUN \
  --mount=type=cache,target=/root/.cache/pip \
  --mount=type=bind,src=opt/requirements.txt,dst=/opt/requirements.txt <<-END
  pip3 install \
    --break-system-packages \
    -r https://raw.githubusercontent.com/zephyrproject-rtos/zephyr/v3.5.0/scripts/requirements-base.txt \
    -r /opt/requirements.txt
END

ADD --unpack=true https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.3/zephyr-sdk-0.16.3_linux-aarch64_minimal.tar.xz /opt
ADD --unpack=true https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.3/toolchain_linux-aarch64_arm-zephyr-eabi.tar.xz /opt/zephyr-sdk-0.16.3

RUN <<-END
  cd /opt/zephyr-sdk-0.16.3
  ./setup.sh -h -c -t arm-zephyr-eabi
END

RUN \
  --mount=type=cache,target=/var/cache/west \
  --mount=type=bind,src=src/zmk/config/west.yml,dst=/src/zmk/config/west.yml <<-END
  cd /src/zmk
  west init -l /src/zmk/config
  west update --fetch-opt=--filter=tree:0 --auto-cache /var/cache/west
  west zephyr-export
END

ADD --keep-git-dir https://github.com/qmk/qmk_firmware.git?tag=0.32.12 /src/qmk_firmware
ADD --unpack=true https://github.com/qmk/qmk_toolchains/releases/download/v15.2.0-1/qmk_toolchains-gcc15.2.0-host_linuxARM64.tar.zst /opt/qmk

ENV PATH=/opt/qmk/qmk_toolchains_linuxARM64/bin:$PATH \
    QMK_DISTRIB_DIR=/opt/qmk \
    QMK_HOME=/src/qmk_firmware \
    QMK_USERSPACE=/src/qmk \
