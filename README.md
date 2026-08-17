# 小Q同学 XiaoQ Companion 🐱

&gt; An AI emotional companion plush toy powered by ESP32-S3.  
&gt; 一个基于 ESP32-S3 的 AI 情感陪伴玩偶，你的个性化伴读书童。

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![ESP32-S3](https://img.shields.io/badge/Hardware-ESP32--S3-blue)](https://www.espressif.com/en/products/socs/esp32-s3)
[![XiaoZhi Protocol](https://img.shields.io/badge/Protocol-XiaoZhi%20AI-green)](https://github.com/78/xiaozhi-esp32)

## 📹 Demo

*(Video coming soon — prototype already running wake-word → ASR → LLM → TTS full pipeline)*

## ✨ Features

- 🎙️ **Offline Wake Word Detection** — Local WakeNet on ESP32-S3, waiting for "小Q同学"
- 🧠 **Cloud AI Dialogue** — Connected to LLM (Qwen / DeepSeek) for natural conversation
- 📚 **Study Companion Mode** — Explains homework, tells stories, answers curiosity
- 🔊 **I2S Audio Pipeline** — MAX98357A amplifier + INMP441 MEMS microphone
- 🔋 **Rechargeable Battery** — Single 18650 Li-ion with USB-C charging
- 🧸 **Plush Toy Form Factor** — Lying-cat design (300×100 mm), soft and huggable

## 🏗️ System Architecture
┌─────────────┐      WebSocket       ┌─────────────────────────────┐
│  ESP32-S3   │ ◄──────────────────► │  Cloud Server               │
│  (Device)   │   Audio Stream       │  - ASR (Whisper)            │
├─────────────┤                      │  - LLM (Qwen / DeepSeek)    │
│ INMP441 Mic │                      │  - TTS (Edge-TTS / Azure)   │
│ MAX98357A   │                      └─────────────────────────────┘
│ Speaker     │
│ 18650 Batt  │
└─────────────┘

## 🔌 Hardware

| Component | Model | Function |
|-----------|-------|----------|
| MCU | ESP32-S3-WROOM-1-N16R8 | Main controller, Wi-Fi + BLE |
| Microphone | INMP441 | I2S digital MEMS mic |
| Amplifier | MAX98357A | I2S 3W Class-D audio amp |
| Speaker | 4Ω 3W cavity speaker | Voice output with sealed chamber |
| Battery | 18650 2600mAh Li-ion | Power supply |
| Charger | TP4056 + DW01A | USB-C charging + protection |
| Structure | 3D printed PETG internal chassis | Head / Body / Base compartments |

## 📐 Internal Structure (Compartment Design)
┌─────────────────────────────────────────┐
│  [Head]  Speaker + Microphone          │
│          Sealed audio chamber           │
├─────────────────────────────────────────┤
│  [Body]  ESP32-S3 + Power PCB          │
│          Antenna window, no metal shield │
├─────────────────────────────────────────┤
│  [Base]  18650 Battery + USB-C Port    │
│          Charging port exposed (belly)  │
└─────────────────────────────────────────┘

## 🚀 Quick Start

### Hardware Wiring

| ESP32-S3 | MAX98357A | INMP441 |
|----------|-----------|---------|
| GPIO26 | BCLK | SCK |
| GPIO25 | LRC | WS |
| GPIO22 | DIN | — |
| GPIO23 | — | SD |
| 3V3 | — | VDD |
| 5V | VIN | — |
| GND | GND | GND |

### Firmware

Based on [xiaozhi-esp32](https://github.com/78/xiaozhi-esp32) with custom board support.

```bash
git clone https://github.com/YOUR_USERNAME/XiaoQ-Companion.git
cd XiaoQ-Companion
idf.py set-target esp32s3
idf.py build flash
📋 Roadmap
[x] Breadboard prototype (ESP32 + MAX98357A + INMP441)
[x] Cloud dialogue pipeline (Wake → ASR → LLM → TTS)
[ ] Internal wiring with silicone cables
[ ] 3D printed chassis (PETG)
[ ] Plush toy integration (lying-cat shell)
[ ] Custom wake word "小Q同学" ← Waiting for ESP-SR model
[ ] OTA firmware updates
[ ] Parental control dashboard
🤝 Wake Word Request
We are requesting the ESP-SR team to add a community wake word model for "小Q同学" (xiao3 q1 tong2 xue2).
See: espressif/esp-sr#88
📄 License
MIT License — feel free to use for personal or commercial projects.
🙏 Acknowledgements
xiaozhi-esp32 — MCP-based chatbot firmware
ESP-SR — Espressif speech recognition framework
ElatoAI — Inspiration for voice AI toys
