//Name: Alex Dorodko
//Date: 26/OCT/2020
//Purpose: This program allows the user to use the potenciometer to switch colors on LEDs

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 11; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 10; //The blue RGB LED is connected pin 11 of the Arduino.
int fadeDelay = 5; //This is the number of milliseconds that it will take between steps
int rotationPin = A0;
int button1Pin = 2;
int flag = 0;
int blue = 0;
int green = 0;
int red = 0;

void setup() 
{
    pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
    pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
    pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
    pinMode(rotationPin, INPUT);
    pinMode(button1Pin, INPUT);
  	Serial.begin(9600);
}

void loop()
{
    if (digitalRead(button1Pin) == HIGH)
        {
            if (flag == 0)
            {
                flag = 1;
                delay(300);
              	Serial.print(flag);
            }
            else if (flag == 1)
            {
                flag = 2;
                delay(300);
              	Serial.print(flag);
            }
            else if (flag == 2)
            {
                flag = 0;
                delay(300);
              	Serial.print(flag);
            }
        }  

    if (flag == 0)
    {	
        red = analogRead(rotationPin);
        red = map(red,0,1023,0,255);
        analogWrite(RGBRedPin, red);
        delay(fadeDelay);
    }

    else if (flag == 1)
    {
        green = analogRead(rotationPin);
        green = map(green,0,1023,0,255);
        analogWrite(RGBGreenPin, green);
        delay(fadeDelay);
    } 

    else if (flag == 2)
    {
        blue = analogRead(rotationPin);
        blue = map(blue,0,1023,0,255);
        analogWrite(RGBBluePin, blue);
        delay(fadeDelay);
    } 
}