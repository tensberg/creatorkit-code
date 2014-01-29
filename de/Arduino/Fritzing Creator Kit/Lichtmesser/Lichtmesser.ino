

// Pinbelegung für Arduino UNO
int reihenPins[8] = {9,3,2,12,15,11,7,6};      // Anschlüsse der Reihenpins am Arduino
int spaltenPins[8] = {13,8,17,10,5,16,4,14};   // Anschlüsse der Spaltenpins am Arduino


// Pinbelegung für Arduino MEGA
// int reihenPins[8] = {9,3,2,12,55,11,7,6};      // Anschlüsse der Reihenpins am Arduino
// int spaltenPins[8] = {13,8,57,10,5,56,4,54};   // Anschlüsse der Spaltenpins am Arduino

int lichtsensorPin=18;                                        // Pin an dem das Potentiometer von Spieler 1 angeschlossen ist
int maxLichtsensor = 1000:

int intensity;

void setup(){
  for (int i=0; i<8; i++){                               // Alle Pins werden als OUTPUT deklariert 
    pinMode(reihenPins[i],OUTPUT);
    pinMode(spaltenPins[i],OUTPUT);
  }
}

void draw(){
  for (int y=0; y<8; y++){                               // zeilenweise werden 
    for (int x=0; x<8; x++){                             // von links nach rechts alle Einträge des Arrays geprüft
      if (intensity >= y*8+x){
        digitalWrite(spaltenPins[x],HIGH);               // wird der Spaltenpin eingeschalten
      } else {                                           // sonst
        digitalWrite(spaltenPins[x],LOW);                // abgeschalten
      }
    }
    digitalWrite(reihenPins[y],LOW);                     // nun wird der Reihenpin auf LOW geschalten (da es die Kathode der LED betrifft bedeutet LOW eingeschalten: LOW = GND)
    delayMicroseconds(1000);                             // das Programm hällt 1000 Mikrosekunden an
    digitalWrite(reihenPins[y],HIGH);                    // danach wird der Reihenpin wieder auf HIGH (in diesem Fall also abge-) schalten
  }
}

void update(){
    intensity = map(analogRead(lichtsensorPin),0,maxLichtsensor,0,63); // Lichtstärke gemappt auf die 64 LEDs der Matrix
}

void loop(){
  update();                                                // alle Berechnungen sind in der update-Methode
  draw();                                                  // Darstellung ist in der draw-Methode
}
