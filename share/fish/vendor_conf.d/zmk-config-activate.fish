set -g __zmk_config__ (realpath (status dirname)/../../..)

function __zmk_config_activate__ --on-variable PWD
  if test (pwd) = $__zmk_config__
    fish_add_path -g $__zmk_config__/bin
  else
    if set -l index (contains -i -- $__zmk_config__/bin $fish_user_paths)
      set -e fish_user_paths[$index]
    end
  end
end

__zmk_config_activate__
