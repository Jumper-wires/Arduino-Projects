void printAsMorse(char str[]);
void printMorse(char str[]);

void printAsMorse(char str[]){
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
  }
}

void printMorse(char str[]){
  char c1 = '.';
  char c2 = '-';
  int i;
  for(i = 0; str[i]!='\0'; i++){
    if(str[i]==c1){
      digitalWrite(LED_BUILTIN,HIGH);
      delay(250);
      digitalWrite(LED_BUILTIN,LOW);
      delay(250);
    }else if(str[i]==c2){
      digitalWrite(LED_BUILTIN,HIGH);
      delay(750);
      digitalWrite(LED_BUILTIN,LOW);
      delay(250);
    }
  }
    delay(1750);
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  delay(5000);
  printAsMorse("this is my message");                  
}
