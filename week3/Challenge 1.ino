//Challenge 1

int rotationPin = A0; 
int data=0;


void setup() 
{
Serial.begin(9600); 

pinMode(rotationPin,INPUT);
}

void loop() 
{ 
data = analogRead(rotationPin); 
Serial.print("Rotation value =");
Serial.println(data);
delay(1000); 
}