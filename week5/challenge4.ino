//Name: Alex Doorodko
//Date: 15/OCT/2020
//Purpose: 

int blueLedPin = 13 ; //The blue LED is connected pin 13 of the Arduino.
int redLedPin = 12;
int greenLedPin = 4;
int button1Pin = 2; //The SW1 button is connect to pin 2 of the Arduino.
int button2Pin = 3;
int RGBRedPin = 9;
int RGBBluePin = 10;
int RGBGreenPin = 11;
int flag = 0;
bool on;
bool RGBOn;


void setup() 
{ 
    //The Setup function runs once
    pinMode(blueLedPin, OUTPUT); //Setup blue LED pin as an output pin.
    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(button1Pin, INPUT); //Setup button1 pin as an input pin.
    pinMode(button2Pin, INPUT);
    pinMode(RGBRedPin, OUTPUT);
    pinMode(RGBBluePin, OUTPUT);
    pinMode(RGBGreenPin, OUTPUT);
}

void loop() 
{   
    if (digitalRead(button1Pin) == HIGH)
    {
        bool on = true;

        while (on == true)
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
                    flag = 0;
                    delay(300);
                }
            }  

            if (flag == 0)
            {	
      	        digitalWrite(redLedPin, LOW);
                digitalWrite(greenLedPin, HIGH);
                delay(300);
            }

            else if (flag == 1)
            {
      	        digitalWrite(greenLedPin, LOW);
                digitalWrite(redLedPin, HIGH);
                delay(300);
            } 
            
            if (flag == 0 && digitalRead(button2Pin) == HIGH)
            {
                RGBOn = true;
                while (RGBOn == true)
                {
                    //Blue
                    digitalWrite(RGBBluePin, HIGH);
                    delay(500); //Uses the potenciometer data as the delay
                    digitalWrite(RGBBluePin, LOW);

                    if (digitalRead(button1Pin) == HIGH)
                    {
                        if (flag == 0)
                        {
                            flag = 1;
                            RGBOn = false;
                            delay(300); 
                        }

                        else if(flag == 1)
                        {
                            flag = 0;
                            RGBOn = false;
                            delay(300);
                        }
                      	break;
                    }

                    if (digitalRead(button2Pin) == HIGH)
                    {
                        break;
                    }

                    //Red
                    digitalWrite(RGBRedPin, HIGH);
                    delay(500);
                    digitalWrite(RGBRedPin, LOW);
                  
                  	if (digitalRead(button1Pin) == HIGH)
                    {
                        if (flag == 0)
                        {
                            flag = 1;
                            RGBOn = false;
                            delay(300);
                            
                        }

                        else if(flag == 1)
                        {
                            flag = 0;
                            RGBOn = false;
                            delay(300);
                            
                        }
                      	break;
                    }

                    if (digitalRead(button2Pin) == HIGH)
                    {
                        break;
                    }

                    //Green
                    digitalWrite(RGBGreenPin, HIGH);
                    delay(500);
                    digitalWrite(RGBGreenPin, LOW);
                  
                  	if (digitalRead(button1Pin) == HIGH)
                    {
                        if (flag == 0)
                        {
                            flag = 1;
                            RGBOn = false;
                            delay(300);
                            
                        }

                        else if(flag == 1)
                        {
                            flag = 0;
                            RGBOn = false;
                            delay(300);
                            
                        }
                      	break;
                    }

                    if (digitalRead(button2Pin) == HIGH)
                    {
                        break;
                    }
                }
            }
        }
    }
}