//Name: Alex Dorodko
//Date: 07/OCT/2020
//Purpose: This program makes the RGB LED display different colors depending on the light the photoresistor recieves.


int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0; //This will store the data from the sensor.
int blueLED = 3;
int redLED = 5;
int RGBRedLED = 9;
int RGBGreenLED = 10;
int RGBBlueLED = 11;

void setup() 
{   
    //The Setup function runs once.
    pinMode(blueLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(RGBRedLED, OUTPUT);
    pinMode(RGBBlueLED, OUTPUT);
    pinMode(RGBGreenLED, OUTPUT);
    Serial.begin(9600);
}


void loop() 

{
    //The loop function runs forever.
    data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
    data = map(data,6,679,0,100); //map the data value to a percentage
    Serial.print("Light value =");
    Serial.println(data); //Print the data to the serial port.
    
    //When it is dark, color red is displayed.
    if (data == 0)
    {
        digitalWrite(RGBRedLED, HIGH);
        delay(1000);
        digitalWrite(RGBRedLED, LOW);
    }

    //When there is some light, color blue is displayed
    else if (data > 0 && data <= 75)
    {
        digitalWrite(RGBBlueLED, HIGH);
        delay(1000);
        digitalWrite(RGBBlueLED, LOW);
    }
    
    //When the light is bright, green is displayed.
    else if (data > 75)
    {
        digitalWrite(RGBGreenLED, HIGH);
        delay(1000);
        digitalWrite(RGBGreenLED, LOW);
    }
}