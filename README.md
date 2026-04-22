# ⌨️ ZMK Config

I've been using this [Ferris Sweep][ferris-sweep] keyboard since Summer 2024. I
love it!

![keyboard][keyboard]

## Local Builds

To build the firmware and draw the keymap, there's a small [shell
script][build] that uses a [Docker image][dockerfile]. In addition to the speed
of the local build, I like how they codify the process and keep my filesystem
clean of dependencies.

```sh
./build -i  # Build the Docker image (prerequisite)
./build     # Build the firmware
./build -d  # Draw an SVG of the keymap
```

## Keymap: Mostly Miryoku

This layout is mostly [Miryoku][miryoku], which I started off
[tweaking][tweaking] in place, then moved here.

I've switched from [Colemak-DH][colemak-dh] to [Focal][focal], which I found in
[Pascal Getreuer's guide][which-alt], and I'm liking it so far.

I've also added some horizontal combos inspired by [urob's
zmk-config][urob-zmk-config]. These give me left-handed copy-paste while I'm
mousing, and, as a vim user, escape on the home row. They also make all the
bracket pairs much easier to remember!

One current challenge with Focal in vim is j on my right pinky. I have started
compensating by using arrow keys for all movement (gasp!), but that's wreaking
havoc on my left thumb. If I can't develop the discipline, I'm considering
trying [Gallium][gallium] out next.

![keymap][keymap]

# Parts

This is really my first foray into weird keyboards, and it was a little hard to
get oriented at first, so here are some links in case you're curious yourself.

- The board and case are from [Boardsource][boardsource].
- The switches are [Ambients nocturnals][ambients].
- The keycaps are [Chicago Stenographer][cs] (via [this fork][cs-fork]),
  3D-printed at [jlc3dp][jlc3dp].

[ambients]: https://lowprokb.ca/products/ambients-silent-choc-switches?variant=44873446391972/
[boardsource]: https://boardsource.xyz/products/crab-broom-choc-ferris-sweep
[build]: build
[colemak-dh]: https://colemakmods.github.io/mod-dh/
[cs-fork]: https://github.com/infused-kim/kb_keycaps_chicago_stenographer
[cs]: https://github.com/pseudoku/PseudoMakeMeKeyCapProfiles
[dockerfile]: Dockerfile
[ferris-sweep]: https://github.com/davidphilipbarr/Sweep
[focal]: https://github.com/Keyhabit/Focal-keyboard-layout/
[gallium]: https://github.com/GalileoBlues/Gallium
[jlc3dp]: https://jlc3dp.com/
[keyboard]: img/keyboard.jpg
[keymap]: img/cradio.svg
[miryoku]: https://github.com/manna-harbour/miryoku
[tweaking]: https://github.com/manna-harbour/miryoku_zmk/compare/master...matthewtodd:miryoku_zmk:matthewtodd
[urob-zmk-config]: https://github.com/urob/zmk-config
[which-alt]: https://getreuer.info/posts/keyboards/alt-layouts/index.html#which-alt-keyboard-layout-should-i-learn
