//Name: Alex Dorodko
//Date: 08/NOV/2020
//Purpose: This program stores one song, and plays it using the array.


int buzzerPin = 5 ; //The buzzerPin is connected to pin 5 of the Arduino.
int button1Pin = 3; //The SW1 button is connect to pin 2 of the Arduino.
int RGBBluePin = 11; // RGB Pins
int RGBRedPin = 10;
int RGBGreenPin = 9;

//The notes for the Starwars theme was found on this website, the code however, is my own. https://gist.github.com/nicksort/4736535
int starWarsFreq[] = {440, 440, 440, 349, 523, 440, 349, 523, 440, 0 , 659, 659, 659, 698, 523, 415, 349, 523, 440};
int starWarsDelays[] = {500, 500, 500, 350, 150, 500, 350, 150, 650, 250, 500, 500, 500, 350, 150, 500, 350, 150, 650};

void setup() 
{
    pinMode(buzzerPin, OUTPUT); //Setup red LED pin as an output pin.
    pinMode(button1Pin, INPUT); //Setup button1 pin as an input pin.
}

void loop() 
{
	if (digitalRead(button1Pin) == HIGH)
    { //Check to see if button1 is pressed.
        for (int i = 0; i < (sizeof(starWarsFreq) / sizeof(starWarsFreq[0])); i++)
        {   
            //Go through each of the array indexes and play the frequency.
            tone(buzzerPin, starWarsFreq[i],starWarsDelays[i]);
		    delay(starWarsDelays[i]);

            analogWrite(RGBBluePin, random(0, 255));
            analogWrite(RGBRedPin, random(0, 255));
            analogWrite(RGBGreenPin, random(0, 255));
        }
	}
}