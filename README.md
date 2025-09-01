!(/Deck32 graphic.jpg)
# Deck32
![License](https://img.shields.io/badge/License-CC--BY--NC_4.0-lightgrey.svg)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)

An open-source, customizable ESP32-based macropad for controlling apps, shortcuts, and more. Non-commercial use only.
## Features (BY DEFAULT)
- Programmable buttons and rotary encoders you can make however you want
- Easy to extend with new functions
- Super easy to bind in software like OBS Studio
- Bluetooth communication
- Battery indicator
- Non-commercial license (CC-BY-NC)

## Requirements (MY VERSION)
- An ESP32 board (Almost any board works)
- Arduino IDE
- A case you can 3D print if you want to
- Some wires/jump wires if you don't want to solder
- Some buttons, rotary encoders - any type should work - I used mechanical buttons + rotary encoders
- An ESP32 extension board for easy connecting
- Some resistors

## How does it work? (MY VERSION)
- I made the buttons (and one encoder) act as Shift+Ctrl+Alt+F1-F12 keys so they are easily detectable and they are not interrupting any shortcuts. When u have a mechanical switch like me, it works the same as touching two wires: one to GND and one to a GPIO. If they touch the esp sends a key to your computer.
- The encoders should work the same and usually there are S1, S2 and KEY pins that work like: clockwise rotation, counter-clockwise rotation, key press.
- The battery indicator is 2 wires taken from the battery and using 2 resistors (10k) connected and then plugged into the GPIO35 that detects voltage and counts the precentage.
- Everything is working on Bluetooth. Not possible using usb, unless you customize it and use a usb HID compatible esp board.

## Customizing & building
### How to build your custom deck32?
- First you have to choose what hardware you would like to use - that means how many buttons, button type, what encoders etc.
- Then you have to adjust the code to your hardware (If you don't want to do this part you can tip me and I will make it for you), it takes some coding understanding. 
   -- this part requires you to know which gpios are used in the code and which ones are they on your esp32 (it may vary)
- Soldering, wiring (depending on your build)
- Making a case, 3D modelling, printing etc.
- And final step assembling your new macropad!

## If you want me to customize the code to your needs, or make a purchase list or make schemes. Write to me by email - deck32@maksotm.pl - We will discuss about pricing. I accept crypto, any other ways of payment to discuss.

## Creators/Owners build
I'll add this soon..

## Contributing
- Feel free to suggest fixes or improvements via Issues or Pull Requests.
- Credit must always remain intact (see LICENSE file).



## License

This project is licensed under the Creative Commons Attribution-NonCommercial 4.0 International License. See the [LICENSE](LICENSE) file for more details.
