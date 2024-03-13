#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte PassLength = 4; // passwords will be 4 characters long
char currentPassword[PassLength] = {'0', '0', '0', '0'};  // default before setting

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

int unlockMode() {
  char result;

  Serial.println("Unlock Mode: Type Password to continue");
  delay(500);

  for(int i=0; i<PassLength; i++) {
    while(!(result=myAwesomePad.getKey())) {
      // wait indefinitely for keypad input of any kind
    }
    if(currentPassword[i] != result) { // a wrong key was pressed
      Serial.println("WRONG PASSWORD");
      Serial.println(result);
      return -1;                      // -1 means failed - return immediatly
    }
    Serial.print("*"); // Print a phantom character for a successful keystroke
  } // Done after 4 characters are accepted

  Serial.println("");
  Serial.println("Device Successfully Unlocked!");
  return 0;     // 0 means succeeded
}

void setup() {
  Serial.begin(9600); // Begin monitoring via the serial monitor
  delay(2000);
  Serial.println("Press * to set a new password. ");
  Serial.println("Press # to access the systems with the existing one. ");
}

void loop() {
  char result = myAwesomePad.getKey();

  if(result == '*') {  // choice to change password
    int access = unlockMode();

    if(access < 0) {
      Serial.println("Access Denied. Cannot change password without knowing the previous password");
    } else {
      Serial.println("Welcome, authorized user. Please enter a new password: ");
      delay(500);

      for(int i=0; i<PassLength; i++) {
        while(!(result = myAwesomePad.getKey())) {
          // wait indefinitely for keypad input of any kind
        }

        currentPassword[i] = result;
        Serial.print("*"); // print a phantom character for a successful keystroke
      } // done after 4 characters are accepted

      Serial.println("");
      Serial.println("Password Successfully Changed!");
    }
  }
  else if (result == '#') { // choice to access system with current password
    int access = unlockMode();
    if(access < 0) {
      Serial.println("Password error. Access Denied");      
    } else {
      Serial.println("Welcome, authorized user. You may begin using the system.");
    }
  }
}