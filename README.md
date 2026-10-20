# rc-fuse-blaster
Secure wireless electronic fuse igniter and pyrotechnic firing system using RF telemetry and hardware safety interlocks.
# 🧨 RC Fuse Blaster & Remote Pyrotechnic Igniter

> A secure, dual-interlock wireless electronic firing system designed for safe, long-distance remote ignition of model rocket engines and pyrotechnic fuses via RF telemetry.

[![Status](https://img.shields.io/badge/Status-Completed-emerald?style=for-the-badge)]()
[![MCU](https://img.shields.io/badge/MCU-Arduino_/_ESP32_NodeMCU-blue?style=for-the-badge)]()

---

## 🎯 Overview & Mission Objective
Manual ignition of model rocket or pyrotechnic fuses poses safety risks. The **RC Fuse Blaster** solves this by establishing a wireless command link between a handheld transmitter and a remote firing node. It incorporates hardware safety interlocks (arming key switch + continuity check) to prevent accidental firing before final execution.

---

## 🛠️ Bill of Materials (BOM)
| Component | Specification / Role |
| :--- | :--- |
| **Arduino Nano / ESP32** | Core microcontroller handling security handshakes and ignition timing |
| **RF Transceiver / NRF24L01 / 433MHz** | Encrypted wireless command link between controller and receiver |
| **High-Current MOSFET (IRFZ44N / IRLZ44N)** | Electronic switch capable of delivering high surge current to the igniter wire |
| **Arming Key Switch & Safety Relay** | Physical hardware interlock to prevent premature triggering |
| **Continuity Test Circuit** | Low-current LED indicator verifying igniter bridge wire integrity |
| **Power Architecture** | Independent high-drain LiPo battery pack dedicated to the firing surge |

---

## 📌 GPIO Pinout & Safety Interlock Mapping
| Component | Component Pin | Microcontroller Pin | Engineering Function |
| :--- | :--- | :--- | :--- |
| **Arming Safety Key** | `Digital IN` | `GPIO 2` | Hardware Arming Interlock Check |
| **Continuity Sensor** | `Analog / Digital Sense` | `A0` | Igniter Bridge Wire Continuity Test |
| **MOSFET Ignition Gate** | `Gate Driver` | `GPIO 5` | High-Current Firing Pulse Output |
| **RF Transceiver** | `SPI Bus / CE / CSN` | `Standard SPI Pins` | Wireless Command Packet Reception |

---

## 📂 Repository Structure
```text
📂 rc-fuse-blaster
├── 📂 firmware             <-- C++ source code (fuse_blaster_node.ino)
├── 📂 schematics           <-- Safety interlock and MOSFET firing circuit guide
└── 📄 README.md            <-- Project documentation
