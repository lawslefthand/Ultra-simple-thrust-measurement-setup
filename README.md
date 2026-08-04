# Thrust Measurement Scale

A compact thrust measurement system based on the **HX711 24-bit ADC** and a **20 kg load cell**, designed for accurate thrust and force measurements using an Arduino. Suitable for motor testing, laboratory experiments, and educational applications.

## Features

- High-resolution force measurement using the HX711 ADC
- Support for 20 kg load cells
- Real-time serial output
- Tare (zero) functionality
- Simple hardware integration

## Hardware Requirements

- Arduino
- HX711 Load Cell Amplifier
- 20 kg Load Cell
- USB Cable
- Rigid mounting fixture

## Usage

1. Assemble the hardware according to the provided schematic.
2. Upload the Arduino sketch.
3. Open the Serial Monitor or PuTTY at **9600 baud**.
4. Allow the system to complete its initial calibration.
5. Press **`T`** to tare the load cell.
6. Apply thrust to begin taking measurements. :contentReference[oaicite:0]{index=0}

## Notes

- Do not exceed the rated 20 kg capacity of the load cell.
- Ensure the load cell is securely mounted before testing.
- Minimize vibration for improved measurement stability. :contentReference[oaicite:1]{index=1}

## Acknowledgements

Special thanks to **LastMinute Engineers** for providing the HX711 schematics and the foundational code that served as the basis for this project.
