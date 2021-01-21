//Name: Alex Dorodko
//Date: 04/DEC/2020
//Purpose: This program rotates the rotor depending on which button you press

#include <Servo.h>
Servo myservo;
int val;

int degrees = 0;

int button1Pin = 2; 
int button2Pin = 3;

void setup()
{
  myservo.attach(4);
  Serial.begin(9600);
  myservo.write(0);
}

void loop()
{
    if (digitalRead(button1Pin) == HIGH && degrees < 180)
    {
        degrees += 45;
        myservo.write(degrees);
        delay(1500);
    }

    else if (digitalRead(button2Pin) == HIGH && degrees > 0)
    {
        degrees -= 45;
        myservo.write(degrees);
        delay(1500);
    }
}

