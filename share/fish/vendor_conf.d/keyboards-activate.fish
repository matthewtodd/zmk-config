set -g __keyboards__ (realpath (status dirname)/../../..)

function __keyboards_activate__ --on-variable PWD
  if test $PWD = $__keyboards__
    fish_add_path -g $__keyboards__/bin
  else if set -l index (contains -i -- $__keyboards__/bin $fish_user_paths)
    set -e fish_user_paths[$index]
  end
end

__keyboards_activate__
