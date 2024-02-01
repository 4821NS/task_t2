const int pirSensorInterrupt = 2;   // PIR sensor connected to pin 3
const int indicatorLedPin = 6;      // Indicator LED connected to digital pin 5
volatile int motionStatus = 0;      // Status indicating motion detection

void setup() {
  Serial.begin(9600);
  Serial.println("Motion Detection System Initialized");
  
  pinMode(indicatorLedPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pirSensorInterrupt), handleMotionInterrupt, HIGH);
}

void loop() {
}

void handleMotionInterrupt() {
  int motionValue = digitalRead(pirSensorInterrupt);
 

  if (motionValue == HIGH) {
    digitalWrite(indicatorLedPin, HIGH);  // Turn on the indicator LED
    Serial.println("Motion detected!");
    delay(1000);  // Adjust this delay as needed
    digitalWrite(indicatorLedPin, LOW);   // Turn off the indicator LED
    motionStatus = 1;                      // Set motion status
  } else {
    Serial.println("No motion detected");
    // motionStatus = 0;                      // Reset motion status
  }
}
