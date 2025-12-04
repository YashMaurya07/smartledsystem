# Smart LED System

Smart LED System is a compact, extensible firmware + controller project for driving addressable LED strips and managing lighting effects, schedules, and remote control. It is designed to run on small microcontrollers (ESP8266 / ESP32 style boards) and expose simple interfaces for local control, web UI, and integration (MQTT/REST). This repository contains the firmware, configuration examples, and helper scripts to get your LED installation up and running.

> NOTE: This README is intentionally general so it can apply to multiple hardware targets. Please update the Hardware, Pinout, and Build sections below with the exact board model and pins used in your setup.

Highlights
- Drive addressable LED strips (e.g., WS2812/WS2812B / SK6812)
- Multiple built-in lighting effects and color transitions
- Wi‑Fi based control with a simple web UI
- Optional MQTT and REST endpoints for automation and integrations
- Configurable schedules and persistent settings

Table of contents
- Project status
- Features
- Hardware
- Wiring
- Software stack
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

Project status
- Repository: active (initial implementation / prototype)
- Tested on: ESP8266 / ESP32 (update this with the exact boards you verified)
- Coverage: core effects, web UI, basic MQTT and REST controls
- Missing / TODO: device-specific optimizations, extended effect library, mobile app

Features
- Power on state restore and persistent configuration
- Smooth color fades, rainbow, chase, blink, and custom effect support
- Per-effect parameters (speed, intensity, palette)
- Schedule support (simple time-based on/off and effect selection)
- Network control via web UI, MQTT, and REST
- OTA updates (if enabled in your build)

Hardware
Minimum hardware required
- Microcontroller board (ESP8266 or ESP32 recommended)
- Addressable LED strip (WS2812, WS2812B, SK6812, or similar)
- 5V power supply capable of handling LED strip current
- Logic-level shifting as required (e.g., 3.3V -> 5V) depending on MCU and LED type
- Common ground between MCU and LED power supply

Recommended parts
- ESP8266 NodeMCU or Wemos D1 mini, or ESP32 DevKit
- WS2812B or SK6812 LED strip
- 5V, 2A+ power supply (depending on LED count)
- 470–1000 µF capacitor across 5V and GND (to protect LEDs)
- 330–500 Ω resistor in series with the data line to reduce ringing

Wiring (example)
- 5V power supply -> LED strip +5V
- Power supply GND -> LED strip GND
- MCU GND -> LED strip GND (common ground)
- MCU data pin (e.g., D2 on ESP8266 / GPIO18 on ESP32) -> through 330–500 Ω -> LED strip data in
- Optional: level shifter on data line if MCU IO is 3.3V and LED expects 5V

IMPORTANT SAFETY NOTE: Do not power long LED strips from the MCU 5V pin. Use a dedicated power supply sized for your LED count. Connect grounds together.

Software stack
- Firmware: Arduino framework or PlatformIO project (code folder)
- LED library: FastLED or Adafruit NeoPixel (recommended: FastLED for effects)
- Web UI: lightweight HTML/JS served by the device
- Integration: MQTT (optional), REST endpoints for HTTP control
- Build tools: Arduino IDE or PlatformIO

Quick start (developer)
1. Install required tools
   - Option A: PlatformIO (VS Code + PlatformIO extension)
   - Option B: Arduino IDE (with ESP8266/ESP32 board packages)
2. Install dependencies
   - FastLED (or Adafruit NeoPixel) library
   - PubSubClient (for MQTT, if used)
   - ArduinoJson (for config / API payloads)
3. Clone this repo
   git clone https://github.com/YashMaurya07/smartledsystem.git
4. Configure
   - Edit config/config.h or config.json (see Configuration section below)
5. Build and flash to your target board
   - PlatformIO: pio run -t upload
   - Arduino IDE: open the project and upload

Configuration
This section describes common configurable options. The exact config file / constants may vary in code — update as appropriate.

Common settings (example)
- SSID / Wi-Fi password (or Wi-Fi manager for runtime provisioning)
- LED count (NUM_LEDS)
- Data pin (LED_PIN)
- Brightness limit (MAX_BRIGHTNESS)
- Default effect and parameters
- MQTT broker, port, username, password, topic prefix (if using MQTT)
- HTTP server port and admin password (if using REST/web UI)
- Timezone and NTP server for schedules

Example config.json
{
  "wifi": {
    "ssid": "your-ssid",
    "password": "your-password"
  },
  "led": {
    "type": "WS2812B",
    "pin": 2,
    "count": 60,
    "brightness": 128
  },
  "mqtt": {
    "enabled": true,
    "broker": "192.168.1.50",
    "port": 1883,
    "base_topic": "smartled"
  },
  "default_effect": "rainbow",
  "timezone": "UTC"
}

Usage

Web UI
- Point your browser to http://<device-ip>/
- Use the UI to:
  - Turn LEDs on/off
  - Choose an effect
  - Set brightness and color
  - Configure schedules and network settings (if implemented)

MQTT
- If enabled, the device will connect to the configured MQTT broker.
- Topics (examples):
  - smartled/<device>/set — payload: JSON with command (on/off/effect/brightness)
  - smartled/<device>/state — device publishes current state
- Example payload to set effect:
  {"cmd":"effect","name":"chase","speed":5,"color":"#FF00FF"}

REST API
- GET /status — returns current state and effect
- POST /control — send JSON commands to control power, effect, brightness
- Sample command:
  POST /control
  {
    "power": "on",
    "effect": "rainbow",
    "brightness": 200
  }

Examples
- Turn all LEDs red and set brightness to 50% (REST):
  POST /control { "color": "#FF0000", "brightness": 128 }
- Start a chase effect via MQTT:
  Publish to smartled/livingroom/set:
    {"cmd":"effect","name":"chase","speed":7}

Troubleshooting
- LEDs flicker or show wrong colors:
  - Check data line resistor and common ground
  - Ensure correct LED type and chipset are configured in firmware (WS2812 vs. SK6812)
  - Verify sufficient power supply current and add capacitor across 5V/GND
- Device doesn't connect to Wi‑Fi:
  - Verify SSID/password and signal strength
  - Consider enabling serial debug or Wi‑Fi manager provisioning
- OTA or uploading fails:
  - Verify the selected board, COM port, and baud rate in your IDE
  - Remove power-hungry peripherals while flashing

Contributing
Contributions are welcome! Here are common ways to help:
- Open issues for bugs or feature requests (include steps to reproduce and logs)
- Submit pull requests for:
  - New effects or optimized effect algorithms
  - New board support (board-specific pin definitions)
  - Documentation improvements and wiring diagrams
- Follow the repository's code style and update README when adding user-facing features

Suggested PR process
1. Fork the repo
2. Create a feature branch
3. Add changes, tests (if any), and documentation updates
4. Open a PR describing your changes

License
This project is distributed under the MIT License. See LICENSE file for details.

Acknowledgements
- FastLED library for driving addressable LEDs
- Contributions and ideas from the open source LED community

Contact
- Maintainer: @YashMaurya07 (GitHub)
- For customization requests or to share what you built, open an issue or PR.

---

If you'd like, I can:
- customize the README with exact board model, pin numbers, and commands based on your repository code,
- create a wiring diagram image and include it in the README,
- or open a PR that adds this README to the repo (I can draft the PR text for you). Tell me which of these you'd like next.
```
