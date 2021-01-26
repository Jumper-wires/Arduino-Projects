/*
 Program to control output using 2 claps
 The output at pin 13 will be HIGH when sound sensor detects any sound
 Just connect pin 12 of the arduino to sound sensor's digital Out pin,
 and calibrate the potentiometer to detect claps, eleminating background noises, after uploading uour sketch
*/
const int outputPin = 13;
const int soundPin = 12;

bool state = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(soundPin, INPUT);
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(13, LOW);
}
bool flag = false;
void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(soundPin)==LOW){
    Serial.println("1st Clap");
    delay(80);
    for(int j = 0; j < 800; j++){
      delay(1);
      Serial.println(j);
      if(digitalRead(soundPin)==LOW){
        Serial.println("2nd Clap");
        state = !state;
        if(state){
             digitalWrite(outputPin, HIGH);
        }
        else {
            digitalWrite(outputPin, LOW);
        }
        break;
      }
    }
    delay(500);
  }
}
