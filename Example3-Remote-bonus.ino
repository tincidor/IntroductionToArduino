const int red_led_pin = 11;
const int green_led_pin = 10;
const int yellow_led_pin = 9;
const int blue_led_pin = 5;

// Run once
void setup() {
   Serial.begin(9600);
   pinMode(red_led_pin, OUTPUT);
   pinMode(green_led_pin, OUTPUT);
   pinMode(yellow_led_pin, OUTPUT);
   pinMode(blue_led_pin, OUTPUT);
}

void blink_light(int lightToBlink) {
  digitalWrite(lightToBlink, HIGH);  
  delay(1000);                 

  digitalWrite(lightToBlink, LOW);  
  delay(1000);
}

// the loop function runs over and over again forever
void loop() {
   blink_light(red_led_pin);
   blink_light(green_led_pin);
   blink_light(yellow_led_pin);
   blink_light(blue_led_pin);
}
