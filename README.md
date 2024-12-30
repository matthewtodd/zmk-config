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
- Added a Qwerty layer so friends can test-drive the keyboard more easily.

## Things I might try someday

- Exploring non-momentary layer switching, since my thumbs get a little
  fatigued holding layer switches down.

## Things I've tried

- After reading [Pascal Getreuer's guide][which-alt], I added experimental
  layers for the [Sturdy][sturdy], [Canary][canary], [Gallium][gallium], and
  [Focal][focal] layouts, curious to see if I might like one better enough to
  switch away from Colemak-DH. So far, no, but I may return someday.

## What the layers look like

Thanks to [caksoylar/keymap-drawer][keymap-drawer].

![keymap][keymap]

[ferris-sweep]: https://github.com/davidphilipbarr/Sweep
[keyboard]: docs/keyboard.jpeg
[tweaked]: https://github.com/manna-harbour/miryoku_zmk/compare/master...matthewtodd:miryoku_zmk:matthewtodd
[miryoku]: https://github.com/manna-harbour/miryoku
[miryoku-mouse-layer]: https://github.com/manna-harbour/miryoku/tree/master/docs/reference#mouse
[miryoku-button-layer]: https://github.com/manna-harbour/miryoku/tree/master/docs/reference#button
[miryoku-additional-features]: https://github.com/manna-harbour/miryoku/tree/master/docs/reference#additional-features
[sturdy]: https://oxey.dev/sturdy
[canary]: https://github.com/Apsu/Canary
[gallium]: https://github.com/GalileoBlues/Gallium
[focal]: https://github.com/Keyhabit/Focal-keyboard-layout/
[which-alt]: https://getreuer.info/posts/keyboards/alt-layouts/index.html#which-alt-keyboard-layout-should-i-learn
[keymap-drawer]: https://github.com/caksoylar/keymap-drawer
[keymap]: docs/cradio.svg
