//Name: Alex Dorodko
//Date: 16/SEP/2020
//Purpose: The program has two LEDs, one red, one blue, and is meant to flash like a police siren, one after another.

//Enabling pin 13 & 12 on the arduino.
int blueLED = 13;
int redLED = 12;
void setup()
{
//Making sure that both LEDs get power with OUTPUT.
pinMode(blueLED, OUTPUT);
pinMode(redLED, OUTPUT);
}
void loop()
{

//Turning on and off the blue LED. Chose a delay of 0.2 seconds, which seems like a good paste.
digitalWrite(blueLED, HIGH);
delay(200);

digitalWrite(blueLED, LOW);
delay(200);


//Turning on and off the red LED. Same delay as the blue one.
digitalWrite(redLED, HIGH);
delay(200);

digitalWrite(redLED, LOW);
delay(200);

}
