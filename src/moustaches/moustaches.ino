// For two motors instance at once
#include <L298NX2.h>

#define EN_A 9
#define IN1_A 8
#define IN2_A 7

#define EN_B 10
#define IN1_B 5
#define IN2_B 6

L298NX2 myMotors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

#define moustacheGauche 3
#define moustacheDroite 4



void setup() {
  pinMode(moustacheGauche, INPUT_PULLUP);
  pinMode(moustacheDroite, INPUT_PULLUP);

  //motor speed si alim en 6v -> 255 = 6V ; 127 = 3v
  myMotors.setSpeed(250);
}

void loop() {
  if (digitalRead(moustacheGauche) == HIGH && digitalRead(moustacheDroite) == HIGH) {
    myMotors.forward();

  } else if (digitalRead(moustacheGauche) == HIGH && digitalRead(moustacheDroite) == LOW) {
    // back and turn left
    myMotors.stop();
    delay(1000);
    myMotors.backward();
    delay(1000);
    myMotors.stop();
    delay(1000);
    myMotors.backwardA();
    myMotors.forwardB();
    delay(500);
  } else if (digitalRead(moustacheGauche) == LOW && digitalRead(moustacheDroite) == HIGH) {
    //back and turn right
    myMotors.stop();
    delay(1000);
    myMotors.backward();
    delay(1000);
    myMotors.stop();
    delay(1000);
    myMotors.backwardB();
    myMotors.forwardA();
    delay(500);
    // }
  } else {
    //back
    myMotors.backwardFor(2000);

    // }
  }
}