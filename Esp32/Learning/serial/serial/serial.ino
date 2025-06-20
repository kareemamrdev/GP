#include <esp32-hal-ledc.h>

const int analogPin = 34; // ADC1_CH6, GPIO34
const int ledPin = 25;    // GPIO25 for on/off LED
const int pwmLedPin = 26; // GPIO26 for PWM LED
const int pwmChannel = 0; // LEDC channel 0
const int pwmFreq = 5000; // PWM frequency in Hz
const int pwmResolution = 8; // 8-bit PWM resolution (0-255)

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);
  delay(1000); // Wait for Serial to initialize
  Serial.println("Starting ESP32 Analog LED Control with LEDC...");

  // Configure pins
  pinMode(ledPin, OUTPUT);
  pinMode(analogPin, INPUT);

  // Configure LEDC PWM using ledcAttach
  Serial.println("Configuring LEDC PWM...");
  // ledcAttach(gpioPin, frequency, resolutionBits)
  if (!ledcAttach(pwmLedPin, pwmFreq, pwmResolution)) {
    Serial.println("Error: Failed to configure LEDC PWM");
    while (1); // Halt on error
  }
  Serial.println("LEDC PWM configured successfully.");
}

void loop() {
  // Read analog value (0-4095)
  int analogValue = analogRead(analogPin);

  // Threshold for on/off LED (half of 4095)
  int threshold = 2048;

  // Control on/off LED
  if (analogValue > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Map analog value (0-4095) to PWM value (0-255)
  int pwmValue = map(analogValue, 0, 4095, 0, (1 << pwmResolution) - 1);

  // Set PWM for proportional LED
  ledcWrite(pwmLedPin, pwmValue);

  // Print values for debugging
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(" PWM: ");
  Serial.println(pwmValue);

  delay(100); // Small delay for stability
}