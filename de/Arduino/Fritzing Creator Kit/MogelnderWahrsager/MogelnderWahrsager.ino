/*
  Wahrsager
  schaltet zwischen fünf LEDs um die Zukunft vorher zu sagen
  
  Dieses Beispiel aus dem Fritzing Creator Kit: www.fritzing.org/creator-kit.
*/

int pins[] = {8,9,10,11,12};            // Pins der einzelnen LEDs werden in einem Array gespeichert
int mogelPin = 2;
int tiltPin = 3;                        // Pin-Nummer des Neigungsschalters wird deklariert

int mogelLed = 0;
boolean tiltPinAn = false;
boolean mogelPinAn = false;

void setup() {                           
  for (int i=0; i<5; i=i+1){            
    pinMode(pins[i] , OUTPUT);          // LED Pins werden als OUTPUTS deklariert
  }
  pinMode(mogelPin,INPUT);
  pinMode(tiltPin,INPUT);  // Pin des Neigungsschalters wird als INPUT deklariert
  randomSeed(analogRead(0));
}

void loop() {
  if (digitalRead(tiltPin)==LOW){      // wenn der Tilt-Switch geöffnet ist
   tiltPinAn = true;
   allesAus();
   int myRandom=random(0,5);            // eine zufällige LED wird ausgewählt
   digitalWrite(pins[myRandom],HIGH);   // und angeschalten
   delay(20);                           // Programm macht eine kurze Pause
  } else {
    if (tiltPinAn) {
      tiltPinAn = false;
      if (mogelLed > 0) {
        mogelAn();
      }
    } else {
      if (digitalRead(mogelPin)==HIGH) {
        if (!mogelPinAn) {
          mogelPinAn = true;
          mogelNaechsteLed();
        }
      } else {
        mogelPinAn = false;
      }
    }
  }
}

void allesAus() {
 for (int i=0; i<5; i=i+1){           // werden alle LEDs
   digitalWrite(pins[i],LOW);         // abgeschalten
 }                                    // sonst
}

void allesAn() {
 for (int i=0; i<5; i=i+1){           // werden alle LEDs
   digitalWrite(pins[i],HIGH);         // abgeschalten
 }                                    // sonst
}

void mogelAn() {
  allesAus();
  digitalWrite(pins[mogelLed-1], HIGH);
}

void mogelNaechsteLed() {
  mogelLed++;
  if (mogelLed == 6) {
    mogelLed = 0;
    allesAn();
  } else {
    mogelAn();
  }
}
