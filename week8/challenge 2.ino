//Name: Alex Dorodko
//Date: 08/NOV/2020
//Purpose: this is a program to make sure the LCD is functioning

#include <LiquidCrystal.h>

//Initialise the Serial LCD.

LiquidCrystal lcd(12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack
int vertical = 0;

void setup()
{
    lcd.begin (16,2); //Initialize the LCD.

}
void loop()
{
    for (int horizontal = 0; horizontal < 13; horizontal++)
    {
        lcd.clear();
        lcd.setCursor(horizontal,vertical); //goto first column and first line (0,0)
        lcd.print("Alex"); //Print at cursor Location
        delay(500);
    }

    vertical = 1;

    for (int horizontal = 12; horizontal >= 0; horizontal--)
    {
        lcd.clear();
        lcd.setCursor(horizontal,vertical); //goto first column and first line (0,0)
        lcd.print("Alex"); //Print at cursor Location
        delay(500);
    }

    vertical = 0;
}   

