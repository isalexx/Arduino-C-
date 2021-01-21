//Name: Alex Dorodko
//Date: 08/NOV/2020
//Purpose: this is a program to rotate between my name, favority hobby, and what i want for lunch.

#include <LiquidCrystal.h>

//Initialise the Serial LCD.

LiquidCrystal lcd(12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack
int button1Pin = 6;
int flag = 0;

void setup()
{
    lcd.begin (16,2); //Initialize the LCD.
}
void loop()
{
    if (digitalRead(button1Pin) == HIGH)
        {
            if (flag == 0)
            {
                flag = 1;
                delay(300);
            }

            else if(flag == 1)
            {
                flag = 2;
                delay(300);
            }

            else if(flag == 2)
            {
                flag = 0;
                delay(300);
            }
        }  


    if (flag == 0)
    {
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (0,0)
        lcd.print("Alex"); //Print at cursor Location
        delay(500);
    }

    else if (flag == 1)
    {
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (0,0)
        lcd.print("Driving"); //Print at cursor Location
        delay(500);
    }

    else if (flag == 2)
    {
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (0,0)
        lcd.print("Pizza"); //Print at cursor Location
        delay(500);

    }
}   
