#include "../lib/tiny-oled.cpp"
#include <Arduino.h>

void printCharacter(char character)
{
    I2C_start(OLED_ADDR); // start transmission to OLED
    I2C_write(OLED_DAT_MODE);
    OLED_printC(character);
    I2C_stop();
}

void printColumn(uint8_t column)
{
    I2C_start(OLED_ADDR); // start transmission to OLED
    I2C_write(OLED_DAT_MODE);
    I2C_write(column);
    I2C_stop();
}

void printString(const char *string)
{
    I2C_start(OLED_ADDR); // start transmission to OLED
    I2C_write(OLED_DAT_MODE);

    for (size_t i = 0; i < strlen(string); i++)
    {
        OLED_printC(string[i]);
    }

    I2C_stop();
}

void setup()
{
    OLED_init();

    OLED_clear();
    OLED_cursor(0, 0); // set cursor position

    printString("XYZ");
}

void loop()
{

}
