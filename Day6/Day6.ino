int sensor = A0;
int led = 13;
int sensorValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop(){
	sensorValue = analogRead(sensor);
  	digitalWrite(led, HIGH);
  	delay(sensorValue);
  	digitalWrite(led, LOW);
  	delay(sensorValue);
	Serial.println(sensorValue);
}