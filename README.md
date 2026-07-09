# OpenMic
OpenMic is an open-source, 2-in, 2-out, usb-c audio interface.


## About

### Why open source?
Open source audio/music hardware is not scarce, but general-purpose open source audio interfaces for musicians are essentially non-existent. OpenMic brings repairability, transparency, and education to an overlooked corner of music hardware.

You own your hardware. All schematics, firmware, and design files are publicly accessible so you can repair it, modify it, and understand it.

### What is OpenMic?
If you aren't familiar with audio interfaces like the [Focusrite Scarlett 2i2](https://us.focusrite.com/products/scarlett-2i2) or the [Universal Audio Apollo Twin](https://www.uaudio.com/products/apollo-twin-x), they basically take analog audio - from a microphone, a guitar, a synth, etc. - and convert it into digital audio your computer can use in a DAW like Ableton, Logic, or Audacity. They also convert digital audio from your computer back into analog audio that you can hear through speakers or headphones. Interfaces also typically provide some sort of amplification or volume control on the inputs and outputs.

This is exactly what OpenMic does. Two inputs that can take microphone/line/instrument level signals, outputs for your speakers, and a headphone jack. Plus a few other features like phantom power that are listed in more detail in the [Features](#features) section.

![Block diagram](docs/images/block%20diagram.jpg)
*System block diagram*

## Current Status
OpenMic is currently in the prototyping stage. The circuit has been designed and [simulated](hardware/sims/), and individual systems are being built and tested. View the [schematics](docs/schematics/openmic.pdf) to see the current circuit design.

Progress will be posted on the [OpenMic blog](https://olpad.codeberg.page/openmic-blog) as prototyping continues.

### Roadmap
- [x] Initial design and component selection
- [x] Simulation for design verification
- [ ] Subsystem prototyping
- [ ] Full board design in KiCad
- [ ] First full v1 board
- [ ] Crowd supply launch
- [ ] Production

## Features
- 2 combo XLR/TRS inputs (mic/line/inst)
- Balanced TRS stereo line outputs
- TRS headphone output
- 48V phantom power
- Direct monitoring
- Up to 32-bit/96kHz
- USB-C bus powered (1.5A) with external USB-C fallback
- Drives headphones from 32Ω to 600Ω
- Fully open hardware and firmware

## Getting Started
If you want to view/edit KiCAD files, make sure to add the part libraries located in /hardware/libs to your project or globally in your KiCAD instance.

---

### Sponsors

<img src="docs/images/aisler.svg" alt="AISLER" width="150">&emsp;&emsp;<img src="docs/images/digilent.png" alt="AISLER" width="150">
