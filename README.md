<img width="600" src="https://user-images.githubusercontent.com/33088785/166832680-600ed270-cbc9-4749-82f1-c1853b242329.png"><img width="600" src="https://user-images.githubusercontent.com/33088785/166829474-a28ca2b7-dd3e-46d4-89d3-8a10bf1d3fad.png">

# ⚡ Bitcoin Switch NFC Edition – *Bitcoin Manor Fork*

### <small>Based on [LNbits Bitcoin Switch](https://github.com/lnbits/bitcoinSwitch) by Ben Arc & DNI</small>

Turn things on with Bitcoin — now with **Bolt Card tap-to-pay support**.

This is the **Bitcoin Manor / StacksWorth** fork of the legendary [LNbits Bitcoin Switch](https://bitcoinswitch.lnbits.com/) firmware.  
We’re extending the project to add **PN532 NFC integration**, allowing **Bolt Cards** and **smartphone NFC wallets** to trigger Lightning-powered hardware directly from your tap.

---

## 🔗 Official Resources

- **Web Installer:** [bitcoinswitch.lnbits.com](https://bitcoinswitch.lnbits.com)  
- **Original LNbits Repo:** [LNbits/bitcoinSwitch](https://github.com/lnbits/bitcoinSwitch)  
- **Tutorial:** [Makerbits YouTube](https://www.youtube.com/@makerbits7700)  
- **Community:** [t.me/makerbits](https://t.me/makerbits) | [t.me/lnbits](https://t.me/lnbits)

---

## 💡 What’s New in This Fork
✅ Optional **PN532 NFC reader** support (for Bolt Card & mobile LNURL-tap payments)  
✅ Maintains compatibility with the official LNbits Bitcoin Switch web installer  
✅ Uses **ESP32** with relay, LED, and TFT display  
✅ Optional screen feedback: “Tap to Pay”, “Payment Received”, etc.  

---

## 🧩 The NFC Hardware

This fork integrates the **PN532 NFC module** — the same board used for Bolt Card projects.  
It supports both **I²C** and **SPI** communication with the ESP32.

**Module reference:**  
<img width="600" src="https://m.media-amazon.com/images/I/71EjFqvOaQL._AC_SL1500_.jpg" alt="PN532 module">

| PN532 Pin | ESP32 Pin | Description |
|------------|------------|-------------|
| VCC | 3.3V | Power |
| GND | GND | Ground |
| SDA | GPIO 21 | I²C Data |
| SCL | GPIO 22 | I²C Clock |

---

## ⚙️ Standard Features (Inherited from LNbits)

✅ $8 worth of parts / ~15 minute setup  
✅ WebSocket-based instant relay control  
✅ Built-in browser web installer  
✅ Supports **multiple GPIOs and LNURLs**  

---

## 🧠 What You Can Build

Bitcoin Switch + NFC can trigger:
- Arcade machines  
- Vending / candy / claw machines  
- Lights, locks, gates, or coffee makers ☕  
- Any 12V or 5V relay-driven system  

Explore examples at [LNbits Wiki](https://github.com/lnbits/lnbits/wiki/Tooling-&-Building-with-LNbits) or [LNbits Shop](https://shop.lnbits.com/product-category/hardware/fun-things).

---

## 🪛 What You Need
- ESP32 Dev Kit  
- High-level relay  
- PN532 NFC module (I²C mode)  
- Jumper cables (male/female)  
- Optional: small TFT display  
- LNbits instance with the **Bitcoin Switch extension enabled**

---

## 🧰 Development Setup

For local flashing without the web installer:

1. Install [Arduino IDE 1.8.19](https://www.arduino.cc/en/software)  
2. Install ESP32 boards using [Espressif’s board manager guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)  
3. Download this repo  
4. Copy the included [libraries](libraries) folder into your Arduino `libraries` directory  
5. Open `bitcoinSwitch.ino` in Arduino IDE  
6. Select your ESP32 board under **Tools → Board**  
7. Upload to device  

---

## ⚡ Web Installer Flashing
Flash & configure your device directly via  
👉 [https://bitcoinswitch.lnbits.com/](https://bitcoinswitch.lnbits.com/)  

After flashing, press **GPIO4** within a few seconds of boot to enter configuration mode.

---

## 📷 Example Builds

<table>
  <tr>
    <th><img src="https://user-images.githubusercontent.com/33088785/204107016-bc9473e0-2843-4873-af71-cd934e07f444.gif" alt="Switch" style="width:80%"></th>
    <th><img src="https://user-images.githubusercontent.com/33088785/204107029-cc4ad95b-b130-4b48-9091-86d7be7d4f16.gif" alt="Machine" style="width:80%"></th>
    <th><img src="https://user-images.githubusercontent.com/33088785/204107037-870571f8-b860-4019-93d4-bbdbeaf1091f.gif" alt="Vending" style="width:80%"></th>
    <th><img src="https://user-images.githubusercontent.com/33088785/204107044-b8a7d94f-6908-40dd-bb82-974e08f077f4.gif" alt="Arcade" style="width:80%"></th>
  </tr>
</table>

---

## 🧑‍💻 Developers

Build with **arduino-cli**

```bash
sh build.sh

---

##🧡 Credits

Original Authors: Ben Arc, DNI (LNbits)
Fork Maintainer: Bitcoin Manor / StacksWorth
License: GPL-3.0

---

##🛠️ Project Vision

We’re extending Bitcoin Switch into the next generation of Lightning-connected devices by combining:

Fast LNbits payment integration

NFC tap-to-pay using Bolt Card and compatible phone wallets

Clear, on-device display feedback

Open-source accessibility for builders everywhere

“Turn anything on with Bitcoin — or now, with just a tap.” — The Bitcoin Manor Team ⚡
