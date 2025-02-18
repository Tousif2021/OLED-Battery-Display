# ⚡ OLED Battery Display on RISC-V MCU  

This project demonstrates how to display dynamic content on an **OLED screen** using a **RISC-V-based microcontroller (IO-Card REV C)**.  
The program starts with a **welcome message** and features a **battery icon** that updates based on user input.  

## 🎯 Features  

✅ **Startup Message** – Displays a **welcome message** on boot.  
🔋 **Battery Level Indicator** – A battery icon visually represents different charge levels.  
🎮 **User-Controlled Input:**  
- `0` → **0% (Empty)**
- `1` → **25% (Low)**
- `2` → **50% (Half)**
- `3` → **75% (High)**
- `4` → **100% (Full, Green)**  

🎨 **Color-Coded Charge Levels:**  
- 🖤 `0%` → **Black (Empty)**  
- 🔴 `1-25%` → **Red (Low)**  
- 🟠 `25-50%` → **Orange (Medium)**  
- 🟡 `50-75%` → **Yellow (High)**  
- 🟢 `75-100%` → **Green (Full)**  

## 🛠️ Technologies Used  

- 🔹 **RISC-V MCU (IO-Card REV C)**  
- 🔹 **OLED Display (I2C/SPI Interface)**  
- 🔹 **Embedded C Programming**  

## 🚀 How It Works  

1️⃣ The **OLED screen** first shows a **welcome message** upon startup.  
2️⃣ The user provides an input (`0-4`) via a **keypad or serial interface**.  
3️⃣ The **battery icon updates** accordingly, both in **fill level** and **color**.  

## 📷 Screenshots (Optional)  

🖼️ **Welcome message display**  
🔋 **Battery icon at different charge levels**  
🎨 **Color changes with input** 

---

💡 **Future Improvements:**  
🔄 Add **animation effects** for smoother transitions.  
🎛️ Implement **analog input for real-time battery level updates**.  

🛠️ **Made with Embedded C for RISC-V!** 🚀  