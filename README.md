# SeleneArduino

Arduino/PlatformIO firmware experiments for Selene's onboard hardware. The project targets an **Arduino Mega 2560** and contains helper classes for ballast pumps, ballast valves, a leveling sensor, thrusters and thruster servos.

## What is implemented?

The current [entry point](src/main.cpp) is a **leveling-sensor test**: it reads the sensor on `Serial3` at 9600 baud and prints distance in millimetres to `Serial` every 100 ms. It does not currently run an integrated ballast or propulsion controller.

- [include/](include/): hardware helper classes.
- [src/main.cpp](src/main.cpp): the program compiled into the firmware.
- [platformio.ini](platformio.ini): Mega 2560 configuration and Arduino Servo dependency.

## Build

With PlatformIO installed, run from this repository:

```sh
pio run -e megaatmega2560
```

Check the sensor wiring and serial ports against the intended board before uploading. The generic README files in `include/`, `lib/` and `test/` describe PlatformIO conventions, not the status of Selene's firmware.
