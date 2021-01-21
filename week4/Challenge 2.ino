//Name: Alex Dorodko
//Date: 07/OCT/2020
//Purpose: this program makes the LEDs flash when the light sensor detecitcs no light.nt lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.


int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0; //This will store the data from the sensor.
int blueLED = 3;
int redLED = 5;

void setup() 
{   
    //The Setup function runs once.
    pinMode(blueLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    Serial.begin(9600);
}


void loop() 

{
    //The loop function runs forever.
    data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
    data = map(data,6,679,0,100); //map the data value to a percentage
    Serial.print("Light value =");
    Serial.println(data); //Print the data to the serial port.
  
    if (data == 0)
    {
        digitalWrite(redLED, HIGH);
        digitalWrite(blueLED, HIGH);
        delay(1000);
        digitalWrite(redLED, LOW);
        digitalWrite(blueLED, LOW);
    }

}