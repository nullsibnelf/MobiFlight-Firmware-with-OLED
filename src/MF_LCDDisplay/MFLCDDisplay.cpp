//
// MFLCDDisplay.cpp
//
// (C) MobiFlight Project 2022
//

#include "MFLCDDisplay.h"#include <Wire.h>

#include "Adafruit_SSD1306.h"
#define SCREEN_WIDTH  128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    0   // Reset pin # (or -1 if sharing Arduino reset pin)

MFLCDDisplay::MFLCDDisplay()
{
    _initialized = false;
}

void MFLCDDisplay::display(const char *string)
{
    if (!_initialized)
        return;

    // SSD1306 OLED Init
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.display();
    display.setTextColor(WHITE);
    display.setTextSize(2);

    for (uint8_t line = 0; line != _lines; line++) {
        display.setCursor(0, 1 + line * 16);
        display.print(&string[line * _cols]);
    }
    display.display();
}

void MFLCDDisplay::attach(byte address, byte cols, byte lines)
{
    _address     = address;
    _cols        = cols;
    _lines       = lines;
    _initialized = true;
    _lcdDisplay.init((uint8_t)address, (uint8_t)cols, (uint8_t)lines);
    // _lcdDisplay.backlight();
    Wire.setClock(400000);
    // test();
}

void MFLCDDisplay::detach()
{
    if (!_initialized)
        return;
    _initialized = false;
}

void MFLCDDisplay::powerSavingMode(bool state)
{
    /*
    if (state)
        _lcdDisplay.noBacklight();
    else
        _lcdDisplay.backlight();
    */
}

void MFLCDDisplay::test()
{
    /*
    if (!_initialized)
        return;
    uint8_t preLines = 0;
    _lcdDisplay.clear();

    if (_lines > 2) {
        preLines = (_lines / 2) - 1; // floor needs much Flash and for integer it's the same
    }

    _printCentered("MobiFlight", preLines++);
    if (_lines > 1) {
        _printCentered("Rocks!", preLines++);
    }

    _lcdDisplay.setCursor(0, 0);
    */
}

void MFLCDDisplay::_printCentered(const char *str, uint8_t line)
{
    /*
    uint8_t startCol  = 0;
    uint8_t printChar = _cols;

    if (_cols > strlen(str)) {
        startCol  = (_cols - strlen(str)) / 2;
        printChar = strlen(str);
    }

    _lcdDisplay.setCursor(startCol, line);

    for (uint8_t i = 0; i < printChar; i++) {
        _lcdDisplay.write(str[i]);
    }
    */
}

// MFLCDDisplay.cpp
