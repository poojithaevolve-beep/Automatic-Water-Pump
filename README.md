# Automatic Water Pump

## Overview

This project is an **Arduino-based Automatic Water Pump System** that uses an **ultrasonic sensor** to monitor the water level in a tank and a **relay module** to automatically control a water pump.

The ultrasonic sensor measures the distance between the sensor and the water surface. When the water level becomes low, the Arduino turns the pump **ON** through the relay. When the tank becomes full, the Arduino turns the pump **OFF** automatically.

---

## Features

- Automatically monitors the water level in the tank.
- Uses an ultrasonic sensor for non-contact water-level measurement.
- Automatically turns the water pump **ON** when the water level is low.
- Automatically turns the water pump **OFF** when the tank is full.
- Uses a relay module to control the pump.
- Displays the measured distance in the Serial Monitor.
- Uses different ON and OFF levels to avoid unnecessary pump switching.
- Simple and low-cost Arduino-based system.

---

## Components Required

| Component | Quantity |
|---|---:|
| Arduino Uno/Nano | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| 1-Channel Relay Module | 1 |
| Water Pump | 1 |
| Water Tank | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |
| Power Supply | As required |

---

## Pin Connections

### Ultrasonic Sensor (HC-SR04)

| HC-SR04 Pin | Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D9 |
| ECHO | D10 |

### Relay Module

| Relay Pin | Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| IN | D8 |

### Water Pump

The water pump is connected through the relay module.

| Relay Terminal | Connection |
|---|---|
| COM | Pump power supply |
| NO | Pump |
| NC | Not used |

The relay is configured as **Active LOW**:

- `LOW` → Pump ON
- `HIGH` → Pump OFF

> **Safety:** If the water pump uses mains AC voltage, do not make the AC-side connections while powered. Use a properly rated relay, proper insulation, enclosure, and suitable electrical protection.

---

## Libraries Used

This project does not require any external Arduino libraries.

The following standard Arduino functions are used:

- `pinMode()`
- `digitalWrite()`
- `pulseIn()`
- `delay()`
- `Serial`

These functions are available in the standard Arduino IDE.

---

## How It Works

1. The Arduino sends a trigger pulse to the ultrasonic sensor.
2. The ultrasonic sensor sends an ultrasonic wave toward the water surface.
3. The sensor receives the reflected wave.
4. The Arduino calculates the distance between the sensor and the water surface.
5. The measured distance is displayed on the Serial Monitor.
6. When the measured distance reaches or exceeds **7 cm**, the Arduino turns the pump **ON**.
7. The pump fills the tank with water.
8. When the measured distance becomes **5 cm or less**, the Arduino turns the pump **OFF**.
9. The system continuously repeats this process to maintain the water level automatically.

---

## Water Level Control

The project uses two different distance levels:

| Tank Condition | Distance | Pump |
|---|---:|---|
| Low Water Level | 7 cm or more | ON |
| Filling | Between 5–7 cm | Remains in current state |
| Full Tank | 5 cm or less | OFF |

Using two different levels helps prevent the relay from rapidly switching ON and OFF when the water level is close to the threshold.

---

## Default Configuration

| Parameter | Value |
|---|---|
| Ultrasonic TRIG Pin | D9 |
| Ultrasonic ECHO Pin | D10 |
| Relay Pin | D8 |
| Full Level | 5 cm |
| Low Level | 7 cm |
| Relay Type | Active LOW |
| Serial Monitor Baud Rate | 9600 |

---

## Serial Monitor Output

The Arduino displays the measured distance and pump status in the Serial Monitor.

Example:

```text
Distance: 8.20 cm
Pump ON

Distance: 6.50 cm

Distance: 5.00 cm
Pump OFF
