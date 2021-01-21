//Button pins
int button1Pin = 8;
int button2Pin = 9;
int button3Pin = 10;
int button4Pin = 11;

//Red Pins
int RGB1RedPin = 2; // 1
int RGB2RedPin = 3; // 2
int RGB3RedPin = 4; // 3
int RGB4RedPin = 5; // 4

//Green pins
int RGB1GreenPin = 6; // 1
int RGB2GreenPin = 7; // 2
int RGB3GreenPin = 13; // 3
int RGB4GreenPin = 12; // 4

//Misc.
int yellowDelay = 2000;
int greenDelay = 1500;
int buttonLag = 5000;

int circle = 0;
int flag = 0;

void setup()
{
    pinMode(RGB1RedPin, OUTPUT);
    pinMode(RGB2RedPin, OUTPUT);
    pinMode(RGB3RedPin, OUTPUT);
    pinMode(RGB4RedPin, OUTPUT);
    pinMode(RGB1GreenPin, OUTPUT);
    pinMode(RGB2GreenPin, OUTPUT);
    pinMode(RGB3GreenPin, OUTPUT);
    pinMode(RGB4GreenPin, OUTPUT);
    Serial.begin(9600);
    horizontalGo();
}

void loop()
{

    rotation();

    if (flag == 0)
    {
        //If top right or bottom left buttons is pressed, this code executes
        if (digitalRead(button1Pin) == HIGH || digitalRead(button4Pin) == HIGH)
        {
          	flag = 1;
          	circle = 0;
          	Serial.println(flag);
            verticalGo();
        }
    }
    
    else if (flag == 1)
    {
        //If top left or bottom right buttons is pressed, this code executes
        if (digitalRead(button2Pin) == HIGH || digitalRead(button3Pin) == HIGH)
        {
          	flag = 0;
          	circle = 0;
          	Serial.println(flag);
            horizontalGo();
        }
    }
    
}

//Setting up the colors for the north and south lights

void horizontalRed()
{
    digitalWrite(RGB2GreenPin, LOW);
    digitalWrite(RGB2RedPin, HIGH);

    digitalWrite(RGB4GreenPin, LOW);
    digitalWrite(RGB4RedPin, HIGH);
}

void horizontalYellow()
{
    digitalWrite(RGB2GreenPin, HIGH);
    digitalWrite(RGB2RedPin, HIGH);

    digitalWrite(RGB4GreenPin, HIGH);
    digitalWrite(RGB4RedPin, HIGH);
}

void horizontalGreen()
{
    digitalWrite(RGB2GreenPin, HIGH);
    digitalWrite(RGB2RedPin, LOW);

    digitalWrite(RGB4GreenPin, HIGH);
    digitalWrite(RGB4RedPin, LOW);
}


//Setting up the colors for the west and east lights.

void verticalRed()
{
    digitalWrite(RGB1GreenPin, LOW);
    digitalWrite(RGB1RedPin, HIGH);

    digitalWrite(RGB3GreenPin, LOW);
    digitalWrite(RGB3RedPin, HIGH);
}

void verticalYellow()
{
    analogWrite(RGB1GreenPin, 255);
    analogWrite(RGB1RedPin, 255);

    analogWrite(RGB3GreenPin, 255);
    analogWrite(RGB3RedPin, 255);
}

void verticalGreen()
{
    digitalWrite(RGB1GreenPin, HIGH);
    digitalWrite(RGB1RedPin, LOW);

    digitalWrite(RGB3GreenPin, HIGH);
    digitalWrite(RGB3RedPin, LOW);
}

void horizontalGo()
{
    //Light from previous state
        verticalGreen();
        horizontalRed();

        delay(buttonLag);

        //Lights turning yellow, then red from the previous
        verticalYellow();

        delay(yellowDelay);

        //Main light for walking
        verticalRed();

        //Give a bit of time for those running the red light
        delay(greenDelay);

        horizontalGreen();
}

void verticalGo()
{
    //Light from previous state goes on for another 5 seconds
        verticalRed();
        horizontalGreen();

        delay(buttonLag);

        //Yellow flashes for 2 seconds
        horizontalYellow();

        delay(yellowDelay);

        //You can now cross
        horizontalRed();

        //Give a bit of time for those running the red light
        delay(greenDelay);

        verticalGreen();
        
}

void rotation()
{
    circle += 1;
    Serial.println(circle);
  	Serial.println(flag);

    if (circle > 250)
    {
        if (flag == 0)
        {
          	flag = 1;
          	Serial.println(flag);
            verticalGo();
            
        }
        
        else if (flag == 1)
        {	
          	flag = 0;
          	Serial.println(flag);
            horizontalGo();
            
        }
        circle = 0;
    }  
}