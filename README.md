# ⌨️ ZMK Config

I've been using this [Ferris Sweep][ferris-sweep] keyboard daily since Summer
2024. I didn't intend to fall down the keyboard rabbit hole, but it's been a
surprisingly delightful experience!

![keyboard][keyboard]

This repository holds its firmware configuration.

I didn't start here, though; I first [tweaked][tweaked] the thoughtful
[Miryoku][miryoku] layout and used that quite happily for some time. Now that I
understand it all a little better, I'm dropping down to this level so that I
can tinker a little more freely.

## Changes from Miryoku

- Removed the [button layer][miryoku-button-layer], since I wasn't really using
  it.
- Removed [additional features][miryoku-additional-features] (boot, base, tap,
  extra, opposite, current).
- Removed keys I didn't use (insert, RGB, power & output toggles, scroll lock).
- Added a layer for the [Sturdy][sturdy] keyboard layout! Colemak-DH is a very
  sensible default, but I'm curious what I might learn from other experimental
  layouts like this.
- Added a QWERTY layer so friends can test-drive the keyboard more easily.

## Things I might try someday

- Exploring non-momentary layer switching, since my thumbs get a little
  fatigued holding layer switches down.

## What the layers look like

![keymap][keymap]

[ferris-sweep]: https://github.com/davidphilipbarr/Sweep
[keyboard]: docs/keyboard.jpeg
[tweaked]: https://github.com/manna-harbour/miryoku_zmk/compare/master...matthewtodd:miryoku_zmk:matthewtodd
[miryoku]: https://github.com/manna-harbour/miryoku
[miryoku-mouse-layer]: https://github.com/manna-harbour/miryoku/tree/master/docs/reference#mouse
[miryoku-button-layer]: https://github.com/manna-harbour/miryoku/tree/master/docs/reference#button
[miryoku-additional-features]: https://github.com/manna-harbour/miryoku/tree/master/docs/reference#additional-features
[sturdy]: https://oxey.dev/sturdy
[keymap]: docs/cradio.svg
