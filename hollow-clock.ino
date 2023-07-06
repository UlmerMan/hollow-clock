#include <RTClib.h>

#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3
#define BUTTON4 4

RTC_DS3231 myRTC;
int previousMin;
bool button3State = 0, button4State = 0;

void setup() {
  myRTC.begin();
  DateTime newDT = DateTime(2001, 9, 11, 14, 14, 0);
  myRTC.adjust(newDT);
}

void loop() {
  checkButtons();
  delay(1);
}

void checkButtons() {
  if (digitalRead(BUTTON1)) {
    moveForward(1);
  }
  if (digitalRead(BUTTON2)) {
    moveBack(1);
  }
  if (digitalRead(BUTTON3)) {
    button3State = !button3State;
  }
  if (digitalRead(BUTTON4)) {
    button4State = !button4State;
  }
}

void checkTime() {
  DateTime dt = myRTC.now();
  if (dt.minute() == previousMin + 1) {
    previousMin == dt.minute();

    if (previousMin == 60) {
      previousMin = 0;
    }
  }
}

void moveForward(int times) {
}

void moveBack(int times) {
}