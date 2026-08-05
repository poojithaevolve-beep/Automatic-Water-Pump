# Automatic Water Pump Using Ultrasonic Sensor

An Arduino-based automatic water pump controller that uses an **HC-SR04 Ultrasonic Sensor** to monitor the water level in a tank and control a water pump through a relay module.

## Features

- Automatically starts the pump when the water level is low.
- Automatically stops the pump when the tank is full.
- Uses hysteresis to prevent rapid ON/OFF switching.
- Displays water level information on the Serial Monitor.
- Compatible with Arduino Uno, Nano, and similar boards.

---

## Components Required

| Component | Quantity |
|-----------|----------|
| Arduino Uno/Nano | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| 5V Relay Module (Active LOW) | 1 |
| Water Pump | 1 |
| Power Supply | 1 |
| Jumper Wires | As required |

---

## Pin Connections

| Arduino Pin | Component |
|-------------|-----------|
| D9 | HC-SR04 Trigger |
| D10 | HC-SR04 Echo |
| D8 | Relay IN |
| 5V | Sensor & Relay VCC |
| GND | Sensor & Relay GND |

---

## Working Principle

1. The ultrasonic sensor measures the distance between the sensor and the water surface.
2. A larger distance means the water level is low.
3. A smaller distance means the tank is filling up.
4. When the measured distance becomes greater than or equal to the **LOW_LEVEL**, the pump turns ON.
5. When the measured distance becomes less than or equal to the **FULL_LEVEL**, the pump turns OFF.

This difference between ON and OFF thresholds provides **hysteresis**, preventing relay chattering.

---

## Threshold Configuration

Modify these values according to your tank dimensions.

```cpp
const float FULL_LEVEL = 5.0;   // Pump OFF
const float LOW_LEVEL  = 7.0;   // Pump ON
```

Example:

- Distance ≤ **5 cm** → Tank Full → Pump OFF
- Distance ≥ **7 cm** → Tank Low → Pump ON

---

## Serial Monitor Output

Example:

```
Distance: 8.2 cm
Pump ON

Distance: 6.4 cm

Distance: 4.9 cm
Pump OFF
```

---

## Relay Logic

This project assumes an **Active LOW Relay Module**.

| Relay Pin | Pump State |
|------------|------------|
| LOW | ON |
| HIGH | OFF |

If your relay is **Active HIGH**, replace:

```cpp
digitalWrite(relayPin, LOW);
```

with

```cpp
digitalWrite(relayPin, HIGH);
```

and replace:

```cpp
digitalWrite(relayPin, HIGH);
```

with

```cpp
digitalWrite(relayPin, LOW);
```

---

## Upload Instructions

1. Connect all components as shown above.
2. Open the Arduino IDE.
3. Select the correct Arduino board and COM port.
4. Copy the provided code into a new sketch.
5. Upload the sketch.
6. Open the Serial Monitor at **9600 baud**.
7. Test the system by changing the water level in the tank.

---

## Project Structure

```
Automatic-Water-Pump/
│
├── Automatic_Water_Pump.ino
├── README.md
└── images/
    └── circuit_diagram.png
```

---

## Future Improvements

- OLED/LCD display for water level.
- Wi-Fi monitoring using ESP8266/ESP32.
- Mobile notifications when the tank is full.
- Dry-run protection for the pump.
- Manual ON/OFF override switch.
- Buzzer or LED status indicators.

---

## Notes

- Mount the ultrasonic sensor securely at the top of the tank.
- Ensure there are no obstacles between the sensor and the water surface.
- Calibrate the `FULL_LEVEL` and `LOW_LEVEL` values for your specific tank.
- Use an appropriately rated relay and power supply for the pump.

---
