FROM python:3

WORKDIR /workspaces

RUN pip install keymap-drawer west

# Use west so keymap-drawer can see any module code the keymap might depend on.
# Filter out zmk and zephyr because those are huge and irrelevant for drawing.
RUN --mount=type=bind,src=config/west.yml,dst=config/west.yml <<-END
  west init -l /workspaces/config
  west config --local manifest.project-filter " -zmk,-zephyr"
  west update --fetch-opt=--filter=tree:0
END

SHELL ["/bin/sh", "-c"]
CMD \
  keymap -c ${CONFIG} parse -z ${KEYMAP} | \
  keymap -c ${CONFIG} draw -o ${OUTPUT} -
