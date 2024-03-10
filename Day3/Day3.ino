int LED = 12;
int SWITCH = 2;
int buttonState = 0;
int BUZZER = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(SWITCH);
  // put your main code here, to run repeatedly:
  if (buttonState == HIGH){
    Serial.print("Switch On \n");
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
    delay(500);
  } else {
    Serial.print("Switch Off \n");
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

}
