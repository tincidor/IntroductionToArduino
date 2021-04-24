const int red_led_pin = 11;

// Run once
void setup() {
   Serial.begin(9600);
   pinMode(red_led_pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(red_led_pin, HIGH);
  Serial.println("On");  
  delay(1000);                 
  
  digitalWrite(red_led_pin, LOW);  
  Serial.println("Off");
  delay(1000); 
}
