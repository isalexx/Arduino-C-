int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0; //This will store the data from the sensor.

void setup() 

{ 
    //The Setup function runs once.
    Serial.begin(9600);
}
void loop() 

{   
    //The loop function runs forever.
    data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
    data = map(data,6,679,0,100); //map the data value to a percentage
    Serial.print("Light value =");
    Serial.println(data); //Print the data to the serial port.
    delay(1000); //Wait 1 second (1000mS) before running again.
}