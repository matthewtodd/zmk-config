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

COPY --chmod=755 <<-"END" entrypoint
  while getopts "k:" opt; do
    case ${opt} in
      k)
        input=config/${OPTARG}.keymap
        output=images/${OPTARG}.svg
        ;;
    esac
  done

  keymap -c config/keymap-drawer.yml parse -z ${input} | \
  keymap -c config/keymap-drawer.yml draw -o ${output} -
END

ENTRYPOINT ["/bin/bash", "/workspaces/entrypoint"]
