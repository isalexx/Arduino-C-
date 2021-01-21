//Challenge 3
//Name: Alex Dorodko
//Date: 04/OCT/2020
//The purpose of this code is to make the RGB LED display different colors depending on where the potenciometer is pointed.


//Setting up the variables

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBBluePin = 10; //The blue RGB LED is connected pin 10 of the Arduino.
int RGBGreenPin = 11; //The green RGB LED is connected pin 11 of the Arduino.
int rotationPin = A0;  //Setting up the rotation pin.
int data=0; //This will be the data for the potenciometer.

void setup()
{
    pinMode(RGBRedPin, OUTPUT); //Setting up the RGB Red pin as output.
    pinMode(RGBBluePin, OUTPUT); //Setting up the RGB blue pin as output.
    pinMode(RGBGreenPin, OUTPUT); //Setting up the RGB green pin as output.
    pinMode(rotationPin, INPUT); //Allowing the potentiometer to input data.
    Serial.begin(9600); //This sends the data to the serial monitor.
}

void loop()
{   
    
    data = analogRead(rotationPin); //Recieve data from the rotation pin, which tells us where the potentiometer is pointed

    if (data > 0 && data <= 170)
    {
        //Red
        digitalWrite(RGBRedPin, HIGH);
        delay(500);
        digitalWrite(RGBRedPin, LOW);
        data = analogRead(rotationPin);
    }

    else if (data >= 171 && data <= 340)
    {
        //Display the color Orange (255, 10, 0)
        analogWrite(RGBRedPin, 255); 
        analogWrite(RGBGreenPin, 10); 
        analogWrite(RGBBluePin, 0);
        delay(500);
        analogWrite(RGBRedPin, 0); 
        analogWrite(RGBGreenPin, 0); 
        analogWrite(RGBBluePin, 0);
        data = analogRead(rotationPin);
    }

    else if (data >= 341 && data <= 510)
    {   
        //Display Yellow (Red + Green)
	    digitalWrite(RGBRedPin, HIGH);
	    digitalWrite(RGBGreenPin, HIGH);
	    delay(500);
	    digitalWrite(RGBRedPin, LOW);
	    digitalWrite(RGBGreenPin, LOW);
        data = analogRead(rotationPin);
    }

    else if (data >= 511 && data <= 680)
    {
        //Display Green
	    digitalWrite(RGBGreenPin, HIGH); //Turn on RED
	    delay(500); //Wait for 2 seconds
	    digitalWrite(RGBGreenPin, LOW); //Turn off Red
        data = analogRead(rotationPin);
    }

    else if (data >= 681 && data <= 850)
    {
        //Display Blue
	    digitalWrite(RGBBluePin, HIGH); //Turn on RED
	    delay(500); //Wait for 2 seconds
	    digitalWrite(RGBBluePin, LOW); //Turn off Red
        data = analogRead(rotationPin);
    }

    else if (data >= 850 && data <= 1023)
    {   
        //Displaying purple
        analogWrite(RGBRedPin, 255); 
        analogWrite(RGBGreenPin, 0); 
        analogWrite(RGBBluePin, 50);
        delay(500);
        analogWrite(RGBRedPin, 0); 
        analogWrite(RGBGreenPin, 0); 
        analogWrite(RGBBluePin, 0);
        data = analogRead(rotationPin);
    }
}   