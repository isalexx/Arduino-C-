//Name: Alex Dorodko
//Date: 08/NOV/2020
//Purpose: This program stores three songs, and plays the one you wish.

int buzzerPin = 5 ; //The buzzerPin is connected to pin 5 of the Arduino.
int button1Pin = 3; //The SW1 button is connect to pin 2 of the Arduino.
int RGBBluePin = 11; // 
int RGBRedPin = 10;
int RGBGreenPin = 9;

//The notes for the Starwars theme was found on this website, the code however, is my own. https://gist.github.com/nicksort/4736535
int starWarsFreq[] = {440, 440, 440, 349, 523, 440, 349, 523, 440, 0 , 659, 659, 659, 698, 523, 415, 349, 523, 440};
int starWarsDelays[] = {500, 500, 500, 350, 150, 500, 350, 150, 650, 250, 500, 500, 500, 350, 150, 500, 350, 150, 650};

//The notes for the mario bros theme was found on this website https://www.instructables.com/Arduino-Mario-Bros-Theme-Song/ 
int marioBrothersFreq[] = {2637, 2637, 0, 2637, 0, 2093, 2637, 0, 3136, 0, 0,  0, 1568, 0, 0, 0,2093, 0, 0, 1568,0, 0, 1319, 0,0, 1760, 0, 1976,0, 1865, 1760, 0,1568, 2637, 3136, 3520, 0, 2794, 3136, 0, 2637, 0, 2093, 2349, 1976, 0, 0, 2093, 0, 0, 1568, 0, 0, 1319, 0, 0, 1760, 0, 1976, 0, 1865, 1760, 0, 1568, 2637, 3136, 3520, 0, 2794, 3136, 0, 2637, 0, 2093, 2349, 1976, 0, 0};
int marioBrothersDelays[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 140, 140, 140, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 140, 140, 140, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};


//The notes for the soviet union anthem was found on this website https://github.com/Aorda/USSR-Anthem-with-Arduino-Piezo-Buzzer/blob/master/sovietanthem.ino
int sovietAnthemFreq[] = {392, 523, 392, 440, 494, 330, 330, 440, 392, 349, 392, 262, 262, 294, 294, 330, 349, 349, 392, 440, 494, 523, 587};

int sovietAnthemDelays[] = {250, 500, 333, 125, 500, 250, 250, 500, 333, 125, 500, 250, 250, 500, 250, 250, 500, 250, 250, 500, 250, 250, 500};

void setup() 
{
    pinMode(buzzerPin, OUTPUT); //Setup red LED pin as an output pin.
    pinMode(button1Pin, INPUT); //Setup button1 pin as an input pin.
    Serial.begin(9600); //Starts the output monitor.
    Serial.print("\nThere are three songs stored in the library. Choose which one you would like to play:\n1 - Star Wars Theme\n2 - Mario Bros Theme\n3 - USSR Anthem\n");
}

void loop() 
{
    runMain();
}

//This is the main function which calls a function of a melody depending on the selection of the user.
void runMain()
{
    
    char choice = '0'; 

    if (Serial.available() > 0) 
    {
        choice = Serial.read();  
    }

    if (choice == '1')
    {
        starWars();
    }

    else if (choice == '2')
    {
        marioBros();
    }
    
    else if (choice == '3')
    {
        sovietAnthem();
    }
}


//Function to play star wars theme
void starWars()
{
    for (int i = 0; i < (sizeof(starWarsFreq) / sizeof(starWarsFreq[0])); i++)
    {
        tone(buzzerPin, starWarsFreq[i],starWarsDelays[i]);
		delay(starWarsDelays[i]);

        analogWrite(RGBBluePin, random(0, 255));
        analogWrite(RGBRedPin, random(0, 255));
        analogWrite(RGBGreenPin, random(0, 255));
    }
}

//Function to play mario bros
void marioBros()
{
    for (int i = 0; i < (sizeof(marioBrothersFreq) / sizeof(marioBrothersFreq[0])); i++)
    {
        tone(buzzerPin, marioBrothersFreq[i],marioBrothersDelays[i]);
		delay(marioBrothersDelays[i] * 1.3);

        analogWrite(RGBBluePin, random(0, 255));
        analogWrite(RGBRedPin, random(0, 255));
        analogWrite(RGBGreenPin, random(0, 255));
    }
}

//Function to play soviet anthem
void sovietAnthem()
{   
    //Creating a for loop 
    for (int i = 0; i < (sizeof(sovietAnthemFreq) / sizeof(sovietAnthemFreq[0])); i++)
    {   
        tone(buzzerPin, sovietAnthemFreq[i],sovietAnthemDelays[i]);
		delay(sovietAnthemDelays[i]);
        analogWrite(RGBBluePin, random(0, 255));
        analogWrite(RGBRedPin, random(0, 255));
        analogWrite(RGBGreenPin, random(0, 255));
    }
}