/*
 * Code to beep an active buzzer according to the given morse code
 * Connections-
 *  Positive terminal of the buzzer to pin 13
 *  Negative terminal of the buzzer to ground
 */
 
const int buzzPin = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {   
  delay(2000);
  beepAsMorse("this is my message");    
  Serial.println();
  Serial.println("####################################################################################################################################################");
  delay(7000);
}

void beepAsMorse(char str[]){
  char arr1[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0'};
  char *arr2[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----"};
  int i,j;
  for(i=0; str[i]!='\0'; i++){
    char c = str[i];
    for(j = 0; j<(sizeof(arr1)/sizeof(char));j++){
      if(c==arr1[j]){
        beepMorse(arr2[j]);
      }
    }
    if(c==' ')
        Serial.println();
    delay(210);
  }
}

void beepMorse(char str[]){
  char c1 = '.';
  char c2 = '-';
  int i;
  for(i = 0; str[i]!='\0'; i++){
    if(str[i]==c1){
      Serial.print(c1);
      digitalWrite(buzzPin,HIGH);
      delay(30);
      digitalWrite(buzzPin,LOW);

    }else if(str[i]==c2){
      Serial.print(c2);
      digitalWrite(buzzPin,HIGH);
      delay(90);
      digitalWrite(buzzPin,LOW);

    }
    delay(90);
  }
    Serial.print("  ");
}
