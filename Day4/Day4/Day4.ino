int led1 = 10;
int led2 = 11;
int led3 = 12;
int swi1 = 2;
int swi2 = 3;
int swi3 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(swi1, INPUT);
  pinMode(swi2, INPUT);
  pinMode(swi3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(swi1) == HIGH) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  if (digitalRead(swi2) == HIGH) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
  if (digitalRead(swi3) == HIGH) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }

}