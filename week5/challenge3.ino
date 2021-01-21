//Name: Alex Doorodko
//Date: 15/OCT/2020
//Purpose: 

int blueLedPin = 13 ; //The blue LED is connected pin 13 of the Arduino.
int redLedPin = 12;
int button1Pin = 2; //The SW1 button is connect to pin 2 of the Arduino.
int button2Pin = 3;
int RGBRedPin = 9;
int RGBBluePin = 10;
int RGBGreenPin = 11;
bool on = false;

void setup() 
{ 
    //The Setup function runs once
    pinMode(blueLedPin, OUTPUT); //Setup blue LED pin as an output pin.
    pinMode(redLedPin, OUTPUT);
    pinMode(button1Pin, INPUT); //Setup button1 pin as an input pin.
    pinMode(button2Pin, INPUT);
    pinMode(RGBRedPin, OUTPUT);
    pinMode(RGBBluePin, OUTPUT);
    pinMode(RGBGreenPin, OUTPUT);
}

void loop() 
{ 
  	//The loop function runs forever.


    //if 1st button is pressed, LED starts cycling
	if (digitalRead(button1Pin) == HIGH)
	{ 
      	on = true;
        
        //if it is still true, the light will keep cycling
      	while(on = true)
        {
            digitalWrite(RGBRedPin, 1);
            delay(500);
            digitalWrite(RGBRedPin, 0);

            //If the 2nd button is pressed, the light will not flash any longer
            if (digitalRead(button2Pin) == HIGH)
            {
                on = false;
                break;
            }

            digitalWrite(RGBGreenPin, 1);
            delay(500);
            digitalWrite(RGBGreenPin, 0);

            //If the 2nd button is pressed, the light will not flash any longer
            if (digitalRead(button2Pin) == HIGH)
            {
                on = false;
                break;
            }

            digitalWrite(RGBBluePin, 1);
            delay(500);
            digitalWrite(RGBBluePin, 0);

            //If the 2nd button is pressed, the light will not flash any longer
            if (digitalRead(button2Pin) == HIGH)
            {
                on = false;
                break;
            }
        }
	} 
}