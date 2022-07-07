const uint8_t MOTION_SENSOR_PIN = 2; // Arduino pin connected to the OUTPUT pin of motion sensor
const uint8_t BUTTON_PIN = 3;     // the number of the pushbutton pin
const uint8_t LED_PIN = 4; // Arduino pin connected to the input pin of the LED

const int redLED = PB4;

const uint16_t t1_load = 0; // counter +
const uint16_t t1_comp = 31250; // compare thresholds

uint8_t buttonState, motionState = 0;
uint8_t prevButtonState, prevMotionState = 0;

void setup()
{
  Serial.begin(9600); // Initialize Serial
  pinMode(LED_PIN, OUTPUT); // Set Arduino pin to output mode
  pinMode(MOTION_SENSOR_PIN, INPUT); // Set Arduino pin to input mode
  pinMode(BUTTON_PIN, INPUT_PULLUP); // initialize the pushbutton pin as an input
  
  // Set LED pin to be output
  DDRB |= (1 << redLED);
  
  PCICR |= 0b00000100; // Turn on port D
  PCMSK2 |= 0b00011100; // PCINT18,19,20
  
  // Reset Timer1 Control Reg A
  TCCR1A = 0;
  
  // Set CTC mode
  TCCR1B &= ~(1 << WGM13);
  TCCR1B |= (1 << WGM12);
  
  // Set to prescaler of 256
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);
  
  // Reset Timer1 and set compare value
  TCNT1 = t1_load;
  OCR1A = t1_comp;
  
  // Enable Timer1 compare interrupt
  TIMSK1 = (1 << OCIE1A);
  
  // Enable Global interrupts
  sei();
}

void loop(){
  if(prevButtonState != buttonState){
  	Serial.println("Alarm Off!"); // Print "Alarm Off!" to serial
  	digitalWrite(LED_PIN, LOW); // Turn LED off
    prevButtonState = buttonState;
  }
  
  if(prevMotionState != motionState){
  	Serial.println("Motion detected"); // Print "Motion Detected" to serial
  	digitalWrite(LED_PIN, HIGH); // Turn LED on
    prevMotionState = motionState;
  }
  delay(300);
}

ISR(PCINT2_vect){
  motionState = PIND & B00000100;
  buttonState = PIND & B00001000;
}

ISR(TIMER1_COMPA_vect){
  PORTB ^= (1 << redLED);
}
