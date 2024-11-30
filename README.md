# ⌨️ ZMK Config

I've been using a [wireless][nice-nano] [Ferris Sweep][ferris-sweep] from
[Boardsource][boardsource] with [Nocturnal][nocturnal] keyswitches and [MBK
Legend‡][mbk-legend] keycaps since Summer 2024. (I didn't mean to fall down
this rabbit hole, but what a delightful trip it's been!)

This repository holds its firmware configuration.

I didn't start here, though; I first [tweaked][tweaked] the thoughtful
[Miryoku][miryoku] layout and used that quite happily for some time. Now that I
understand it all a little better, I'm dropping down to this level so that I
can tinker a little more freely.

## Changes from Miryoku

- Removed the mouse layer, for now. I'm watching zmkfirmware/zmk#2477, which
  seems like it's close!
- Removed the button layer, since I wasn't really using it.
- Removed additional features (boot, base, tap, extra, opposite, current).
- Removed keys I didn't use (insert, RGB, power & output toggles, scroll lock).
- Added a [Sturdy][sturdy] layer so I can play around with it! I may add other
  experimental layouts like this from time to time.

## Things I might try someday

- Add a QWERTY layer so I can let friends test-drive the keyboard more easily.
- Explore non-momentary layer switching, since my thumbs get a little fatigued
  holding layer switches down.

## What the layers look like

![keymap][keymap]

[nice-nano]: https://nicekeyboards.com/nice-nano
[ferris-sweep]: https://github.com/davidphilipbarr/Sweep
[boardsource]: https://www.boardsource.xyz/products/crab-broom
[nocturnal]: https://lowprokb.ca/collections/switches/products/ambients-silent-choc-switches?variant=44873446391972
[mbk-legend]: https://fkcaps.com/keycaps/mbk/legend-40s
[tweaked]: https://github.com/manna-harbour/miryoku_zmk/compare/master...matthewtodd:miryoku_zmk:matthewtodd
[miryoku]: https://github.com/manna-harbour/miryoku
[sturdy]: https://oxey.dev/sturdy
[keymap]: docs/cradio.svg
