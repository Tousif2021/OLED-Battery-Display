# OLED Battery Monitor - Smart Power Display 🔋

This project is a **real-time battery monitoring system** designed for **embedded OLED displays**. It features **dynamic color-coded battery levels**, a **charging animation**, percentage tracking, and a **sleek UI** for professional visualization.

## ✨ Features
✅ **Real-time Battery Status** - Updates dynamically based on input.  
✅ **Color-Coded UI** - Battery level changes color:  
   - 🔴 **0-25%** - Red (Low Power Warning)  
   - 🟤 **25-50%** - Brown (Moderate Power)  
   - 🟡 **50-75%** - Golden Yellow (Optimal)  
   - 🟢 **75-100%** - Green (Fully Charged)  
✅ **Charging Animation** - ⚡ Battery pulses while charging.  
✅ **Battery Percentage Display** - Shows power levels inside the battery icon.    
✅ **Smooth UI Experience** - Professionally aligned text & dynamic effects.  

---

## 🎨 **Project Preview**
🚀 **OLED UI Snapshot**
[Insert Screenshot Here]  

---

## ⚙️ **Setup & Usage**
### 📌 **Hardware Requirements**
- **GD32VF103**(RISC-V) or similar MCU  
- **128x64 OLED Display**  
- **Embedded Keypad (for input simulation)**  

### 📌 **Software & Tools**
- **Platform:** VS Code + GD32 RISC-V Toolchain  
- **Programming Language:** C and Assembly  
- **Display Driver:** `lcd.h`  
