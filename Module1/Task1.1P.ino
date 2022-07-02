int MOTION_SENSOR_PIN = 2; // Arduino pin connected to the OUTPUT pin of motion sensor
int LED_PIN = 8; // Arduino pin connected to the input pin of the LED

void setup()
{
  pinMode(LED_PIN, OUTPUT); // Set Arduino pin to output mode
  pinMode(MOTION_SENSOR_PIN, INPUT); // Set Arduino pin to input mode
  Serial.begin(9600); // Initialize Serial
}

void loop()
{
  int currentMotion = digitalRead(MOTION_SENSOR_PIN); // Store the Motion Sensor's Current State
  
  if(currentMotion==HIGH) { // If motion is detected
    Serial.println("Motion detected"); // Print "Motion Detected" to serial
  	digitalWrite(LED_PIN, HIGH); // Turn LED on
    delay(1000); // Wait for 1000 millisecond(s)
  }
  else {
    digitalWrite(LED_PIN, LOW); // Turn LED off
  }
}
