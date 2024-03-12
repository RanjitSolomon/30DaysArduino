int sensorPin = A0;
int sensorValue = 0;

int redLed = 11;
int greLed = 10;
int bluLed = 9;

unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
unsigned PercentFull;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greLed, OUTPUT);
  pinMode(bluLed, OUTPUT);

  Serial.begin(9600);
}

void RGB_color(int red_value, int green_value, int blue_value) {
  // custom function to set three PWM color channels to any given mixture
  analogWrite(redLed, red_value);
  analogWrite(greLed, green_value);
  analogWrite(bluLed, blue_value);
}

double getBatteryPercentage() {
  // Custom function calculates battery charge percentage
  // and returns the result as a double precision number

  return (((double)batteryLevel/ (double)batteryCapacity)*100);
}

void showBatteryPercentage() {
  // send battery results to both serial and LED outputs
  // calculate the charge percentage with a custom function
  PercentFull = getBatteryPercentage();

  // print the elapsed time
  Serial.print(ticks);
  Serial.print(" ms charge at ");
  // print the percent charge
  Serial.print(PercentFull);
  // print a percent character and line return...
  Serial.println("%");

  // Now let's light the LED with the appropriate color...
  if(PercentFull > 0 && PercentFull <= 25) {
    RGB_color(125, 0, 0); // red
  } else if (PercentFull > 25 && PercentFull <= 50) {
    RGB_color(125, 80, 0); // Yellow-ish
  } else if (PercentFull > 50 && PercentFull <= 75) {
    RGB_color(0, 125, 125); // blue-ish
  } else if (PercentFull > 75 && PercentFull < 100) {
    RGB_color(125, 125, 125); // white
  }
}

void loop() {
  Serial.println('Start');
  sensorValue = analogRead(sensorPin);
  batteryLevel += sensorValue;
  ticks += wait;

  if(batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.print(" ms   ");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity; // to prevent integer from continuing to increase
    ticks = 0;
    RGB_color(0, 125, 0); // Green for charging complete
    delay(30000); // Long pause
  } else {
    showBatteryPercentage();
  }
  delay(wait);
}