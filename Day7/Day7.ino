// C++ code
//
int sensor = A0;
int led = 13;
int sensorValue = 0;
// int -32000 to +32000
// unsigned int 0 to 64000
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double percentFull;


void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void PrintBatteryPercentage() {
  // Print the elapsed time
  Serial.print(ticks);
  Serial.print(" ms charge at ");

  // convert the integers to decimal numbers, divide them and print ...
  percentFull = 100 * ((double)batteryLevel / (double)batteryCapacity);
  Serial.print(percentFull);

  // print a percent character and line return...
  Serial.println("%");
}

void loop() {
  // Pulse the built in LED for a time determined by the sensor
  sensorValue = analogRead(sensor);
  batteryLevel += sensorValue;
  ticks += wait;

  if (batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.print(" ms   ");
    Serial.print(batteryLevel);
    Serial.println(" FULLY CHARGED");
    batteryLevel = batteryCapacity; // to prevent integer from continuing to increase
    ticks = 0;
    delay(20000); // long pause
  }
  else {
    PrintBatteryPercentage();
  }

  delay(wait);
}

// 3 binary digit can only produce 8 numbers
// 000, 001, 010, 011, 100, 101, 110, 111
// int -32000 to +32000
// unsigned 0 to 64000

// float
// 30000 = 3 x 10^4
// up to 10^38

//double
// up to 10^308