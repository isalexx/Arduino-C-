//Name: Alex Dorodko
//Date: 16/SEP/2020
//Purpose: The program is designed to flash initials of a person using morse code, with the LED. The current initials being flashed are AD.

//Enabling pin 13 on the arduino.
int blueLED = 13;
void setup()
{
pinMode(blueLED, OUTPUT);
}
void loop()
{


//turning on the blue LED at a bright setting, for 100ms to reprisent a dot.
digitalWrite(blueLED, HIGH);
delay(100);

//turning off the LED, in order to have the light reprisent a dash after.
digitalWrite(blueLED, LOW);
delay(1000);

//turning on the blue LED at a bright setting, for 1000ms to reprisent a dash.
digitalWrite(blueLED, HIGH);
delay(1000);

//turning off the LED for 2 second to indicate that letter is done.
digitalWrite(blueLED, LOW);
delay(2000);

//--------------------------------------------------------------

//turning on the blue LED at a bright setting, for 1000s to reprisent a dash
digitalWrite(blueLED, HIGH);
delay(1000);

//turning off the LED, in order to have the light reprisent a dot after.
digitalWrite(blueLED, LOW);
delay(1000);

//turning on the blue LED at a bright setting, for 100ms to reprisent a dot.
digitalWrite(blueLED, HIGH);
delay(100);

//turning on the blue LED at a bright setting, for 100ms to reprisent a dot.
digitalWrite(blueLED, LOW);
delay(1000);

//turning on the blue LED at a bright setting, for 100ms to reprisent a dot.
digitalWrite(blueLED, HIGH);
delay(100);

//turning on the blue LED at a bright setting, for 100ms to reprisent a dot.
digitalWrite(blueLED, LOW);
delay(100000);

}
