# Wireless Robotic Piano (9-DOF Tele-operation System) 🎹🤖

**An automatic control systems project featuring a compact actuator system capable of playing 18 piano keys using only 9 motors.**

## 📂 Project Resources
* **[View Project Slides & Circuit Diagram (PDF)](./Wireless%20Robotic%20Piano.pdf)** *(Note: Click to view architecture)*
* **[View Source Code](./Piano_Code.ino)**

---

## 🔧 Technical Breakdown

### 1. Kinematics & Actuation
* **Optimization:** Solved hardware constraints by designing a **Bi-directional Actuation** mechanism. Each Servo controls two distinct outputs (CW → Key A, CCW → Key B), effectively doubling the system's mechanical resolution.
* **Hardware:** 9x SG90 Micro Servos with custom direct-drive horns.

### 2. Power Integrity & Safety
* **Problem:** Non-linear current demand (up to 4A peak) caused brownouts.
* **Solution:** Integrated an **XL4015 DC-DC Buck Converter** to step down 12V Li-Ion sources to a regulated 6V/5A rail. This isolated the high-current motor load from the microcontroller's logic.

### 3. Embedded Software & Architecture
* **Controller:** Arduino Uno.
* **Communication:** HC-05 Bluetooth Module (UART) using `SoftwareSerial`.
* **Latency:** Tuned signal timing (120ms actuation window) to ensure responsive playback.

---

## 🎮 Manual Control Map (ASCII Interface)

We implemented a real-time ASCII-to-Angle interface for wireless tele-operation.

| Letter | Note | Color | Servo | Direction |
| :---: | :--- | :--- | :---: | :--- |
| **a** | Do | Pink | 0 | Left |
| **b** | Re | Orange | 1 | Left |
| **c** | Mi | White | 0 | Right |
| **d** | Fa | Green | 1 | Right |
| **e** | Sol | Blue | 2 | Left |
| **f** | La | White | 3 | Left |
| **g** | Si | White | 2 | Right |
| **h** | High Do | White | 3 | Right |
| **i** | High Re | White | 4 | Left |
| **j** | High Mi | White | 5 | Left |
| **k** | High Fa | White | 4 | Right |
| **l** | High Sol | White | 5 | Right |
| **m** | High La | White | 6 | Left |
| **n** | High Si | White | 6 | Right |

### Automatic Presets
* **`1`** : Happy Birthday 🎂
* **`2`** : Merry Christmas 🎄
* **`5`** : Ode to Joy (Dual Octave) 🎻
