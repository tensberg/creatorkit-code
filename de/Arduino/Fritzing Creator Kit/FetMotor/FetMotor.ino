int motorControlPin = 2;
int motorPowerPin = 8;

boolean motorOn = false;

void setup(){
  pinMode(motorControlPin,INPUT);
  pinMode(motorPowerPin,OUTPUT);
}

void loop(){
  if (digitalRead(motorControlPin) == LOW) {
    if (!motorOn) {
      motorOn = true;
      digitalWrite(motorPowerPin, HIGH);
    }
  } else {
    if (motorOn) {
      motorOn = false;
      digitalWrite(motorPowerPin, LOW);
    }
  }
}
