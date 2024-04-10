/*
  Del C:
  button(toggle) will turn LED on or off
  once the button is turned on, wait and turn servo on to push the button off
  if possible, use a counter to make the machine more "mad" and swtich up servo behavior
*/
#define buttonPin 2
#define LED_Pin 42
int ledState = LOW;
int madState = 1;
bool mad_trigger = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED_Pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), initial_buttonISR, FALLING);
  Serial.begin(9600);

}

void loop() {
  // vars

  // check if led is on, then get mad
  if (ledState == HIGH) {
    mad_trigger = true;
  }
  
  if (mad_trigger == true) {
    mad_trigger = false; // cool off after
    switch (madState) {
      case 1:
        madState1();
        break;
      case 2:
        madState2();
        break;
      case 3:
        madState3();
        break;
    }
  }
}

void initial_buttonISR() {
  unsigned long currentTime = millis();
  if ((currentTime - lastDebounceTime) > debounceDelay) { // check debounce
    // toggle led
    ledState = !ledState;
    digitalWrite(LED_Pin, ledState);
  }
}

// servo actions when mad, will not be mad after
void madState1() {
  
}

void madState2() {

}

void madState3() {

}

