const uint8_t MOTION_SENSOR_PIN = 2; // Arduino pin connected to the OUTPUT pin of motion sensor
const uint8_t BUTTON_PIN = 3;     // the number of the pushbutton pin
const uint8_t LED_PIN = 8; // Arduino pin connected to the input pin of the LED

void setup()
{
  Serial.begin(9600); // Initialize Serial
  pinMode(LED_PIN, OUTPUT); // Set Arduino pin to output mode
  pinMode(MOTION_SENSOR_PIN, INPUT); // Set Arduino pin to input mode
  pinMode(BUTTON_PIN, INPUT_PULLUP); // initialize the pushbutton pin as an input
  
  attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), action, RISING); // Interrupt digital pin function for motion
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), toggleButton, FALLING); // Interrupt digital pin function for button push
}

void loop(){delay(100);}

void action() {
  Serial.println("Motion detected"); // Print "Motion Detected" to serial
  digitalWrite(LED_PIN, HIGH); // Turn LED on
  delay(100);
}

void toggleButton() {
  Serial.println("Alarm Disabled!"); // Print "Alarm Disabled!" to serial
  digitalWrite(LED_PIN, LOW); // Turn LED off
}
