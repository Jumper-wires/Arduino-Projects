//Program to switch ON an LED automatically at night or if the lights in the room are turned OFF.
//Connections : 
/*
5V(on Arduino)_________LDR_________Resistor(1k)_________GND(on Arduino)
                              |
                              | 
                              A0
                        (on Arduino)   



Port 8(on Arduino)_______ LED______Resistor(220ohm)______GND(on Arduino)

*/

int ldrPin = A0;   
int ldrValue;   //It will store value of LDR
int ledPin = 8;

void setup(){
  Serial.begin(9600); //Intializing the serial monitor
  pinMode(ledPin, OUTPUT);
}

void loop(){
  
  ldrValue = analogRead(ldrPin);
  Serial.print(ldrValue); //Open serial monitor to watch the value of LDR
  
  if(ldrValue < 20){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
