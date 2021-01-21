//Name: Alex Dorodko
//Date: 04/DEC/2020
//Purpose: This program rotates the rotor depending on which button you press, and displays a color depending how many degrees the rotor is rotated.

#include <Servo.h>
Servo myservo;
int val;

int degrees = 0;

int button1Pin = 2; 
int button2Pin = 3;

int RGBRedPin = 11;
int RGBGreenPin = 9;
int RGBBluePin = 10;

int redColors[] = {255, 255, 255, 0, 0};
int greenColors[] = {0, 255, 255, 255, 0};
int blueColors[] = {0, 0, 255, 255, 255};


void setup()
{
    myservo.attach(4);
    Serial.begin(9600);
    myservo.write(0);
    pinMode(RGBRedPin, OUTPUT);
    pinMode(RGBBluePin, OUTPUT);
    pinMode(RGBGreenPin, OUTPUT);
}

void loop()
{

    //If button 1 is pressed, go +45 degrees.
    if (digitalRead(button1Pin) == HIGH)
    {
        degrees += 45;
        myservo.write(degrees);
        delay(500);
		
      	Serial.println(degrees);
      
        //Output a different color depending on the degree
        color(degrees);

        //If it is pressed again when maxed out, go back to 0 degrees and output each color.
        if (degrees > 180)
        {
            for (int i = 0; i < 5; i++)
            {
                degrees -= 45;
                myservo.write(degrees);

                analogWrite(RGBRedPin, redColors[i]);
                analogWrite(RGBGreenPin, greenColors[i]);
                analogWrite(RGBBluePin, blueColors[i]);
                
                delay(500);
              
              	Serial.println(degrees);
            }
        }
        

    }

    //If button 2 is pressed, go -45 degrees.
    else if (digitalRead(button2Pin) == HIGH)
    {
        degrees -= 45;
        myservo.write(degrees);
        delay(500);
      
      	Serial.println(degrees);

        //Output a color
        color(degrees);
      
        //If it is pressed while its at 0, it will go to 180 and output the colors.
      	if (0 > degrees)
        {
            for (int i = 0; i < 5; i++)
            {
                degrees += 45;
                myservo.write(degrees);

                analogWrite(RGBRedPin, redColors[i]);
                analogWrite(RGBGreenPin, greenColors[i]);
                analogWrite(RGBBluePin, blueColors[i]);
                
                delay(500);
              
              	Serial.println(degrees);
            }
        }
    }
}

//Function to output color based on degree.
void color(int degrees)
{
    switch (degrees)
        {
        case 0:
            digitalWrite(RGBRedPin, HIGH);
            digitalWrite(RGBGreenPin, LOW);
            digitalWrite(RGBBluePin, LOW);
            break;

        case 45:
            digitalWrite(RGBRedPin, HIGH);
            digitalWrite(RGBGreenPin, HIGH);
            digitalWrite(RGBBluePin, LOW);
            break;

        case 90:
            digitalWrite(RGBRedPin, HIGH);
            digitalWrite(RGBGreenPin, HIGH);
            digitalWrite(RGBBluePin, HIGH);
            break;

        case 135:
            digitalWrite(RGBRedPin, LOW);
            digitalWrite(RGBGreenPin, HIGH);
            digitalWrite(RGBBluePin, HIGH);
            break;

        case 180:
            digitalWrite(RGBRedPin, LOW);
            digitalWrite(RGBGreenPin, LOW);
            digitalWrite(RGBBluePin, HIGH);
            break;

        default:
            break;
        }
}