//Name: Alex Dorodko
//Date: 08/NOV/2020
//Purpose: 5 buttons, 4 of which turn off/on LED, and one makes them flash three times.

#include <IRremote.h> //including infrared remote header file
int RECV_PIN = 3; // the pin where you connect the output pin of IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results;
int blueLed = 6;
int redLed = 5;
int value = 0;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop()
{
    if (irrecv.decode(&results)) 
    {
        value = results.value;
        Serial.println(" ");
        Serial.print("Code: ");
        Serial.println(value); //prints the value a a button press
        Serial.println(" ");
        irrecv.resume(); // Receive the next value
        Serial.println("*****************");

        //Turning on blue LED with 1
        if(value == 2295)
        {
            digitalWrite(blueLed, HIGH);
            delay(500);
        }

        //turning off blue LED with 3
        else if (value == 18615)
        {
            digitalWrite(blueLed, LOW);
            delay(500);
        }
        
        //Turning on red LED with 4
        else if (value == 10455)
        {
            digitalWrite(redLed, HIGH);
            delay(500);
        }
        
        //Turning off red LED with 6
        else if (value == 26775)
        {
            digitalWrite(redLed, LOW);
            delay(500);
        }

        //Making both LEDs flash two times with middle play button
        else if (value == -24481)
        {
            //Make sure it is off
            digitalWrite(blueLed, LOW);
            digitalWrite(redLed, LOW);

            for (int i = 0; i < 3; i++)
            {
                digitalWrite(blueLed, LOW);
                digitalWrite(redLed, LOW);
                delay(1000);
                digitalWrite(blueLed, HIGH);
                digitalWrite(redLed, HIGH);
            }
            
            //Make sure it is off after the flashing
            digitalWrite(blueLed, LOW);
            digitalWrite(redLed, LOW);
        }
    }
}