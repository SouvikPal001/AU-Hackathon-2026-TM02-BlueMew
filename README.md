# AI-Driven Vision-Based Intelligent Lighting System

> **AI Impact Summit 2026 Hackathon Submission**
> 
> TRACK: AI FOR RENEWABLE ENERGY & CLIMATE ACTION

---

## Problem Statement

In homes, campuses, offices, and public infrastructure, lights often remain ON even when no humans are present. Traditional solutions such as timers, motion sensors, or manual switches are either inefficient, error‑prone, or incapable of understanding real human presence.

This leads to:

* Significant energy wastage
* Increased electricity costs
* Higher carbon footprint
* Poor scalability for smart infrastructure

---

## Solution Overview

**AI-Driven Vision‑Based Intelligent Lighting System** is a system that uses real‑time computer vision to detect actual human presence and automatically control lighting.

Instead of relying on indirect signals (motion, time, or distance), the system *sees* and *understands* whether a human is present, and makes lighting decisions accordingly.

---

## Core Idea

> *Lights should respond to humans — not assumptions.*

By combining:

* **Computer Vision (YOLOv8)** for human detection
* **Ambient light sensing (BH1750)** for context awareness
* **Microcontroller‑based hardware control (Arduino + Relay)**

This system ensures that lights turn ON **only when both conditions are met**:

1. A human is detected
2. Ambient light is insufficient

---

## System Architecture

1. Camera captures live video feed
2. YOLOv8 model performs real‑time human detection
3. Detection confidence is evaluated
4. BH1750 sensor checks ambient light intensity
5. Decision logic determines ON/OFF state
6. Arduino controls relay module
7. Lamp responds instantly

---

## Tech Stack

### Software

* Python
* YOLOv8 (Ultralytics)
* OpenCV
* PySerial

### Hardware

* Arduino Uno
* Relay Module
* BH1750 Light Intensity Sensor
* LED Lamp / Bulb
* USB Camera (Laptop Camera)

---

## Hackathon Implementation Scope

This repository represents the **hackathon‑specific implementation, integration, and optimization** of the system.

### Work done during the hackathon includes:

* Designing a clean, modular project structure
* Integrating real‑time human detection with hardware control
* Implementing light‑aware decision logic using BH1750
* Optimizing detection stability and confidence thresholds
* Preparing a reliable demo‑ready pipeline
* Documenting system architecture and impact

---

## Project Structure

```
AU-Hackathon-2026-TM02-BlueMew/
│
├── arduino/
│   └── lamp_control.ino
│
├── src/
│   ├── main.py
│   ├── human_detection.py
│   └── config.py
│
├── requirements.txt
├── README.md
└── .gitignore
```

---

## How It Works (Simplified)

* Camera continuously monitors the environment
* YOLOv8 detects humans in the frame
* If **human detected AND light level < threshold** → Light ON
* If **no human OR sufficient ambient light** → Light OFF

---

## Impact & Use Cases

### Impact

* Reduces unnecessary energy consumption
* Lowers electricity costs
* Contributes to sustainable infrastructure
* Minimizes false triggers compared to motion sensors

### Use Cases

* Smart classrooms
* Offices & workspaces
* Hostels & corridors
* Smart homes
* Energy‑efficient campuses

---

## Future Scope

* Multi‑camera support
* Edge‑AI deployment (Jetson / Raspberry Pi)
* Crowd density‑based lighting control
* Smart city street lighting integration
* Mobile dashboard for monitoring & analytics

---

## Demo Status

✅ Fully functional prototype
✅ Real‑time detection & hardware response
✅ Tested in controlled indoor environment

---

## Conclusion

The **AI-Driven Vision-Based Intelligent Lighting System** demonstrates how **computer vision can move beyond screens** and create tangible real‑world impact. By combining AI with low‑cost hardware, this project showcases a scalable, sustainable, and intelligent approach to energy management.

> *Smarter systems don’t just automate — they understand.*

---

## Author

**Souvik Pal**
AI Impact Summit 2026 Hackathon Participant

---

## 📜 License

This project is intended for educational, research, and hackathon demonstration purposes.
