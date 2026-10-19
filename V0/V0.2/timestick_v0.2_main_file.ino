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

int resetCurrState;
int resetPrevState=1;
bool resetButtonPressed;

int pauseCurrState;
int pausePrevState = 1;
bool pauseButtonPressed;

bool minuteAdjust;
String prevUnit;
bool secondAdjust;

int secondCount = 0;
int minuteCount = 0;
int startMillis;
int currMillis;
int incPressMillis;
int decPressMillis;
int resetPressMillis;
int pausePressMillis;
int bounceDelay = 400;

bool timeAdjusting = true;
LiquidCrystal_I2C lcd(0x27,16, 2);
String minuteDisplay;
String secondDisplay;



void timerStarter(){        // Link countUp() function here
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                 ");
  lcd.print("Timer Started");
}

void increment(){
  incCurrState = digitalRead(incButton);
  if(incPrevState == 0 && incCurrState == 1 && (currMillis-incPressMillis)>=bounceDelay && incButtonPressed == false){
    incButtonPressed = true;
    if(minuteAdjust == true && timeAdjusting == true){
      minuteCount = minuteCount+1;
    }
    if(secondAdjust == true && timeAdjusting == true){
      secondCount = secondCount+1;
    }
    
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
    if (secondCount > 0 && minuteCount > 0){
      if(minuteAdjust == true && timeAdjusting == true){
        minuteCount = minuteCount-1;
      }
      if (secondAdjust == true && timeAdjusting == true){
        secondCount = secondCount-1;
      }
    }
    
    decPressMillis = currMillis;
  }
  else{
    decButtonPressed = false;
  }
  decPrevState = decCurrState;
}
void adjustMode(){
  // Serial.println("adjustMode()");
  if(timeAdjusting == true){
    // Serial.println("adjustMode() inside if");
    resetCurrState = digitalRead(resetButton);
    if(resetPrevState == 0 && resetCurrState == 1 && (currMillis-resetPressMillis)>=bounceDelay && resetButtonPressed == false){
      resetButtonPressed = true;
      Serial.println("reset pressed");
      timeAdjusting = false;
      resetPressMillis = currMillis;
      
    }
    else{
      resetButtonPressed=false;
    }
    resetPrevState = resetCurrState;

    pauseCurrState = digitalRead(pauseButton);
    if(pausePrevState == 0 && pauseCurrState == 1 && (currMillis-pausePressMillis)>=bounceDelay && pauseButtonPressed == false){
      Serial.println("Pause pressed");
      pauseButtonPressed=true;
      if (minuteAdjust == true){
        minuteAdjust = false;
        Serial.println("second adjusting");
        secondAdjust = true;
        lcd.setCursor(14, 0);
        lcd.print("+-");
        lcd.setCursor(0, 0);
        lcd.print("  ");
      }
      else{
        secondAdjust = false;
        Serial.println("minute adjusting");
        minuteAdjust = true;
        lcd.setCursor(0, 0);
        lcd.print("+-");
        lcd.setCursor(14, 0);
        lcd.print("  ");
      }
      pausePressMillis = currMillis;
    }
    else{
      pauseButtonPressed=false;
    }
    pausePrevState = pauseCurrState;
    increment();
    decrement();
  }
  else{
    timerStarter();
  }
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
  minuteAdjust = true;

  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  currMillis = millis();
  adjustMode();
  timeDisplay();
}
