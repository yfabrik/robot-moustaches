#include <AccelStepper.h>


AccelStepper motorLeft;
AccelStepper motorRight(AccelStepper::FULL4WIRE, 6, 7, 8, 9);

#define moustacheGauche 10
#define moustacheDroite 11

boolean manoeuvre = false;

void setup() {
  pinMode(moustacheGauche, INPUT_PULLUP);
  pinMode(moustacheDroite, INPUT_PULLUP);

  motorLeft.setMaxSpeed(200.0);
  motorLeft.setAcceleration(100.0);
  motorLeft.moveTo(24);

  motorRight.setMaxSpeed(200.0);
  motorRight.setAcceleration(100.0);
  motorRight.moveTo(24);
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
      motorLeft.move(50);
      motorRight.move(-50);
      manoeuvre = true;
    }

    // back and turn left
  } else if (digitalRead(moustacheGauche) == LOW && digitalRead(moustacheDroite) == HIGH) {
    //back and turn right
    if (!manoeuvre) {
      motorLeft.stop();
      motorRight.stop();
      motorLeft.move(-50);
      motorRight.move(50);
      manoeuvre = true;
    }
  } else {
    //back
    if (!manoeuvre) {
      motorLeft.stop();
      motorRight.stop();
      motorLeft.move(-50);
      motorRight.move(-50);
      manoeuvre = true;
    }
  }

  motorLeft.run();
  motorRight.run();
}