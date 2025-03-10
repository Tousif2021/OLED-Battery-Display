#include "gd32vf103.h"
#include "drivers.h"
#include "lcd.h"
#include <stdio.h>

#define BATTERY_X 65  // X position for battery display (Centered)
#define BATTERY_Y 50  // Y position for battery display
#define BATTERY_WIDTH 40
#define BATTERY_HEIGHT 25

void drawBattery(int level);
void delay_ms(int ms);
int main(void) {
    int ms=0, s=0, key, pKey=-1, c=0, idle=0;
    int lookUpTbl[16]={1,4,7,14,2,5,8,0,3,6,9,15,10,11,12,13};
    int batteryLevel = 0;  // Start with empty battery
    
    t5omsi();       
    colinit();
    l88init();
    keyinit();
    
    // Initialize LCD
    Lcd_SetType(LCD_NORMAL);
    Lcd_Init();
    LCD_Clear(BRRED);   // BLACK background 
    
    // Mitt namn
    //LCD_ShowStr(30, 20, "SYSTEM LOADING...", CYAN, TRANSPARENT);
    for (int i = 0; i < 4; i++) {
    LCD_ShowStr(55, 40, ".", CYAN, TRANSPARENT);
    delay_ms(1000);
    LCD_ShowStr(55, 40, "  ", BLACK, TRANSPARENT);
    }
    LCD_Clear(BLACK);
    LCD_ShowStr(20, 3, "Battery Monitor", CYAN, TRANSPARENT);
    LCD_ShowStr(26, 23, "By Tousif Dewan", GRAY, TRANSPARENT);
    LCD_ShowStr(0, 27, "____________________", BLUE, TRANSPARENT);
    // Show initial battery
    drawBattery(batteryLevel);

    while (1) {
        idle++;   
        LCD_WR_Queue();

        if (t5expq()) {  
            l88row(colset()); 
            ms++;  
            
            if (ms == 1000) {
                ms = 0;
                l88mem(0, s++);
            }
            
            if ((key = keyscan()) >= 0) {
                int newLevel = -1;
                switch (lookUpTbl[key]) {
                    case 0: newLevel = 0; break;  // Initial = Empty Battery
                    case 1: newLevel = 1; break;  // 25%
                    case 2: newLevel = 2; break;  // 50%
                    case 3: newLevel = 3; break;  // 75%
                    case 4: newLevel = 4; break;  // 100% (Full)
                }

                if (newLevel >= 0 && newLevel != batteryLevel) {
                    batteryLevel = newLevel;
                    drawBattery(batteryLevel);  // Update battery visual
                }
                
                if (pKey == key) c++; else { c = 0; pKey = key; }
                l88mem(1, lookUpTbl[key] + (c << 4));

            }
          }

            l88mem(2, idle >> 8);  
            l88mem(3, idle); 
            idle = 0;
        }
    }

//  Battery Drawing Function
void drawBattery(int level) {
    char percentStr[10];  // Buffer for percentage text
    int targetFill = (level * (BATTERY_WIDTH - 4)) / 4;  
    int fillColor;
    if (level == 0) fillColor = RED;       // 0-25% → Red
    else if (level == 1) fillColor = RED; // 25-50% → Brown
    else if (level == 2) fillColor = BRRED; // 50-75% → Golden Yellow
    else if (level == 3) fillColor = YELLOW;
    else fillColor = GREEN;

    for (int w = 0; w <= targetFill; w++) {  // Animate the fill
        LCD_Fill(BATTERY_X + 2, BATTERY_Y + 2, BATTERY_X + 2 + w, BATTERY_Y + BATTERY_HEIGHT - 2, fillColor);
        delay_ms(50);  // Small delay for smooth effect
    }
    // Draw Battery Outline
    LCD_Fill(BATTERY_X, BATTERY_Y, BATTERY_X + BATTERY_WIDTH, BATTERY_Y + BATTERY_HEIGHT, WHITE); // Outer Border
    LCD_Fill(BATTERY_X + BATTERY_WIDTH, BATTERY_Y + BATTERY_HEIGHT / 4, 
             BATTERY_X + BATTERY_WIDTH + 5, BATTERY_Y + (3 * BATTERY_HEIGHT / 4), WHITE); // Small tip on right

    // Fill the Battery Based on Level
    if (targetFill > 0) {
        LCD_Fill(BATTERY_X + 2, BATTERY_Y + 2, BATTERY_X + 2 + targetFill, BATTERY_Y + BATTERY_HEIGHT - 2, fillColor);
    }
    
    // Centered Percentage Text Inside Battery
    sprintf(percentStr, "%d%%", level * 25);
    LCD_ShowStr(BATTERY_X + (BATTERY_WIDTH / 2) - 6,  // Centered horizontally
                BATTERY_Y + (BATTERY_HEIGHT / 2) - 6,  // Centered vertically
                percentStr, BLACK, TRANSPARENT);

}

void delay_ms(int ms) {
     for (int i = 0; i < ms * 1000; i++) {
         asm volatile("nop");
     }
      }
