# ⌨️ Keyboards

I've been using this [Ferris Sweep][ferris-sweep] keyboard since Summer 2024,
in both wired and wireless flavors. I love it!

![keyboard][keyboard]

## Local Builds

To build the firmware and draw the keymap, there's a small [shell
script][build] that uses a [Docker image][dockerfile].

<!-- {{{markin
build -h 2>/dev/null | sed -e "s/^/    /"
}}}-->
    usage: build [-I] firmware [-k <keyboard>]
           build [-I] keymap [-k <keyboard>]
           build [-I] shell
    
      global options:
        -I             build docker image
    
      commands:
        firmware       build keyboard firmware (default)
        keymap         draw keyboard keymap
        shell          start an interactive shell in the docker container
    
      options:
        -k <keyboard>  select keyboard
    
      keyboards:
        ferris_sweep (default)
        ferris_sweep_wired
        corne_min
    
<!-- {{{end}}} -->

## Keymap

This layout is mostly [Miryoku][miryoku], which I started off
[tweaking][tweaking] in place, then moved here.

I've switched from [Colemak-DH][colemak-dh] to [Focal][focal], which I found in
[Pascal Getreuer's guide][which-alt], and I'm liking it so far.

I've also added some horizontal combos inspired by [urob's
zmk-config][urob-zmk-config]. These give me left-handed copy-paste while I'm
mousing, and, as a vim user, escape on the home row. They also make all the
bracket pairs much easier to remember!

![keymap][keymap]

# Links

This is really my first foray into weird keyboards, and it was a little hard to
get oriented at first, so here are some links in case you're curious yourself.

- The board and case are from [Boardsource][boardsource].
- The switches are [Ambients nocturnals][ambients].
- The keycaps are [Chicago Stenographer][cs] (via [this fork][cs-fork]),
  3D-printed at [jlc3dp][jlc3dp].
- This [travel case][case] works really well.

# Future

After seeing the [mikefive][mikefive] and [mikecinq][mikecinq], I've been
curious about those super-low profile switches. I've preordered a [Corne Min
prototype][corne_min_prototype] from Mechboards and can't wait for it to get
here!

# Directory Layout

I've gone a little nuts here, far afield from the typical `zmk-config` or
`qmk_userspace` repository. Part of this is for fun, and part is because I'm
thinking about starting to make keyboards someday, and it's fun to think about
all the ergogen or kicad or whatever files just slotting in here neatly, along
with their attendant tooling living in the docker image.

But it's not too weird. If you squint, things should look a little familiar
here:

<!-- {{{markin
tree -I var | sed -e "s/^/    /"
}}}-->
    .
    ├── bin
    │   ├── build
    │   └── markin
    ├── etc
    │   └── keymap-drawer.yml
    ├── opt
    │   ├── Dockerfile
    │   ├── packages.txt
    │   └── requirements.txt
    ├── README.md
    ├── share
    │   ├── doc
    │   │   ├── corne_min.svg
    │   │   ├── ferris_sweep_wired.svg
    │   │   ├── ferris_sweep.svg
    │   │   └── keyboard.jpg
    │   ├── fish
    │   │   ├── vendor_completions.d
    │   │   │   └── build.fish
    │   │   └── vendor_conf.d
    │   │       └── keyboards-activate.fish
    │   └── git
    │       └── hooks
    │           └── pre-commit
    └── src
        ├── qmk
        │   ├── keyboards
        │   │   └── ferris
        │   │       └── sweep
        │   │           └── keymaps
        │   │               └── matthewtodd
        │   │                   ├── config.h
        │   │                   ├── keymap.c
        │   │                   └── rules.mk
        │   └── qmk.json
        └── zmk
            └── config
                ├── common.dtsi
                ├── corne_min.conf
                ├── corne_min.keymap
                ├── cradio.conf
                ├── cradio.keymap
                └── west.yml
    
    20 directories, 24 files
<!-- {{{end}}} -->

[ambients]: https://lowprokb.ca/products/ambients-silent-choc-switches?variant=44873446391972/
[boardsource]: https://boardsource.xyz/products/crab-broom-choc-ferris-sweep
[build]: bin/build
[case]: https://lowprokb.ca/collections/parts/products/travel-case-for-small-keyboards
[colemak-dh]: https://colemakmods.github.io/mod-dh/
[corne_min_prototype]: https://mechboards.co.uk/products/corne-min
[cs-fork]: https://github.com/infused-kim/kb_keycaps_chicago_stenographer
[cs]: https://github.com/pseudoku/PseudoMakeMeKeyCapProfiles
[dockerfile]: opt/Dockerfile
[ferris-sweep]: https://github.com/davidphilipbarr/Sweep
[focal]: https://github.com/Keyhabit/Focal-keyboard-layout/
[jlc3dp]: https://jlc3dp.com/
[keyboard]: share/doc/keyboard.jpg
[keymap]: share/doc/ferris_sweep.svg
[mikecinq]: https://kbd.news/Mikecinq-2686.html
[mikefive]: https://kbd.news/Mikefive-a-Kailh-PG1316S-keyboard-2366.html
[miryoku]: https://github.com/manna-harbour/miryoku
[tweaking]: https://github.com/manna-harbour/miryoku_zmk/compare/master...matthewtodd:miryoku_zmk:matthewtodd
[urob-zmk-config]: https://github.com/urob/zmk-config
[which-alt]: https://getreuer.info/posts/keyboards/alt-layouts/index.html#which-alt-keyboard-layout-should-i-learn
