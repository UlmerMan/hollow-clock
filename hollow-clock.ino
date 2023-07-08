//Includes the Librarys
#include <Stepper.h>
#include <RTClib.h>

#define BUTTON1 3
#define BUTTON2 4
#define BUTTON3 5
#define BUTTON4 12
#define BUTTON5 A0
//RTC variables and stuf
RTC_DS3231 rtc;
int previousSec = 0;
bool button3State = 0;
DateTime now = rtc.now();

float soll;

// Defines the number of steps per rotation
const int stepsPerRevolution = 2048;

int TimeSetEverySec = 1;
float TurnBy = TimeSetEverySec*5.12 ; 

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);


 
void setup() {
    //Stepper Setup
    pinMode(7, OUTPUT);
    Serial.begin(9600);
    digitalWrite(7, HIGH);
    myStepper.setSpeed(10);
    //RTC Setup
    pinMode(BUTTON1, INPUT);
    pinMode(BUTTON2, INPUT);
    pinMode(BUTTON3, INPUT);
    pinMode(BUTTON4, INPUT);
    pinMode(BUTTON5, INPUT);
    rtc.begin();
    DateTime newDT = DateTime(2001, 9, 11, 14, 14, 0);
    rtc.adjust(newDT);
}

void loop() {
 Turn();
 checkButtons();
}

void Turn(){
 soll += TurnBy;
  while(soll>=1){
   myStepper.step(1);
   soll--;
  }
}

void checkButtons() {

  if (digitalRead(BUTTON1)) {
    soll += 307.2;
  }

  // if (digitalRead(BUTTON2)) {
  //  moveBack(1);
  // }

  if (digitalRead(BUTTON4)) {
   soll += 307.2;
  }

  //if (digitalRead(BUTTON5)) {
  //moveBack(60);
  //}

  if (digitalRead(BUTTON3)) {
  button3State = !button3State;
  }
  
}

