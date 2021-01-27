/*This is a program to display the temperature and humidity of your surroundings on a 16*2 lcd display
connections- 

  First, power up the things. Connect the + and - on the DHT11 to the 5V and Ground of arduino respectively
  Then, power the lcd by connecting the Vss pin of lcd to Ground, and the Vdd pin to 5V. 

  connect DHT11 temperature sensor to pin 13 of arduino
  connect d4, d5, d6, d7 pins of lcd to the pins 4, 5, 6, 7 of arduino respectively, 
  
  connect the Register Select(RS) pin of lcd to pin 2 of arduino
  connect the enable(E) pin of lcd to the pin 3 of arduino
  connect the Read/Write(RW) pin of lcd with ground

  Next up, we need to connect the V0 pin on the lcd to the signal output pin(middle pin) of the potentiometer,
  and also supply 5V to it from the arduino. Also join the ground pin of the potentiometer to the ground of arduino.
  
  Last, connect the anode(A) of the lcd to ground, and the cathode(K) to 5V
*/


//  Don't forget to calibrate the potentiometer so that your text is visible on the lcd after you have uploaded your sketch.
#include<LiquidCrystal.h>
#include<DHT.h>

int rs = 2;
int e = 3;

int d4 = 4;
int d5 = 5;
int d6 = 6;
int d7 = 7;

int sensorPin = 12; // to sense output from DHT11

DHT dht(sensorPin, DHT11); // to initialize an object of DHT11
LiquidCrystal lcd(rs, e, d4, d5, d6, d7); // to initialize an object of LCD

void setup() {
  dht.begin();
  lcd.begin(16, 2); // we need to tell the dimensions of lcd
}

int strLength_1 = 0;
int strLength_2 = 0;

void loop() {

  float tempFloat = dht.readTemperature();
  float humFloat = dht.readHumidity();

  int tempC = round(tempFloat);
  int hum = round(humFloat);

  String str1 = String("Temperature: ") + tempC + String("C");
  String str2 = String("Humidity: ") + hum + String("%");

  lcd.setCursor(0,0); //for setting the cursor on the first row
  if(str1.length() != strLength_1){
    lcd.clear(); //for clearing the lcd whenever the text on 1st row changes
  }

  strLength_1 = str1.length();
  lcd.print(str1); // for printing on the lcd

    lcd.setCursor(0,1); //for setting the cursor on the second row
  if(str2.length() != strLength_2){
    lcd.clear(); //For clearing the lcd whenever the text on 2nd row changes
  }

  strLength_2 = str2.length();
  lcd.print(str2); // for printing on the lcd
}
