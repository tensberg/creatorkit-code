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
int MODES = 3;
int modeSelectPin = 8;
int modeSelect = 0;
int modeSelectPressed = false;
int frame = 0;

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
      modeSelect = (modeSelect + 1)%MODES;
      
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
  
  int potValue;
  switch (modeSelect) {
    case 0:
      valRed = mixSelect == 0 ? 255 : 0;
      valGreen = mixSelect == 1 ? 255 : 0;
      valBlue = mixSelect == 2 ? 255 : 0;
      break;

    case 1:
      potValue = map(analogRead(potPin),0,1024,0,255);
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
      break;
      
      case 2:
        int speed = map(analogRead(potPin),0,1024,0,20);

        frame = (frame + speed)%900;
        
        if (frame<150) {                                   // wenn frame < 150  > rot
          valRed = 255;                         // LED wird eingeschaltet
          valBlue = 0;                          // LED wird abgeschaltet
          valGreen = 0;                         // LED wird abgeschaltet
        } else if (frame<300) {                            // wenn frame < 300
          valRed = map(frame,150,300,255,0);    // LED wird ausgedimmt
          valBlue = map(frame,150,300,0,255);   // LED wird angedimmt 
          valGreen = 0;                         // LED wird abgeschaltet
        } else if (frame<450) {                            // wenn frame < 450  > blau
          valRed = 0;                           // LED wird abgeschaltet
          valBlue = 255;                        // LED wird eingeschaltet
          valGreen = 0;                         // LED wird abgeschaltet  
        } else if (frame<600) {                            // wenn frame < 600
          valRed = 0;                           // LED wird abgeschaltet
          valBlue = map(frame,450,600,255,0);   // LED wird ausgedimmt 
          valGreen = map(frame,450,600,0,255);  // LED wird angedimmt
        } else if (frame<750) {                            // wenn frame < 750  > grün
          valRed = 0;                           // LED wird abgeschaltet
          valBlue = 0;                          // LED wird abgeschaltet 
          valGreen = 255;                       // LED wird abgeschaltet
        } else if (frame<900) {                            // wenn frame < 900
          valRed = map(frame,750,900,0,255);    // LED wird angedimmt
          valBlue = 0;                          // LED wird abgeschaltet 
          valGreen = map(frame,750,900,255,0);  // LED wird ausgedimmt
        }
        break;
  }

  analogWrite(LEDRed,valRed);                         // LED wird eingeschaltet
  analogWrite(LEDBlue,valBlue);                          // LED wird abgeschaltet
  analogWrite(LEDGreen,valGreen);                         // LED wird abgeschaltet
  analogWrite(MIXRed,valRed);                         // LED wird eingeschaltet
  analogWrite(MIXBlue,valBlue);                          // LED wird abgeschaltet
  analogWrite(MIXGreen,valGreen);                         // LED wird abgeschaltet

  delay(10);                                         // kurze Pause
}


