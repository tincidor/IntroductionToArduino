const int sensorPin = A1;
const int red_led_pin = 9;

int inputValue = 0;
int outputValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(red_led_pin, OUTPUT);
}

void loop() {
  inputValue = analogRead(sensorPin);

  //Serial.print("Input: ");
  Serial.println(inputValue);  

  outputValue = map(inputValue, 0, 1023, 0, 255);
  Serial.print("Output: "); 
  Serial.println(outputValue);
  analogWrite(red_led_pin, outputValue);
}
