//Name: Alex Dorodko
//Date: 26/OCT/2020
//Purpose: This program lets you change colors of each induvidual LED color by using buttons

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 11; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 10; //The blue RGB LED is connected pin 11 of the Arduino.
int fadeDelay = 5; //This is the number of milliseconds that it will take between steps
int button2Pin = 3;
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
    pinMode(button2Pin, INPUT);
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
        if (digitalRead(button2Pin) == HIGH)
        {
            red = red + 51;
            delay(300);

            if (red > 255)
            {
                red = 0;
            }
        }

        analogWrite(RGBRedPin, red);
        delay(fadeDelay);
    }

    else if (flag == 1)
    {
        if (digitalRead(button2Pin) == HIGH)
        {
            green = green + 51;
            delay(300);

            if (green > 255)
            {
                green = 0;
            }
        }

        analogWrite(RGBGreenPin, green);
        delay(fadeDelay);
    } 

    else if (flag == 2)
    {
        if (digitalRead(button2Pin) == HIGH)
        {
            blue = blue + 51;
            delay(300);

            if (blue > 255)
            {
                blue = 0;
            }
        }

        analogWrite(RGBBluePin, blue);
        delay(fadeDelay);
    } 
}