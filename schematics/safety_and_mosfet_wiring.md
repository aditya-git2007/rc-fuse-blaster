# RC Fuse Blaster — Safety Interlocks & MOSFET Firing Circuit

## ⚡ Safety & Power Isolation Guidelines
* **Isolated Firing Power:** Never power the igniter nichrome wire or electric match from the microcontroller's internal battery bus. Use a dedicated high-drain battery pack connected to the MOSFET drain terminal.
* **Gate Resistor & Pulldown:** Always include a 10kΩ pulldown resistor on the MOSFET gate pin (`GPIO 5`) to ensure the firing pin is held strictly LOW during microcontroller boot-up, preventing accidental ignition.
* **Continuity Check:** The continuity verification circuit uses a safe, low-current micro-amp test current that flows through the igniter bridge wire without generating enough heat to trigger it prematurely.
