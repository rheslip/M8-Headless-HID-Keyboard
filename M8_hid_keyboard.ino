
// quick and dirty Dirtywave M8 HID keyboard for Pi Pico for use with M8C web interface and M8 headless
// uses default M8 web keyboard keys - left shift, x,z, space and arrow keys
// RH dec 26,2023

#include "Keyboard.h"

// set pin numbers for the buttons:
const int upButton = 4;
const int downButton = 14;
const int leftButton = 15;
const int rightButton = 5;
const int shiftButton = 17;
const int playButton = 16;
const int optButton = 3;
const int editButton = 2;

bool up=0;
bool down=0;
bool left=0;
bool right=0;
bool shift=0;
bool play=0;
bool opt=0;
bool edit=0;

void setup() {  // initialize the buttons' inputs:
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(shiftButton, INPUT_PULLUP);
  pinMode(playButton, INPUT_PULLUP);
  pinMode(optButton, INPUT_PULLUP);
  pinMode(editButton, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {


  // use the pushbuttons to control the keyboard:
  if (digitalRead(upButton) == LOW) {
    if (!up) Keyboard.press(0xda);
    up=true;
  }
  else {
    Keyboard.release(0xda);
    up=false;
  }

  if (digitalRead(downButton) == LOW) {
    if (!down) Keyboard.press(0xd9);
    down=true;
  }
  else {
    Keyboard.release(0xd9);
    down=false;
  }

  if (digitalRead(leftButton) == LOW) {
    if (!left) Keyboard.press(0xd8);
    left=true;
  }
  else {
    Keyboard.release(0xd8);
    left=false;
  }

  if (digitalRead(rightButton) == LOW) {
    if (!right) Keyboard.press(0xd7);
    right=true;
  }
  else {
    Keyboard.release(0xd7);
    right=false;
  }


  if (digitalRead(shiftButton) == LOW) {
    if (!shift) Keyboard.press(0x81);
    shift=true;
  }
  else {
    Keyboard.release(0x81);
    shift=false;
  }

  if (digitalRead(playButton) == LOW) {
    if (!play) Keyboard.press(' ');
    play=true;
  }
  else {
    Keyboard.release(' ');
    play=false;
  }

  if (digitalRead(optButton) == LOW) {
    if (!opt) Keyboard.press('z');
    opt=true;
  }
  else {
    Keyboard.release('z');
    opt=false;
  }

  if (digitalRead(editButton) == LOW) {
    if (!edit) Keyboard.press('x');
    edit=true;
  }
  else {
    Keyboard.release('x');
    edit=false;
  }
}

