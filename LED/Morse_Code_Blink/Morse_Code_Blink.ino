// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {   
  String msg; 
  delay(2000);
  Serial.print("Enter your message: ");
  while(Serial.available()==0){
  }
  msg = Serial.readStringUntil('\n');
  delay(500);
  Serial.println(msg);
  delay(100);
  printAsMorse(msg); 
  Serial.println();
  Serial.println();
}

void printAsMorse(String str){
  char arr1[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0'};
  char *arr2[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----"};
  int i,j;
  for(i=0; str[i]!='\0'; i++){
    char c = str[i];
    for(j = 0; j<(sizeof(arr1)/sizeof(char));j++){
      if(c==arr1[j]){
        printMorse(arr2[j]);
      }
    }
    if(c==' ')
      Serial.println();
  }
}

void printMorse(char str[]){
  char c1 = '.';
  char c2 = '-';
  int i;
  for(i = 0; str[i]!='\0'; i++){
    if(str[i]==c1){
      Serial.print(c1);
      digitalWrite(LED_BUILTIN,HIGH);
      delay(125);
      digitalWrite(LED_BUILTIN,LOW);
      delay(125);
    }else if(str[i]==c2){
      Serial.print(c2);
      digitalWrite(LED_BUILTIN,HIGH);
      delay(375);
      digitalWrite(LED_BUILTIN,LOW);
      delay(125);
    }
  }
    delay(750);
    Serial.print("  ");
}
