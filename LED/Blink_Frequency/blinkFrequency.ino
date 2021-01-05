// This program will blink the inbuilt LED of the arduino at a desired frequency.
//Give the frequency of blinking as input in the blinkFrequency Function in void loop()

//Frequency : number of times LED blink per second
// Input = 2 : LED blinks 2 times a second
// Input = 0.5 : LED blinks once in two seconds

void blinkFrequency(float freq){
  float timeDelay = 1000/freq;

  digitalWrite(LED_BUILTIN, HIGH);   
  delay(100);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(timeDelay);                       
  
}
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //Give the frequency here
  blinkFrequency(1.5);

}
