//Name: Alex Dorodko
//Date: 07/OCT/2020
//Purpose: This program makes different LEDs flash depending on the binary values.

//Setting up all the variables for the LEDs, and the photoresistor.

int lightPin = A1; 
int data = 0; 
int redLED2 = 2;
int blueLED2 = 6;
int orangeLED = 7;
int greenLED = 8;
int blueLED = 3;
int redLED = 5;
int RGBRedLED = 9;
int RGBGreenLED = 10;
int RGBBlueLED = 11;

void setup() 
{   
    pinMode(blueLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(blueLED2, OUTPUT);
    pinMode(redLED2, OUTPUT);
    pinMode(RGBRedLED, OUTPUT);
    pinMode(RGBBlueLED, OUTPUT);
    pinMode(RGBGreenLED, OUTPUT);
  	pinMode(lightPin, INPUT);
    Serial.begin(9600);
}

void loop() 
{
    //The loop function runs forever.
    data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
    data = map(data,6,679,0,15); //map the data value to a percentage
    Serial.print("Light value =");
	Serial.println(data); //Print the data to the serial port.
  	
  	//Reading the bit placements of the photoresistor values.
	int one = bitRead(data,0);
  	int two = bitRead(data,1);
  	int four = bitRead(data,2);
	int eight = bitRead(data,3);
	
  	//Making the lights turn on depending if the decimal placement is 1 or 0
    digitalWrite(redLED2, eight);
  	digitalWrite(blueLED2, four);
  	digitalWrite(orangeLED, two);
  	digitalWrite(greenLED, one); 
}