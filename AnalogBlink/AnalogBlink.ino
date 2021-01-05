void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  blinkAnalog();
}

void blinkAnalog(){
  analogOutput(0);
}
void analogOutput(int n){
  if(n==255)
    return;
    analogWrite(9,n);
    delay(5);
    analogOutput(n+1);
    analogWrite(9,n);
    delay(5);
}
