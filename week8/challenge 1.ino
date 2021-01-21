//Name: Alex Dorodko
//Date: 08/NOV/2020
//Purpose: this is a program to make sure the LCD is functioning

#include <LiquidCrystal.h>

//Initialise the Serial LCD.

LiquidCrystal lcd(12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack

void setup()
{
    lcd.begin (16,2); //Initialize the LCD.
}
void loop()
{
    lcd.clear();
    lcd.setCursor(6,0); //goto first column and first line (0,0)
    lcd.print("321"); //Print at cursor Location
    lcd.setCursor(0,1); //goto first column and second line
    lcd.print("Maker"); //Print at cursor Location
    delay(1000);
}