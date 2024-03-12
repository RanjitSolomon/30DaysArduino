// C++ code

#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {9, 8, 7, 6};     // Arduino pins
byte colPins[COLS] = {5, 4, 3, 2};    //  Arduino pins

char buttons[ROWS][COLS] = {
  {'1','2','3','A'},   // 1st row
  {'4','5','6','B'},   // 2nd row
  {'7','8','9','C'},   // 3rd row
  {'*','0','#','D'}    // 4th row
};

Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

int tones[ROWS][COLS] = { // freqncy tone for each button
  { 31,  93, 147, 203},
  {247, 311, 370, 440},
  {523, 587, 698, 880},
  {1397, 2637, 3729, 4978}
};

int buzzer = 10; // pin drives the buzzer

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int toneFreq = 0;
  char result = myAwesomePad.getKey();

  if (result) { // if a button is pressed

    for(byte j=0; j<ROWS; j++) {
      for (byte i=0; i<COLS; i++){
        if(result == buttons[j][i]) {
          toneFreq=tones[j][i];
        }
      }
    }
    Serial.print("Key:  ");
    Serial.print(result);
    Serial.print("  Freq:  ");
    Serial.println(toneFreq);

    tone(buzzer, toneFreq, 500);  // and play tone for a half second
    delay(500);
    noTone(buzzer);
  }
}