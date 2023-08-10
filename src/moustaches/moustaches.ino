#include <AccelStepper.h>


AccelStepper motorLeft(AccelStepper::FULL4WIRE, 2, 4, 3, 5);
AccelStepper motorRight(AccelStepper::FULL4WIRE, 6, 8, 7, 9);

#define moustacheGauche 10
#define moustacheDroite 11
int tournant 500;
boolean manoeuvre = false;

void setup() {
  pinMode(moustacheGauche, INPUT_PULLUP);
  pinMode(moustacheDroite, INPUT_PULLUP);

  motorLeft.setMaxSpeed(200.0);
  motorLeft.setAcceleration(100.0);
  motorLeft.moveTo(500);

  motorRight.setMaxSpeed(200.0);
  motorRight.setAcceleration(100.0);
  motorRight.moveTo(500);
}

void loop() {

  if (!motorLeft.isRunning()) {
    motorLeft.move(2400);
    motorRight.move(2400);
    manoeuvre = false;
  }


  if (digitalRead(moustacheGauche) == HIGH && digitalRead(moustacheDroite) == HIGH) {
    //motor run
  } else if (digitalRead(moustacheGauche) == HIGH && digitalRead(moustacheDroite) == LOW) {
    if (!manoeuvre) {
      motorLeft.stop();
      motorRight.stop();
      motorLeft.move(tournant);
      motorRight.move(tournant * -1);
      manoeuvre = true;
    }

    // back and turn left
  } else if (digitalRead(moustacheGauche) == LOW && digitalRead(moustacheDroite) == HIGH) {
    //back and turn right
    if (!manoeuvre) {
      motorLeft.stop();
      motorRight.stop();
      motorLeft.move(tournant * -1);
      motorRight.move(tournant);
      manoeuvre = true;
    }
  } else {
    //back
    if (!manoeuvre) {
      motorLeft.stop();
      motorRight.stop();
      motorLeft.move(tournant * -1);
      motorRight.move(tournant * -1);
      manoeuvre = true;
    }
  }

  motorLeft.run();
  motorRight.run();
}