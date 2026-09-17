# 🔐 RFID-Based Motor Ignition System

An RFID-based motor ignition system developed using a **Raspberry Pi Pico**, **RC522 RFID reader**, and **L298N motor driver**. The system uses RFID authentication to control a DC motor, allowing the motor to operate only when an authorized RFID tag is detected.

## 📌 Project Overview

The project demonstrates a simple **RFID-based access and ignition control system**.

The RC522 RFID module reads the unique identification number (UID) of an RFID card or tag. The Raspberry Pi Pico compares the detected UID with a predefined authorized UID.

* ✅ Authorized tag → Motor starts
* ❌ Unauthorized tag → Motor remains OFF
* 💡 LED indicates system status
* 🔊 Buzzer provides feedback

The project demonstrates the integration of **RFID communication, microcontroller programming, authentication logic, and motor control**.

## 🛠️ Components Used

* Raspberry Pi Pico
* RC522 RFID Reader
* RFID Card/Tag
* L298N Motor Driver
* DC Motor
* LED
* Buzzer
* External Power Adapter
* Jumper Wires

## 💻 Software & Technologies

* **Arduino IDE**
* **C/C++**
* **MFRC522 Library**
* **SPI Communication**

## ⚙️ Working Principle

```text
             RFID Card / Tag
                    │
                    ▼
             ┌─────────────┐
             │    RC522    │
             │ RFID Reader │
             └──────┬──────┘
                    │
                  SPI
                    │
                    ▼
             ┌─────────────┐
             │ Raspberry   │
             │  Pi Pico    │
             └──────┬──────┘
                    │
                UID Check
                    │
             ┌──────┴──────┐
             │             │
         Authorized     Unauthorized
             │             │
             ▼             ▼
       Motor Driver     Motor OFF
            ON
             │
             ▼
          DC Motor
```

### 1. RFID Detection

The RC522 scans for a nearby RFID card or tag.

When a tag is detected, its UID is read by the Raspberry Pi Pico through the SPI interface.

### 2. Authentication

The detected UID is compared with the authorized UID stored in the program.

```text
Detected UID
     │
     ▼
Compare with
Authorized UID
     │
 ┌───┴────┐
 │        │
Match   No Match
 │        │
 ▼        ▼
Motor    Motor
 ON       OFF
```

### 3. Motor Control

When the correct RFID tag is detected, the Pico sends control signals to the **L298N motor driver**, which drives the DC motor.

The motor is powered using an external adapter through the motor driver.

## 🔌 Hardware Connections

### RC522 → Raspberry Pi Pico

The RC522 communicates with the Pico using **SPI**.

| RC522 Pin | Pico            |
| --------- | --------------- |
| 3.3V      | 3.3V            |
| GND       | GND             |
| SDA/SS    | Configured GPIO |
| SCK       | SPI Clock       |
| MOSI      | SPI MOSI        |
| MISO      | SPI MISO        |
| RST       | Configured GPIO |

> The GPIO assignments should match the pins defined in the Arduino sketch.

### Pico → L298N

The Pico provides digital control signals to the L298N motor driver.

```text
Pico
 │
 ├── IN1 ──► L298N
 └── IN2 ──► L298N
               │
               ▼
            DC Motor
```

The motor receives power from an **external adapter through the L298N**.

> The motor should not be powered directly from the Raspberry Pi Pico.

## 🔐 RFID Authentication

The project uses the RFID tag's UID for basic authentication.

An authorized UID is stored in the Arduino program:

```cpp
byte authorizedUID[] = {
    0xXX, 0xXX, 0xXX, 0xXX
};
```

When an RFID tag is scanned:

```text
IF UID == Authorized UID
        ↓
   Access Granted
        ↓
     Motor ON

ELSE
        ↓
   Access Denied
        ↓
     Motor OFF
```

## 📊 Expected Output

### Authorized Tag

```text
RFID Tag Detected
UID Matched
Access Granted
Motor ON
```

### Unauthorized Tag

```text
RFID Tag Detected
UID Not Matched
Access Denied
Motor OFF
```

## 📂 Project Structure

```text
RFID-Motor-Ignition/
│
├── RFID_Motor_Ignition/
│   └── RFID_Motor_Ignition.ino
│
├── images/
│   ├── circuit.jpg
│   └── project_setup.jpg
│
└── README.md
```

## 🚀 Getting Started

### 1. Install Arduino IDE

Install Arduino IDE and configure it for the Raspberry Pi Pico.

### 2. Install Pico Board Support

Add the Raspberry Pi Pico board package through the Arduino IDE Board Manager.

### 3. Install MFRC522 Library

Open:

```text
Arduino IDE
→ Library Manager
→ Search "MFRC522"
→ Install
```

### 4. Connect the Components

Connect the RC522 to the Pico through SPI and connect the L298N to the Pico and DC motor.

### 5. Set the Authorized UID

Update the authorized UID in the Arduino sketch.

### 6. Upload

Select the Raspberry Pi Pico as the target board and upload the code using Arduino IDE.

## 📸 Project Images

Add your project photographs to the `images` folder.

Example:

```markdown
![RFID Motor Ignition](images/project_setup.jpg)
```

## 🎯 Applications

The concept can be applied to:

* Vehicle ignition systems
* Two-wheeler security
* Access-control systems
* Machine authorization
* Industrial equipment control
* Restricted-access systems

## 🔮 Future Improvements

* Support multiple authorized RFID tags
* Add an LCD/OLED display
* Store authorized UIDs in memory
* Add an emergency stop switch
* Add automatic motor timeout
* Add access logging
* Implement stronger RFID authentication

## 📚 Skills Demonstrated

* Embedded Systems
* Raspberry Pi Pico
* Arduino IDE
* RFID / RC522
* SPI Communication
* C/C++ Programming
* Motor Driver Interfacing
* DC Motor Control
* Digital I/O
* Hardware Debugging
* Authentication Logic

## 📜 License

This project is developed for **educational and prototype purposes**.
