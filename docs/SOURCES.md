# Sources

Awesome lists and payload repos linked from [AWESOME.md](../AWESOME.md).
This repo does **not** vendor Duckyscript. Ideas are adapted into `catalog.json`
ops and regenerated as LilyPad Arduino sketches.

## Filter

Taken:

- `prank` / `general` / fun demo / own-machine utility
- mouse jiggle, ASCII art, banners, open own URLs, volume nudge

Skipped:

- credential theft, clipboard dump, Wi-Fi dump, browser dump
- reverse shells, persistence, exfil, remote access
- anything aimed at someone else's machine

## Upstream collections

| Upstream | Used as |
|----------|---------|
| [hak5/usbrubberducky-payloads](https://github.com/hak5/usbrubberducky-payloads) (`payloads/library/prank`, `general`) | Most demo inspiration |
| [FalsePhilosopher/badusb](https://github.com/FalsePhilosopher/badusb) (`general`) | GitHub open / utility tone |
| [djsime1/awesome-flipperzero](https://github.com/djsime1/awesome-flipperzero) | Mouse jiggler / pomodoro ideas |
| [savagedamage/awesome-hid-security](https://github.com/savagedamage/awesome-hid-security) | Map of HID ecosystem (link only) |

## Adapted into this catalog

| id | source note |
|----|-------------|
| matrix-wake-up | Hak5 The_Matrix-Wake_Up / Digital_Rain |
| rickroll-ascii | Hak5 RickRoll_ASCII / TerminalRickRoll |
| hacker-typer | Hak5 Hacker_Typer |
| mouse-jiggler | Flipper jiggler / Hak5 The_Mouse_Moves_By_Itself / FP jiggler |
| caps-troll | Hak5 cApS-Troll |
| alien-message | Hak5 Alien Message From Computer |
| banner-joke | Hak5 Full-ScreenBannerJoke |
| terminal-spam | Hak5 Continuos Print In Terminal / Windows-Spam-Terminals |
| star-lilypad-repo | FalsePhilosopher general/GitHub-Star.txt |
| quack-roll | Hak5 Quack_Rolled / YouHaveBeenQuacked2.0 |
| usb-scream | Hak5 USBScream |
| mr-robot-exit | Hak5 mr-robot_eXit |
| catch-me | Hak5 Try_To_Catch_Me |
| piano-ascii | Hak5 Piano_Player |
| volume-nudge | Hak5 MaxVolumeRickroll_Windows / SoundChangeDuck |
| pomodoro-ping | Flipper Flipp Pomodoro (via awesome-flipperzero) |
| yt-tripwire-lite | Hak5 / Jakoby YT-Tripwire (open YouTube only) |

Original rows in `catalog.json` (no `source` field) are this repo's own Omarchy sketches.

## Count

- Original fun set: 20
- Adapted from awesome/Hak5/FP/Flipper: **17**
- Catalog total: **37** (+ hand sketch `demo-hello`)
