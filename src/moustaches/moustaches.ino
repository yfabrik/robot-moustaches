// For two motors instance at once
#include <L298NX2.h>

#define EN_A 7
#define IN1_A 8
#define IN2_A 9
#define EN_B 10
#define IN1_B 11
#define IN2_B 12

L298NX2 myMotors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

#define moustacheGauche 10
#define moustacheDroite 11

int tournant = 500;
boolean manoeuvre = false;

void setup() {
  pinMode(moustacheGauche, INPUT_PULLUP);
  pinMode(moustacheDroite, INPUT_PULLUP);

  myMotors.setSpeed(100);
}

void loop() {

  myMotors.forward();

  if (digitalRead(moustacheGauche) == HIGH && digitalRead(moustacheDroite) == HIGH) {
    //motor run
  } else if (digitalRead(moustacheGauche) == HIGH && digitalRead(moustacheDroite) == LOW) {
    if (!manoeuvre) {
      myMotors.backwardFor(2000);
      myMotors.backwardForA(1000);
      myMotors.forwardForB(1000);


      manoeuvre = true;
    }

    // back and turn left
  } else if (digitalRead(moustacheGauche) == LOW && digitalRead(moustacheDroite) == HIGH) {
    //back and turn right
    if (!manoeuvre) {
      myMotors.backwardFor(2000);
      myMotors.backwardForB(1000);
      myMotors.forwardForA(1000);


      manoeuvre = true;
    }
  } else {
    //back
    if (!manoeuvre) {
      myMotors.backwardFor(2000);

      manoeuvre = true;
    }
  }
}