const int buttonPin = 2;
const int ledpin = 13;
int count = 0;

// Variable to track time of last button press
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 1000; // debounce time; increase if the button seems to bounce

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
void loop() {
  int reading = digitalRead(buttonPin); // read the state of the button

// check if the button state has changed
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // update the last debounce time
  }

  // check if the button state has been stable for the debounce delay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed
    if (reading != buttonState) {
      buttonState = reading; // update the button state

      // if the button state is LOW (pressed)
      if (buttonState == LOW) {
        count++; // increment the count
        Serial.print("Button pressed! Count: ");
        Serial.println(count); // print the count to the serial monitor
      }
    }
  }

  // update the last button state
  lastButtonState = reading;

// if no button press is detected for more than 1 second
  if (millis() - lastDebounceTime > debounceDelay && buttonState == HIGH) {
    // indicate the end of the sequence by blinking the LED
    digitalWrite(ledPin, HIGH);
    delay(100); // adjust the blink duration as needed
    digitalWrite(ledPin, LOW);
    count = 0; // reset the count
    Serial.println("End of sequence");
  }
}

void btn_ISR(){
  buttonState = digitalRead(buttonPin);
}
