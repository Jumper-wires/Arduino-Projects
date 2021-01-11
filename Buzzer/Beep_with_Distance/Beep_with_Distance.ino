// Buzzer Beeps faster as you get close to it!

/*  PIN Connections
# Ultrasound Sensor
   # Vcc  --> 5V
   # Trig --> 12
   # Echo --> 13
   # GND  --> GND

# Buzzer
  Positive - 8
  Negative - GND (through resistor)
*/
//---------------------------------------------


const int buzzerPin = 8;
const int trigPin = 12;
const int echoPin = 13;
const float speedLight = 0.0343;//in cm/microseconds

float duration;  //Stores time taken by the signal to return
float distance;  //Stores the distance signal travelled
float delayBuzzer; //For changing the frequency of buzzer


void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);      //Wait for small time to make sure that trigPin is at LOW
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);      //Sent signal for 10 Micro Seconds
  digitalWrite(trigPin, LOW);

   duration = pulseIn(echoPin, HIGH);  
   distance = (duration * speedLight)/2;  

// Changing buzzer frequency depending on the value of distance
  if(distance > 500){ 
   delayBuzzer = 200; 
  }else if(distance<=500 && distance>100){
    delayBuzzer = 100; 
  }else if(distance<=30 && distance>10){
    delayBuzzer = 50; 
  }else{
    delayBuzzer = 20; 
  }
  
  digitalWrite(buzzerPin, LOW);
  delay(delayBuzzer);
  digitalWrite(buzzerPin,HIGH);
  delay(delayBuzzer);
    
  // Open Serial-Monitor to see the output
  Serial.print("Distance : ");
  Serial.println(distance);
  Serial.print(" cm");
}
