# ⚡ Bitcoin Switch NFC Edition – *Bitcoin Manor Fork*

<img width="600" src="https://user-images.githubusercontent.com/33088785/166832680-600ed270-cbc9-4749-82f1-c1853b242329.png"><img width="600" src="https://user-images.githubusercontent.com/33088785/166829474-a28ca2b7-dd3e-46d4-89d3-8a10bf1d3fad.png">

### <small>Based on [LNbits Bitcoin Switch](https://github.com/lnbits/bitcoinSwitch) by Ben Arc & DNI</small>

Turn things on with Bitcoin — now with **Bolt Card tap-to-pay** support.

This is the **Bitcoin Manor / StacksWorth** fork of the legendary [LNbits Bitcoin Switch](https://bitcoinswitch.lnbits.com/) firmware.  
We’re extending the project to add **PN532 NFC** integration, allowing **Bolt Cards** and **smartphone NFC wallets** to trigger Lightning-powered hardware directly from a tap.

---

## 🔗 Official Resources
- **Web Installer:** [bitcoinswitch.lnbits.com](https://bitcoinswitch.lnbits.com)  
- **Original Repo:** [LNbits/bitcoinSwitch](https://github.com/lnbits/bitcoinSwitch)  
- **Tutorial:** [Makerbits YouTube](https://www.youtube.com/@makerbits7700)  
- **Community:** [t.me/makerbits](https://t.me/makerbits) | [t.me/lnbits](https://t.me/lnbits)

---

## 💡 What’s New in This Fork
- Optional **PN532 NFC reader** support (for Bolt Card & LNURL-tap payments)  
- Full compatibility with the official LNbits web installer  
- **ESP32** relay + LED + optional TFT display  
- On-screen feedback (“Tap to Pay”, “Paid”, etc.)

---

## 🧩 The NFC Hardware
<img width="600" src="https://m.media-amazon.com/images/I/71EjFqvOaQL._AC_SL1500_.jpg" alt="PN532 module">

| PN532 Pin | ESP32 Pin | Description |
|:--|:--|:--|
| VCC | 3.3 V | Power |
| GND | GND | Ground |
| SDA | GPIO 21 | I²C Data |
| SCL | GPIO 22 | I²C Clock |

> Tip – Some ESP32-S3 boards use SDA = 8 and SCL = 9.

---

## ⚙️ Standard Features (Inherited from LNbits)
✅ $8 in parts / ≈ 15 min setup  
✅ WebSocket instant relay control  
✅ Browser web installer included  
✅ Supports multiple GPIOs and LNURLs  

---

## 🧠 What You Can Build
- Arcade or vending machines  
- Candy / claw / coffee dispensers  
- Lights, locks, doors and gates  
- Any 5–12 V relay-driven device  

See [Wiki](https://github.com/lnbits/lnbits/wiki/Tooling-&-Building-with-LNbits) and [Shop](https://shop.lnbits.com/product-category/hardware/fun-things).

---

## 🪛 What You Need
- ESP32 Dev Kit  
- High-level relay  
- PN532 NFC module (I²C mode)  
- Jumper wires  
- Optional TFT display  
- LNbits instance with **Bitcoin Switch** enabled  

---

## 🧰 Development Setup
1. Install [Arduino IDE 1.8.19](https://www.arduino.cc/en/software)  
2. Add ESP32 boards via [Espressif Boards Manager](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)  
3. Clone this repo  
4. Copy included [libraries](libraries) to Arduino `libraries` folder  
5. Open `bitcoinSwitch.ino` in IDE  
6. Select board under **Tools → Board**  
7. Upload to device  

---

## ⚡ Web Installer Flashing
Use the official installer → [https://bitcoinswitch.lnbits.com](https://bitcoinswitch.lnbits.com)  
Press **GPIO 4** within a few seconds of boot to enter config mode.

---

## 📷 Example Builds
<table>
<tr>
<th><img src="https://user-images.githubusercontent.com/33088785/204107016-bc9473e0-2843-4873-af71-cd934e07f444.gif" width="80%"></th>
<th><img src="https://user-images.githubusercontent.com/33088785/204107029-cc4ad95b-b130-4b48-9091-86d7be7d4f16.gif" width="80%"></th>
<th><img src="https://user-images.githubusercontent.com/33088785/204107037-870571f8-b860-4019-93d4-bbdbeaf1091f.gif" width="80%"></th>
<th><img src="https://user-images.githubusercontent.com/33088785/204107044-b8a7d94f-6908-40dd-bb82-974e08f077f4.gif" width="80%"></th>
</tr>
</table>

---

## 🧑‍💻 Developers
**arduino-cli build and upload examples**
```bash
sh build.sh
```
```bash
sh build-installer.sh
```
```bash
cd installer
http-server -p 8080
```
```bash
arduino-cli compile --build-path build --fqbn esp32:esp32:esp32 bitcoinSwitch
```
```bash
arduino-cli monitor -p /dev/ttyUSB1 -c baudrate=115200
```
```bash
arduino-cli upload --fqbn esp32:esp32:esp32 --input-dir build -p /dev/ttyUSB1
```

---

## 🧡 Credits
**Original Authors:** Ben Arc, DNI (LNbits)  
**Fork Maintainer:** Bitcoin Manor / StacksWorth  
**License:** GPL-3.0  

---

## 🛠️ Project Vision
We’re extending **Bitcoin Switch** into the next generation of Lightning-connected devices by combining:  
- Fast LNbits payment integration  
- **NFC tap-to-pay** with Bolt Card and mobile wallets  
- Clear on-device display feedback  
- Open-source access for builders everywhere  

> “Turn anything on with Bitcoin — or now, with just a tap.”  
> — The Bitcoin Manor Team ⚡
