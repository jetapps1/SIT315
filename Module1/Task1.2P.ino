const uint8_t MOTION_SENSOR_PIN = 2; // Arduino pin connected to the OUTPUT pin of motion sensor
const uint8_t LED_PIN = 8; // Arduino pin connected to the input pin of the LED

void setup()
{
  pinMode(LED_PIN, OUTPUT); // Set Arduino pin to output mode
  pinMode(MOTION_SENSOR_PIN, INPUT); // Set Arduino pin to input mode
  Serial.begin(9600); // Initialize Serial
  attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), action, RISING); // Interrupt digital pin function
}

void loop(){}

void action() {
  Serial.println("Motion detected"); // Print "Motion Detected" to serial
  digitalWrite(LED_PIN, HIGH); // Turn LED on
  delay(100);
  Serial.println("LED blinked"); // Print "LED on" to serial
  digitalWrite(LED_PIN, LOW); // Turn LED off
}
