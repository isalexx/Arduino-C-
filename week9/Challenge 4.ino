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
    pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
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

        if (value == -24481)
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
        if (flag == 1)
        {
            if (value == 2295)
            {
                modeOne();
            }

            else if (value == -30601)
            {
                modeTwo();
            }

            else if (value == 18615)
            {
                modeThree();
            }
        }

        else if(flag == 0)
        {
            digitalWrite(redLED, LOW);
            digitalWrite(blueLED, LOW);
        }

        Serial.println(value);
    }
}

void modeOne()
{
    for (int i = 0; i < 25; i++)
    {
        digitalWrite(redLED, HIGH);
        delay(50);
        digitalWrite(redLED, LOW);
    
        delay(50);

        digitalWrite(blueLED, HIGH);
        delay(50);
        digitalWrite(blueLED, LOW);
    }
    
}

void modeTwo()
{
    for (int i = 0; i < 25; i++)
    {
        digitalWrite(redLED, HIGH);
        delay(100);
        digitalWrite(redLED, LOW);
        
        delay(100);

        digitalWrite(blueLED, HIGH);
        delay(100);
        digitalWrite(blueLED, LOW);
    }
}

void modeThree()
{
    for (int i = 0; i < 25; i++)
    {
        digitalWrite(redLED, HIGH);
        delay(250);
        digitalWrite(redLED, LOW);
        
        delay(250);

        digitalWrite(blueLED, HIGH);
        delay(250);
        digitalWrite(blueLED, LOW);
    }
}


