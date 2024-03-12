
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

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char result = myAwesomePad.getKey();
  if (result) {
    Serial.println(result);
  }
}