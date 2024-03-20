const int buttonPin = 2;
const int ledpin = 13;
volatile int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), btn_ISR, CHANGE);
}

void loop() {
  if (buttonState == HIGH){
    digitalWrite(ledPin, HIGH);
  } 
  else{
    digitalWRITE(ledPin, LOW);
  }
}

void btn_ISR(){
  buttonState = digitalRead(buttonPin);
}