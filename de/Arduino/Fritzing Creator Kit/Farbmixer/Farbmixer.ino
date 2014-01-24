int LEDGreen=5;                                      // LEDGreen Pins wird deklariert
int LEDBlue=6;                                      // LEDBlue Pins wird deklariert
int LEDRed=3;                                       // LEDRed Pins wird deklariert 
int MIXGreen=10;                                      // LEDGreen Pins wird deklariert
int MIXBlue=9;                                      // LEDBlue Pins wird deklariert
int MIXRed=11;                                       // LEDRed Pins wird deklariert 
int potPin=0;
int mixSelectPin=2;
int mixSelect = 0;
boolean mixSelectPressed = false;
int modeSelectPin = 8;
int modeSelect = 0;
int modeSelectPressed = false;

int valRed = 255;
int valGreen = 255;
int valBlue = 255;

void setup(){
  pinMode(LEDRed,OUTPUT);                            // Pin wird als OUTPUT initialisiert
  pinMode(LEDGreen,OUTPUT);                          // Pin wird als OUTPUT initialisiert
  pinMode(LEDBlue,OUTPUT);                           // Pin wird als OUTPUT initialisiert
  pinMode(MIXRed,OUTPUT);                            // Pin wird als OUTPUT initialisiert
  pinMode(MIXGreen,OUTPUT);                          // Pin wird als OUTPUT initialisiert
  pinMode(MIXBlue,OUTPUT);                           // Pin wird als OUTPUT initialisiert
  pinMode(mixSelectPin, INPUT);
}

void loop(){

  if (digitalRead(modeSelectPin) == LOW) {
    if (!modeSelectPressed) {
      modeSelectPressed = true;
      modeSelect = (modeSelect + 1)%2;
      
      if (modeSelect > 0) {
        valRed = 255;
        valGreen = 255;
        valBlue = 255;
        delay(100);
      }
    }
  } else {
    modeSelectPressed = false;
  }
  
  if (digitalRead(mixSelectPin) == LOW) {
    if (!mixSelectPressed) {
      mixSelectPressed = true;
      mixSelect = (mixSelect + 1) % 3;
    }
  } else {
    mixSelectPressed = false;
  }
  
  if (modeSelect == 0) {
    valRed = mixSelect == 0 ? 255 : 0;
    valGreen = mixSelect == 1 ? 255 : 0;
    valBlue = mixSelect == 2 ? 255 : 0;
  } else {
    int potValue = map(analogRead(potPin),0,1024,0,255);
    switch (mixSelect) {
      case 0:
        valRed = potValue;
        break;
        
      case 1:
        valGreen = potValue;
        break;
        
      case 2:
        valBlue = potValue;
        break;
    }
  }

  analogWrite(LEDRed,valRed);                         // LED wird eingeschaltet
  analogWrite(LEDBlue,valBlue);                          // LED wird abgeschaltet
  analogWrite(LEDGreen,valGreen);                         // LED wird abgeschaltet
  analogWrite(MIXRed,valRed);                         // LED wird eingeschaltet
  analogWrite(MIXBlue,valBlue);                          // LED wird abgeschaltet
  analogWrite(MIXGreen,valGreen);                         // LED wird abgeschaltet

  delay(10);                                         // kurze Pause
}


