#include <LiquidCrystal_I2C.h>
int incButton = 8;
int decButton = 12;
int pauseButton = 10;
int resetButton = 2;

int incCurrState;
int incPrevState=1;
bool incButtonPressed;

int decCurrState;
int decPrevState=1;
bool decButtonPressed;

int secondCount = 0;
int minuteCount = 0;
int startMillis;
int currMillis;
int incPressMillis;
int decPressMillis;
int bounceDelay = 400;


LiquidCrystal_I2C lcd(0x27,16, 2);
String minuteDisplay;
String secondDisplay;

void increment(){
  incCurrState = digitalRead(incButton);
  if(incPrevState == 0 && incCurrState == 1 && (currMillis-incPressMillis)>=bounceDelay && incButtonPressed == false){
    incButtonPressed = true;
    secondCount = secondCount+1;
    incPressMillis = currMillis;
  }
  else{
    incButtonPressed = false;
  }
  incPrevState = incCurrState;
}

void decrement(){
  decCurrState = digitalRead(decButton);
  if(decPrevState == 0 && decCurrState == 1 && (currMillis-decPressMillis)>=bounceDelay && decButtonPressed == false){
    decButtonPressed = true;
    if (secondCount > 0){
      secondCount = secondCount-1;
    }
    
    decPressMillis = currMillis;
  }
  else{
    decButtonPressed = false;
  }
  decPrevState = decCurrState;
}

void timeDisplay(){
  if (minuteCount<10){
    minuteDisplay = "0" + String(minuteCount);
  }
  else{
    minuteDisplay = String(minuteCount);
  }

  if(secondCount<10){
    secondDisplay = "0" + String(secondCount);
  }
  else{
    secondDisplay = String(secondCount);
  }

  lcd.setCursor(3,0);
  lcd.print("MIN : SEC");
  lcd.setCursor(4, 1);
  lcd.print(minuteDisplay);
  lcd.setCursor(7,1);
  lcd.print(":");
  lcd.setCursor(9,1);
  lcd.print(secondDisplay);
}

void setup() {
  pinMode(incButton,INPUT_PULLUP);
  pinMode(pauseButton,INPUT_PULLUP);
  pinMode(decButton,INPUT_PULLUP);
  pinMode(resetButton,INPUT_PULLUP);

  Serial.begin(9600);

  incPressMillis = millis();

  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  currMillis = millis();
  increment();
  decrement();
  timeDisplay();
}
