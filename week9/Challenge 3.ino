//Name: Alex Dorodko
//Date: 08/NOV/2020
//Purpose: this is a program which turns up the brightness between 

#include <IRremote.h> //including infrared remote header file
int RECV_PIN = 3; // the pin where you connect the output pin of IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results;

//LEDs
int blueLED = 6;
int redLED = 5;

//RGB LED
int RGBRedPin = 11; 
int RGBGreenPin = 9; 
int RGBBluePin = 10;

int value = 0;
int flag = 0;

int brightness = 0;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();
    pinMode(RGBGreenPin, OUTPUT); //Setup red RGB LED pin as an output pin.
    pinMode(RGBRedPin, OUTPUT); //Setup green RGB LED pin as an output pin.
    pinMode(RGBBluePin, OUTPUT); //Setup green RGB LED pin as an output pin.
    pinMode(blueLED, OUTPUT); //Setup blue RGB LED pin as an output pin.
    pinMode(redLED, OUTPUT); //Setup red RGB LED pin as an output pin.
}

void loop()
{
    if (irrecv.decode(&results)) 
    {
        value = results.value;
        Serial.println(" ");
        Serial.print("Code: ");
        Serial.println(value); //prints the value a a button press
        Serial.println(" ");
        irrecv.resume(); // Receive the next value
        Serial.println("*****************");

        //Rotating between both LEDs
        if (value == -22441)
        {
            if (flag == 0)
            {
                flag = 1;
                delay(5);
              	Serial.print(flag);
            }
            else if (flag == 1)
            {
                flag = 0;
                delay(5);
              	Serial.print(flag);
            }
        }

        //Blue
        if (flag == 0)
        {
            if(value == 2295 && brightness < 255)
            {
                brightness = brightness + 51;
                delay(5);
            }

            else if (value == -30601 && 0 < brightness)
            {
                brightness = brightness - 51;
                delay(5);
            }

            analogWrite(RGBRedPin, 0);
            analogWrite(RGBGreenPin, 0);
            analogWrite(RGBBluePin, brightness);
            Serial.println(brightness);
        }

        //Green
        else if (flag == 1)
        {
            if(value == 2295 && brightness < 255)
            {
                brightness = brightness + 51;
                delay(5);
            }

            else if (value == -30601 && 0 < brightness)
            {
                brightness = brightness - 51;
                delay(5);
            }

            analogWrite(RGBRedPin, 0);
            analogWrite(RGBBluePin, 0);
            analogWrite(RGBGreenPin, brightness);
            Serial.println(brightness);
        }
    }
}