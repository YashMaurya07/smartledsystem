# 🚀 Smart LED System

Smart LED System is a compact, extensible firmware + controller platform for driving addressable LED strips with beautiful lighting effects, Wi-Fi remote control, automation support, and optional MQTT/REST integration.  
Designed for **ESP8266 (NodeMCU / Wemos D1 mini)** and **ESP32 DevKit** boards.

This repository includes the firmware, configuration examples, and helper utilities needed to deploy responsive, network-controlled LED lighting.

---

## ✨ Highlights
- Drive WS2812 / WS2812B / SK6812 addressable LEDs  
- Smooth fades, rainbow, chase, breathe, strobe & custom effects  
- Wi-Fi based control with a clean Web UI  
- MQTT & REST APIs for automation (Home Assistant compatible)  
- Persistent configuration & effect restore on reboot  
- OTA updates (optional)  
- Lightweight and extensible effect engine  

---

## 📌 Table of Contents
- Project Status  
- Features  
- Hardware  
- Wiring  
- Software Stack  
- Quick Start  
- Configuration  
- Usage  
  - Web UI  
  - MQTT  
  - REST API  
- Examples  
- Troubleshooting  
- Contributing  
- License  
- Acknowledgements  
- Contact  

---

## 📊 Project Status
| Component | Status |
|----------|--------|
| Repository | 🔥 Active — core components complete |
| Boards Tested | ESP8266 NodeMCU, ESP32 DevKit |
| Features | Effects engine, Web UI, MQTT, REST |
| TODO | More optimized effects, mobile app, multi-device sync |

---

## ⭐ Features
- Persistent config (LED count, brightness, effect)  
- Real-time color, brightness & effect updates  
- Per-effect parameters (speed, intensity, palette)  
- Network control via Web UI  
- MQTT broker support for automations  
- REST API for programmatic control  
- OTA firmware updates (optional)  
- Modular, easy to extend with new effects  

---

## 🔧 Hardware

### Minimum Requirements
- ESP8266 (NodeMCU / Wemos D1 mini) or ESP32 DevKit  
- WS2812B / SK6812 LED strip  
- 5V Power supply (2A+ depending on LED count)  
- Common ground between MCU and LED supply  

### Recommended Extras
- 470–1000 µF capacitor across 5V/GND  
- 330–500 Ω resistor inline with data pin  
- Optional level shifter for long LED strips  

---

## 🧩 Wiring (ESP8266 Example)

### LED Strip
| LED Wire | Connect To |
|----------|------------|
| +5V      | External 5V PSU |
| GND      | PSU GND + ESP GND |
| Data In  | D2 (GPIO4) through 330–500 Ω resistor |

### Power Safety Notes
- **Never power LED strips from the MCU 5V pin.**  
- Always use a dedicated power supply sized for your LED count.  
- Connect **all grounds together**.

---

## 🖥 Software Stack
- Firmware: Arduino / PlatformIO  
- LED Driver: FastLED  
- Web UI: Lightweight HTML/JS  
- Network: Wi-Fi + AsyncWebServer  
- APIs: MQTT (PubSubClient), REST (HTTP JSON)  
- Config: JSON file or header defines  

---

## ⚡ Quick Start (Developer Setup)

### 1. Install Tools
**Option A — PlatformIO (recommended)**  
- VS Code + PlatformIO extension  

**Option B — Arduino IDE**  
- Install ESP8266/ESP32 board packages  

### 2. Install Libraries
- FastLED  
- ArduinoJson  
- PubSubClient (optional for MQTT)  

### 3. Clone the Repo
```sh
git clone https://github.com/YashMaurya07/smartledsystem.git
