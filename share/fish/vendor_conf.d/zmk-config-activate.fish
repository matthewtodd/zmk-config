set -g __zmk_config__ (realpath (status dirname)/../../..)

function __build_activate__ --on-variable PWD
  if test (pwd) = $__zmk_config__
    fish_add_path -gv $__zmk_config__/bin
  else
    if set -l index (contains -i -- $__zmk_config__/bin $fish_user_paths)
      set -e fish_user_paths[$index]
      echo set -g fish_user_paths $fish_user_paths
    end
  end
end

__build_activate__
