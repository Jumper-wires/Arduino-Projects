/* Program to measure distance using ultrasound sensor
   PIN Connections

   # Vcc  --> 5V
   # Trig --> 12
   # Echo --> 8
   # GND  --> GND
*/

const int trigPin = 12;
const int echoPin = 8;

float duration;  //Stores time taken by the signal to return
float distance;  //Stores the distance signal travelled

void setup(){
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);      //Wait for small time to make sure that trigPin is at LOW
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);      //Sent signal for 10 Micro Seconds
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);  //PulseIn --> listens to the echo pin and measures how long it has been set HIGH
  distance = (duration * 0.0343)/2;  // distance = time x speed of sound [Speed of Sound - 343 m/s === 0.0343 cm / micro second]

   Serial.print("Distance : ");
   Serial.println(distance);

   delay(100);
}
