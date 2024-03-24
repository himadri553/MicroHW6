const int buttonPin = 2;
const int ledpin = 13;
int count = 0;
int buttonState = 0;
int lastButtonState = 0;

// Tracks time of last button press
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (buttonState == LOW){
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
        delay(50); // debounce delay
      }
    }
  }

  // update the last button state
  lastButtonState = reading;

// if no button press is detected for more than 1 second
  if (millis() - lastDebounceTime > debounceDelay && buttonState == HIGH) {
    // indicate the end of the sequence by blinking the LED
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    count = 0; // resets the count
  }
}

// This code is similar to one above possibly, test which one works better
 // Check if there's a pause between presses
  if (lastButtonState == LOW && count > 0) {
    // Blink LED count times
    for (int i = 0; i < count; i++) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }

    // Pause for approximately one second
    delay(1000);

    // Reset count
    count = 0;
  }
}

