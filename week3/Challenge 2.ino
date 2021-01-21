//Challenge 2
//Name: Alex Dorodko
//Date: 04/OCT/2020
//The purpose of this code is to make the LEDs flash at different speeds as you turn the potentiometer.

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
    data = analogRead(rotationPin); //Reads the data and stores it under data.

    //Blue
    digitalWrite(RGBBluePin, HIGH); //turning on the blue RGB light.
    delay(data); //Uses the potenciometer data as the delay
    digitalWrite(RGBBluePin, LOW);

    data = analogRead(rotationPin); //Reads the data and stores it under data.
    
    //Red
    digitalWrite(RGBRedPin, HIGH);
    delay(data);
    digitalWrite(RGBRedPin, LOW);

    data = analogRead(rotationPin); //Reads the data and stores it under data.

    //Green
    digitalWrite(RGBGreenPin, HIGH);
    delay(data);
    digitalWrite(RGBGreenPin, LOW);
    
}   