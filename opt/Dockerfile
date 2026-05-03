FROM ubuntu:noble-20250925

RUN --mount=type=cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,target=/var/lib/apt,sharing=locked \
    --mount=type=bind,src=opt/packages.txt,dst=/opt/packages.txt \
    rm -f /etc/apt/apt.conf.d/docker-clean \
    && echo 'Binary::apt::APT::Keep-Downloaded-Packages "true";' > /etc/apt/apt.conf.d/keep-cache \
    && apt-get -y update \
    && apt-get -y install $(grep -v '#' /opt/packages.txt)

ARG ZEPHYR_VERSION=3.5.0
RUN --mount=type=cache,target=/root/.cache/pip \
    --mount=type=bind,src=opt/requirements.txt,dst=/opt/requirements.txt \
    pip3 install --break-system-packages \
      --requirement https://raw.githubusercontent.com/zephyrproject-rtos/zephyr/v${ZEPHYR_VERSION}/scripts/requirements-base.txt \
      --requirement /opt/requirements.txt

ARG ZEPHYR_SDK_VERSION=0.16.3
ADD --unpack=true https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v${ZEPHYR_SDK_VERSION}/zephyr-sdk-${ZEPHYR_SDK_VERSION}_linux-aarch64_minimal.tar.xz /opt
ADD --unpack=true https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v${ZEPHYR_SDK_VERSION}/toolchain_linux-aarch64_arm-zephyr-eabi.tar.xz /opt/zephyr-sdk-${ZEPHYR_SDK_VERSION}
RUN cd /opt/zephyr-sdk-${ZEPHYR_SDK_VERSION} && ./setup.sh -h -c -t arm-zephyr-eabi

RUN --mount=type=cache,target=/var/cache/west \
    --mount=type=bind,src=src/zmk/config/west.yml,dst=/src/zmk/config/west.yml \
    cd /src/zmk \
    && west init -l /src/zmk/config \
    && west update --fetch-opt=--filter=tree:0 --auto-cache /var/cache/west \
    && west zephyr-export

ARG QMK_FIRMWARE_VERSION=0.32.12
ARG QMK_TOOLCHAINS_VERSION=15.2.0
ARG QMK_TOOLCHAINS_VERSION_SUFFIX=1
ADD --keep-git-dir https://github.com/qmk/qmk_firmware.git?tag=${QMK_FIRMWARE_VERSION} /src/qmk_firmware
ADD --unpack=true https://github.com/qmk/qmk_toolchains/releases/download/v${QMK_TOOLCHAINS_VERSION}-${QMK_TOOLCHAINS_VERSION_SUFFIX}/qmk_toolchains-gcc${QMK_TOOLCHAINS_VERSION}-host_linuxARM64.tar.zst /opt/qmk
ENV PATH=/opt/qmk/qmk_toolchains_linuxARM64/bin:$PATH
ENV QMK_HOME=/src/qmk_firmware
ENV QMK_USERSPACE=/src/qmk
