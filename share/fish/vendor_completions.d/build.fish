set -l commands firmware keymap shell
set -l keyboards ferris_sweep ferris_sweep_wired corne_min

complete -c build -f
complete -c build -n "not __fish_seen_subcommand_from $commands" -s I -d "Build docker image"
complete -c build -n "not __fish_seen_subcommand_from $commands" -a "firmware" -d "Build keyboard firmware"
complete -c build -n "not __fish_seen_subcommand_from $commands" -a "keymap" -d "Draw keyboard keymap"
complete -c build -n "not __fish_seen_subcommand_from $commands" -a "shell" -d "Start an interactive shell in the docker container"
complete -c build -n "__fish_seen_subcommand_from firmware keymap" -n "not __fish_seen_argument -s k" -s k -x -a "$keyboards" -d "Select keyboard"
