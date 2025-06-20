// Define the pin number for the built-in LED
const int ledPin = 2; // Built-in LED is usually on GPIO 2

void setup() {
  // Initialize the digital pin as an output
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  Serial.print("ss: ");
  for(int i=0; i<500; i++){
    Serial.println("dd: ");
  }
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(1000);                // Wait for 1 second
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(1000);                // Wait for 1 second
  Serial.print("ID: ");
}

