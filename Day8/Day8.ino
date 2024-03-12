int redLed = 11;
int bluLed = 10;
int greLed = 9;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(bluLed, OUTPUT);
  pinMode(greLed, OUTPUT);
}

void RGB_color(int red_value, int green_value, int blue_value) {
  // custom function to set three PWM color channels to any given mixture
  analogWrite(redLed, red_value);
  analogWrite(greLed, green_value);
  analogWrite(bluLed, blue_value);
}

void loop()
{
  RGB_color(125, 0, 0); // Red
  delay(800);
  RGB_color(0, 125, 0); // Green
  delay(800);
  RGB_color(0, 0, 125); // Blue
  delay(800);
  RGB_color(64, 32, 0); // Yellow
  delay(800);
  RGB_color(125, 0, 125); // Purple
  delay(800);
  RGB_color(125, 125, 125); // White
  delay(2000);

}

// RGB Led - 2 Common
// Digital is either 0 or 5V
// control the timing between 0 -255
// 0 off, 255 - On all the time, 128 - half the time
// Pulse Width Modulation - PWM - Writing Digital Output with analog
// Arduino these pins are indicated with a ~
// Pin 3,5,6,9,10,11