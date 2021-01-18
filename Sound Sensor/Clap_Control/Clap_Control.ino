bool state = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  digitalWrite(13, LOW);
}
bool flag = false;
void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(12)==LOW){
    Serial.println("Muahahaha--");
    delay(80);
    for(int j = 0; j < 800; j++){
      delay(1);
      Serial.println(j);
      if(digitalRead(12)==LOW){
        Serial.println("Muahahaha");
        state = !state;
        if(state){
             digitalWrite(13, HIGH);
        }
        else {
            digitalWrite(13, LOW);
        }
        break;
      }
    }
    delay(500);
  }
}
