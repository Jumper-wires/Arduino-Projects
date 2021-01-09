/* Program to fade an led as an object gets away from the sensor
 *  
 *PIN Connections
 
  Ultrasonic sensor- 
   # Vcc  --> 5V
   # Trig --> 12
   # Echo --> 8
   # GND  --> GND

 */
 
const int trigPin = 10;
const int echoPin = 8;

const int ledOutputPin = 6; // Port to which led is connected

const int speedOfSound = 0.0343;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(echoPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(ledOutputPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH); // duration between time of sending the pulse and receiving it back
  float distance = (speedOfSound * duration)/2;  // distance between the object and the sensor

  // varying the brghtness based upon distance
  int brightness;
  if(distance <= 127 && distance > 5){ 
    brightness = 255- 2*distance;
    analogWrite(ledOutputPin, brightness);
  }

  Serial.print("Distance: ");
  Serial.println(distance);

  delay(10);
}
