//Challenge 4
//Name: Alex Dorodko
//Date: 04/OCT/2020
//The purpose of this code is to take in the user input, and make the LED flash the colors in a sequence which the user inputs.

//Setting up the variables

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBBluePin = 10; //The blue RGB LED is connected pin 10 of the Arduino.
int RGBGreenPin = 11; //The green RGB LED is connected pin 11 of the Arduino.

void setup()
{
    pinMode(RGBRedPin, OUTPUT); //Setting up the RGB Red pin as output.
    pinMode(RGBBluePin, OUTPUT); //Setting up the RGB blue pin as output.
    pinMode(RGBGreenPin, OUTPUT); //Setting up the RGB green pin as output.
    Serial.begin(9600); //This sends the data to the serial monitor.
    Serial.print("Please enter the colors which you would like to see (R/G/B): ");
}

void loop()
{    
  
  	//Reading the user input
  	int color = Serial.read();
	
  	//If the input is R, display red color
    if (color == 82)

    {
        digitalWrite(RGBRedPin, HIGH);
        delay(500);
        digitalWrite(RGBRedPin, LOW);
    }

  	//If the input is G, display green color
    else if (color == 71)
    {
        digitalWrite(RGBGreenPin, HIGH);
        delay(500);
        digitalWrite(RGBGreenPin, LOW);
    }


 	//If the input is B, display blue color
    else if (color == 66)
    {
        digitalWrite(RGBBluePin, HIGH);
        delay(500); 
        digitalWrite(RGBBluePin, LOW);
    }
}