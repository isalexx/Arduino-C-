//Name: Alex Dorodko
//Date: 25/SEP/2020
//Purpose: Shows a "lightshow", which flashes 3 flag's colors  which correspond to my culture. The flags flash fasster and faster. The program uses a for loop to be more efficient.

int RGBGreenPin = 9; //The green RGB LED is connected pin 9 of the Arduino.
int RGBBluePin = 10; //The blue RGB LED is connected pin 10 of the Arduino.
int RGBRedPin = 11; //The red RGB LED is connected pin 11 of the Arduino.

void setup()
{
//The Setup function runs once.
pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
}

void loop()
{

for (int i = 750; i >= 0; i -= 250)
	{

  	//Canadian Flag
    //Display Red
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	delay(i); //Wait
	digitalWrite(RGBRedPin, LOW); //Turn off Red

  	//Display White (Red + Blue + Green)
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
	digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
	delay(i); //Wait
	digitalWrite(RGBRedPin, LOW); //Turn off RED
	digitalWrite(RGBBluePin, LOW); //Turn off BLUE
	digitalWrite(RGBGreenPin, LOW); //Turn off GREEN

  	//Display Red
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	delay(i); //Wait
	digitalWrite(RGBRedPin, LOW); //Turn off Red


  	delay(500);// delay to wait between flags


  	//Ukrainian Flag
  	//Display Blue
	digitalWrite(RGBBluePin, HIGH); //Turn on RED
	delay(i); //Wait
	digitalWrite(RGBBluePin, LOW); //Turn off Red

  	//Display Yellow (Red + Green)
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	digitalWrite(RGBGreenPin, HIGH); //Turn on RED
	delay(i); //Wait
	digitalWrite(RGBRedPin, LOW); //Turn off Red
	digitalWrite(RGBGreenPin, LOW); //Turn of RED

	delay(500);// delay to wait between flags

  	//Russian Flag
  	//Display White (Red + Blue + Green)
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
	digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
	delay(i); //Wait
	digitalWrite(RGBRedPin, LOW); //Turn off RED
	digitalWrite(RGBBluePin, LOW); //Turn off BLUE
	digitalWrite(RGBGreenPin, LOW); //Turn off GREEN

  	//Display Red
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	delay(i); //Wait
	digitalWrite(RGBRedPin, LOW); //Turn off Red

	//Display Blue
	digitalWrite(RGBBluePin, HIGH); //Turn on RED
	delay(i); //Wait
	digitalWrite(RGBBluePin, LOW); //Turn off Red

  	delay(500);// delay to wait between flags
   }
delay(1000000);



}
