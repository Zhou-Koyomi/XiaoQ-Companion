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
