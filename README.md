# RFID-Based Motor Ignition System

## 📌 Project Overview

This project is an RFID-based motor ignition and access-control system developed using a Raspberry Pi Pico, RC522 RFID reader, and L298N motor driver.

The system uses RFID authentication to control a DC motor. When an RFID card or tag is scanned, its unique identification number (UID) is read and compared with a predefined authorized UID. The motor is activated only when the authorized RFID tag is detected.

## ✨ Features

- RFID-based authentication
- UID-based access control
- RC522 RFID reader
- Raspberry Pi Pico microcontroller
- L298N motor driver
- DC motor control
- LED status indication
- Buzzer feedback
- Unauthorized tag rejection
- SPI communication

## 🛠️ Components Used

- Raspberry Pi Pico
- RC522 RFID Module
- RFID Card/Tag
- L298N Motor Driver
- DC Motor
- LED
- Buzzer
- External Power Adapter
- Jumper Wires

## 💻 Software & Technologies

- Arduino IDE
- C/C++
- MFRC522 Library
- SPI Communication

## ⚙️ Working Principle

The RC522 RFID reader scans for nearby RFID cards or tags and reads the UID of the detected tag.

The Raspberry Pi Pico compares the detected UID with the predefined authorized UID.

### Authorized RFID Tag

```text
RFID Tag Detected
        ↓
UID Matches
        ↓
Access Granted
        ↓
LED/Buzzer Indication
        ↓
L298N Activated
        ↓
DC Motor Runs
