#include <IRremote.h> 

const int RECV_PIN = 4; // the pin where you connect the output pin of IR sensor     
IRrecv irrecv(RECV_PIN);     
decode_results results;  

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

   irrecv.enableIRIn();
}

void blink_light(int lightToBlink) {
  digitalWrite(lightToBlink, HIGH);  
  delay(1000);                 

  digitalWrite(lightToBlink, LOW);  
}

// the loop function runs over and over again forever
void loop() {
   /*
   red button code 14025
   green button code 10455
   yellow button code -22441
   blue button code 26775   
   */
   if (irrecv.decode(&results)) {// Returns 0 if no data ready, 1 if data ready.          
      int value = results.value;// Results of decoding are stored in result.value
      
      if (value == 14025) { // red
        blink_light(red_led_pin);
        Serial.println("Red"); 
      } else if (value == 10455) { // green
        blink_light(green_led_pin);
        Serial.println("Green");
      } else if (value == -22441) { // yellow
        blink_light(yellow_led_pin);
        Serial.println("Yellow");
      } else if (value == 26775) { // blue
        blink_light(blue_led_pin);
        Serial.println("Blue");
      }
 
      irrecv.resume(); // Restart the ISR state machine and Receive the next value  
   }
}
