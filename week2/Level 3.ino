//Name: Alex Dorodko
//Date: 25/SEP/2020
//Purpose: Program uses a For loop to cycle through colors 10 times.

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

for (int i = 143; i <= 1450; i += 143)
	{

  	//Display Red
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	delay(i); //Wait for 2 seconds
	digitalWrite(RGBRedPin, LOW); //Turn off Red

	//Display Green
	digitalWrite(RGBGreenPin, HIGH); //Turn on RED
	delay(i); //Wait for 2 seconds
	digitalWrite(RGBGreenPin, LOW); //Turn off Red

	//Display Blue
	digitalWrite(RGBBluePin, HIGH); //Turn on RED
	delay(i); //Wait for 2 seconds
	digitalWrite(RGBBluePin, LOW); //Turn off Red

	//Display Magenta (Red + Blue)
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	digitalWrite(RGBBluePin, HIGH); //Turn on RED
	delay(i); //Wait for 2 seconds
	digitalWrite(RGBRedPin, LOW); //Turn off Red
	digitalWrite(RGBBluePin, LOW); //Turn on RED

	//Display Yellow (Red + Green)
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	digitalWrite(RGBGreenPin, HIGH); //Turn on RED
	delay(i); //Wait for 2 seconds
	digitalWrite(RGBRedPin, LOW); //Turn off Red
	digitalWrite(RGBGreenPin, LOW); //Turn of RED

	//Display Cyan (Blue + Green)
	digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
	digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
	delay(i); //Wait for 2 seconds
	digitalWrite(RGBBluePin, LOW); //Turn of BLUE
	digitalWrite(RGBGreenPin, LOW); //Turn off GREEN

	//Display White (Red + Blue + Green)
	digitalWrite(RGBRedPin, HIGH); //Turn on RED
	digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
	digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
	delay(i); //Wait for 2 seconds
	digitalWrite(RGBRedPin, LOW); //Turn off RED
	digitalWrite(RGBBluePin, LOW); //Turn off BLUE
	digitalWrite(RGBGreenPin, LOW); //Turn off GREEN

   }
delay(1000000);



}
