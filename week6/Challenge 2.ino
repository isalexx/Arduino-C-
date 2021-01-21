//Name: Alex Dorodko
//Date: 26/OCT/2020
//Purpose: Changes green LED brightness

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 11; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 10; //The blue RGB LED is connected pin 11 of the Arduino.
int fadeDelay = 5; //This is the number of milliseconds that it will take between steps
int rotationPin = A0;
int green = 0;

void setup() 
{
    pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
    pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
    pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
    pinMode(rotationPin, INPUT);
}

void loop()
{
    green = analogRead(rotationPin);
    green = map(green,0,1023,0,255);
    analogWrite(RGBGreenPin, green);
    delay(fadeDelay);
}
