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

## Things I might try someday

- Exploring non-momentary layer switching, since my thumbs get a little
  fatigued holding layer switches down.

## Things I've tried

Many of these are experimental layers for alternative layouts, largely inspired
by [Pascal Getreuer's guide][which-alt]. I continue to play with these in the
background, curious to see if I'll find something I like better enough than
Colemak-DH to take the muscle memory hit.

- Adding a [Sturdy][sturdy] layer. I gave this an honest run, using it for work
  for almost a week in January 2025, and while it did feel nice, it wasn't
  enough better than Colemak-DH for me to suffer the muscle memory hit. I was
  curious about Magic Sturdy, so maybe that's a project for a future day.
- Adding a [Canary][canary] layer. I played with it for a little while but 
  decided to concentrate on Sturdy instead. [Vylet][vylet] as a next step did
  look interesting!
- Adding a [Focal][focal] layer. I may have given up too soon (it has nice
  looking metrics!), but I had a lot of trouble with P on the inner index
  column, bottom row. Maybe this teaches me I want to deprioritize the inner
  index column in favor of heavier ring finger usage?
- Adding a [Gallium][gallium] layer. I didn't like the pinky to inner index
  lateral stretch for NG much. I've preemptively ruled out [Graphite][graphite]
  for having the same feature. So I think this means I want low LSBs, which is
  funny, because both of those layouts do have low metrics there. Maybe it's
  just the NG that gets me.
- Adding a Qwerty layer so friends could test-drive the keyboard more easily. I
  tried to gather interest over Christmas, and I think this is just going to be
  my own personal hobby, lol.

## What the layers look like

![keymap][keymap]

Thanks to [caksoylar/keymap-drawer][keymap-drawer].

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
[graphite]: https://github.com/rdavison/graphite-layout
[focal]: https://github.com/Keyhabit/Focal-keyboard-layout/
[vylet]: https://github.com/MightyAcas/vylet
[which-alt]: https://getreuer.info/posts/keyboards/alt-layouts/index.html#which-alt-keyboard-layout-should-i-learn
[keymap]: docs/cradio.svg
[keymap-drawer]: https://github.com/caksoylar/keymap-drawer
