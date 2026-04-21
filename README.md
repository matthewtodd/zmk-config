# ⌨️ ZMK Config

I've been using this [Ferris Sweep][ferris-sweep] keyboard since Summer 2024. I love it!

This is really my first foray into weird keyboards, and it was a little hard to
get oriented at first, so here are some links in case you're curious yourself.

- The board and case are from [Boardsource][boardsource].
- The switches are [Ambients nocturnals][ambients].
- The keycaps are [Chicago Stenographer][cs] (via [this fork][cs-fork]),
  3D-printed at [jlc3dp][jlc3dp].

![keyboard][keyboard]

## Mostly Miryoku

This layout is mostly [Miryoku][miryoku], which I started off
[tweaking][tweaking] in place, then moved here.

I've switched from [Colemak-DH][colemak-dh] to [Focal][focal], which I found in
[Pascal Getreuer's guide][which-alt], and I'm liking it so far.

I've also added some horizontal combos inspired by [urob's
zmk-config][urob-zmk-config]. These give me left-handed copy-paste while I'm
mousing, and, as a vim user, escape on the home row. They also make all the
bracket pairs much easier to remember!

![keymap][keymap]

## Local Builds

While I'm forever grateful for ZMK's out-of-the-box support for Github Actions,
I've moved to an entirely local workflow, with this [shell script][build] using
Docker images for [building the firmware][dockerfile-zmk] and [drawing the
keymap][dockerfile-keymap-drawer]. The hope is that this will make for a much
faster feedback loop when I get into a tinkering frenzy &mdash; I can now have
new firmware in 15 seconds!

[ferris-sweep]: https://github.com/davidphilipbarr/Sweep
[boardsource]: https://boardsource.xyz/products/crab-broom-choc-ferris-sweep
[ambients]: https://lowprokb.ca/products/ambients-silent-choc-switches?variant=44873446391972/
[cs]: https://github.com/pseudoku/PseudoMakeMeKeyCapProfiles
[cs-fork]: https://github.com/infused-kim/kb_keycaps_chicago_stenographer
[jlc3dp]: https://jlc3dp.com/
[keyboard]: images/keyboard.jpeg
[miryoku]: https://github.com/manna-harbour/miryoku
[tweaking]: https://github.com/manna-harbour/miryoku_zmk/compare/master...matthewtodd:miryoku_zmk:matthewtodd
[colemak-dh]: https://colemakmods.github.io/mod-dh/
[focal]: https://github.com/Keyhabit/Focal-keyboard-layout/
[which-alt]: https://getreuer.info/posts/keyboards/alt-layouts/index.html#which-alt-keyboard-layout-should-i-learn
[urob-zmk-config]: https://github.com/urob/zmk-config
[keymap]: images/cradio.svg
[dockerfile-zmk]: docker/west-build.dockerfile
[dockerfile-keymap-drawer]: docker/keymap.dockerfile
[build]: build
