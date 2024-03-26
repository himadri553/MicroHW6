const int buttonPin = 2;
const int ledpin = 8;
int countFromButton = 0;
int CurrentButtonState = 0;
int lastButtonState = 0;
// Tracks time of last button press
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), initial_buttonISR, FALLING);
  Serial.begin(9600);
}

void blink(int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(ledpin, HIGH);
    delay(100);
    digitalWrite(ledpin, LOW);
    delay(100);
  }
}

void loop() {
  blink(countFromButton);
  Serial.println(countFromButton);
  delay(1000);
}

void initial_buttonISR() { // triggred at first button press
  Serial.println("initial_buttonISR triggred");
  CurrentButtonState = digitalRead(buttonPin);
  unsigned long currentTime = millis();

  // checks if 1sec has passed and is start of new sequence
  if (currentTime - lastDebounceTime >= 1000) {
    countFromButton = 0; // reset count
    Serial.println("reset count");
  }
  else { // is part of sequence
    if ((currentTime - lastDebounceTime) > debounceDelay) { // check for valid debounce 
      countFromButton++;
      Serial.println("valid counting press: count going up");
    }
  }

  lastDebounceTime = currentTime; // update time
}
