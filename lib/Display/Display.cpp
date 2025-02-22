#include "Display.h"
#include <Arduino.h>
#include "M5StickCPlus.h"

Display::Display(M5Display* tft, String name_remote):
    buffer(tft),
    name(name_remote)
{
    buffer.createSprite(240, 135);
    buffer.setTextColor((negatif?TFT_WHITE:TFT_BLACK));
    buffer.setCursor(0, 0);
}

void Display::set_init_screen(bool do_pair)
{
    buffer.fillRect(0, 0, 240, 135, (negatif?TFT_BLACK:TFT_WHITE));
    
    buffer.setTextSize(2);
    buffer.setFreeFont(font_name);
    buffer.drawString(name, 120 - (buffer.textWidth(name)/2.0), 20 +  font_name->glyph->height); 
    
    if(do_pair){
        buffer.setTextSize(1);
        buffer.setFreeFont(font_text);
        buffer.drawString("Pairing in progress", 120 - (buffer.textWidth("Pairing in progress")/2.0), 95); 
    }

    buffer.pushSprite(0,0);
}

void Display::set_address(String address_str)
{
    address = address_str;
    address.toUpperCase();
}

void Display::set_main_menu_screen(int delay, String status)
{
    buffer.fillRect(0, 0, 240, 135, (negatif?TFT_BLACK:TFT_WHITE));

    buffer.setFreeFont(font_text);
    buffer.setTextSize(1);
    buffer.drawString(address, 120 - (buffer.textWidth(address)/2.0), 5);
    buffer.drawLine(0, 28, 240, 28, (negatif?TFT_WHITE:TFT_BLACK));
    buffer.drawString(status, 120 - (buffer.textWidth(status)/2.0), 112);
    buffer.drawLine(0, 107, 240, 107, (negatif?TFT_WHITE:TFT_BLACK));

    buffer.drawString("Interval (secs):", 30, 35);
    buffer.setFreeFont(font_titles);
    buffer.drawFloat(float(delay)/1000.0, 1, 30, 60);

    buffer.pushSprite(0,0);
}