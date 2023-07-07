#include <RTClib.h>

#define BUTTON1 3
#define BUTTON2 4
#define BUTTON3 5
#define BUTTON4 12
#define BUTTON5 A0
RTC_DS3231 rtc;
int previousSec = 0;
bool button3State = 0;

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(BUTTON5, INPUT);
  rtc.begin();
  DateTime newDT = DateTime(2001, 9, 11, 14, 14, 0);
  rtc.adjust(newDT);
}

DateTime now = rtc.now();

void loop() {
  checkButtons();
  if (button3State) {
    if (now.second() > previousSec) {
      moveForward(1);
      if (now.second() == 59) {
        previousSec == -1;
      }
      else {
        previousSec = now.minute();
      }
    }
  }
  else {
    if (now.second() > previousSec) {
      moveForward(1);
      if (now.second() == 59) {
        previousSec == -1;
      }
      else {
        previousSec = now.minute();
      }
    }
  }
  delay(1);
}

void checkButtons() {
  if (digitalRead(BUTTON1)) {
    moveForward(1);
  }
  if (digitalRead(BUTTON2)) {
    moveBack(1);
  }
  if (digitalRead(BUTTON4)) {
    moveForward(60);
  }
  if (digitalRead(BUTTON5)) {
    moveBack(60);
  }
  if (digitalRead(BUTTON3)) {
    button3State = !button3State;
  }
}

void moveForward(bool) {
  
}

void moveBack(int times) {
}
