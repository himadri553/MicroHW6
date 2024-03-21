const int buttonPin = 2;
const int ledpin = 8;
volatile int buttonState = 0;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), btn_ISR, CHANGE);
}

void loop() {
  if (buttonState == LOW) {
    digitalWrite(ledpin, HIGH);
  } 
  else {
    digitalWrite(ledpin, LOW);
  }
}

void btn_ISR() {
  buttonState = digitalRead(buttonPin);
}
