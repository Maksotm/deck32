# Deck32
An open-source, customizable ESP32-based macropad for controlling apps, shortcuts, and more. Non-commercial use only.
![License](https://img.shields.io/badge/License-CC--BY--NC_4.0-lightgrey.svg)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
## Features
- Programmable buttons and rotary encoders you can make however you want
- Easy to extend with new functions
- Super easy to bind in software like OBS Studio
- Bluetooth communication
- (Optional) Battery indicator
- Non-commercial license (CC-BY-NC)

## Requirements
- An ESP32 board (Almost any board works)
- Arduino IDE
- A case you can 3D print if you want to
- Some wires/jump wires if you don't want to solder
- Some buttons, rotary encoders - any type should work - I used mechanical buttons + rotary encoders
- Optionally an ESP32 extension board for easy connecting
- Optional: LEDs, buttons, and other hardware for custom build

## How does it work?
I made the buttons (and one encoder) act as Shift+Ctrl+Alt+F1-F12 keys so they are easily detectable and they are not interrupting any shortcuts.
When u have a mechanical switch like me, it works the same as touching two wires: one to GND and one to a GPIO. If they touch the esp sends a key to your computer.
The encoders should work the same and usually there are S1, S2 and KEY pins that work like: clockwise rotation, counter-clockwise rotation, key press.
The battery indicator is 2 wires taken from the battery and using 2 resistors connected and then plugged into the GPIO35 that detects voltage and counts the precentage.
Everything is working on Bluetooth. Not possible using usb, unless you customize it and use a usb HID compatible esp board.

## Customizing & building
I'll add this soon..

## Creators/Owners build
I'll add this soon..
## Contributing
- Feel free to suggest fixes or improvements via Issues or Pull Requests.
- Credit must always remain intact (see LICENSE file).



## License

This project is licensed under the Creative Commons Attribution-NonCommercial 4.0 International License. See the [LICENSE](LICENSE) file for more details.
