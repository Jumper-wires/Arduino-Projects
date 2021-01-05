// This program will make an LED fade-in and fade-out 
// Change the switchSpeed variable value to change the speed of fading 

int led = 9;  //the port number to which LED is connected
int switchSpeed = 1; //speed of fading

void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
  for(int i=0; i<=255; i+=switchSpeed){
    analogWrite(led, i);
    delay(5);
  }
  for(int i=255; i>=0; i-=switchSpeed){
    analogWrite(led, i);
    delay(5);
  }
  delay(200);
}
