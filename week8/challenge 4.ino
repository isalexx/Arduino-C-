//Name: Alex Dorodko
//Date: 08/NOV/2020
//Purpose: this is a program to make sure the LCD is functioning

#include <LiquidCrystal.h>

//Initialise the Serial LCD.

LiquidCrystal lcd(12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack
int button1Pin = 6;
int button2Pin = 7;
int answers[5];
int yes = 0;

void setup()
{
    lcd.begin (16,2); //Initialize the LCD.
    Serial.begin(9600); //Starts the output monitor.
}

void loop()
{
    first();
    second();
    third();
    fourth();
    fifth();

    message();
}   

void first()
{
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Are you happy?");

    while (digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW) 
    {}

    if (digitalRead(button1Pin) == HIGH)
    {
        answers[0] = 1;
        delay(500);
    }

    else if (digitalRead(button2Pin) == HIGH)
    {
        answers[0] = 0;
        delay(500);
    }
}

void second()
{
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Do you drive?");

    while (digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW) 
    {}

    if (digitalRead(button1Pin) == HIGH)
    {
        answers[1] = 1;
        delay(500);
    }

    else if (digitalRead(button2Pin) == HIGH)
    {
        answers[1] = 0;
        delay(500);
    }
}


void third()
{
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Are you bald?");

    while (digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW) 
    {}

    if (digitalRead(button1Pin) == HIGH)
    {
        answers[2] = 1;
        delay(500);
    }

    else if (digitalRead(button2Pin) == HIGH)
    {
        answers[2] = 0;
        delay(500);
    }
}

void fourth()
{
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Are you old?");

    while (digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW) 
    {}

    if (digitalRead(button1Pin) == HIGH)
    {
        answers[3] = 1;
        delay(500);
    }

    else if (digitalRead(button2Pin) == HIGH)
    {
        answers[3] = 0;
        delay(500);
    }
}

void fifth()
{
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Can you fly?");

    while (digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW) 
    {}

    if (digitalRead(button1Pin) == HIGH)
    {
        answers[4] = 1;
        delay(500);
    }

    else if (digitalRead(button2Pin) == HIGH)
    {
        answers[4] = 0;
        delay(500);
    }
}

void message()
{
    yes = 0;
    for (int i = 0; i < 5; i++)
    {
        if (answers[i] == 1)
        {
            yes++;
            Serial.print(yes);
        }
    }
    
    lcd.setCursor(0,0);
    lcd.clear();

    if (yes == 1)
    {
        lcd.print("Good bye!");
    }

    else if (yes == 2)
    {
        lcd.print("Later!");
    }

    else if (yes == 3)
    {
        lcd.print("Till next time!");
    }
    
    else if (yes == 4)
    {
        lcd.print("Take it easy!");
    }
    
    else if (yes == 5)
    {
        lcd.print("Take care.");
    }
    delay(5000);
}