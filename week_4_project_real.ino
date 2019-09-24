#include <Servo.h>
#include "pitches.h"


Servo myservo;

int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode (12, OUTPUT);

  pinMode (11, OUTPUT);

  pinMode (10, OUTPUT);


  myservo.attach(9);
  pinMode(4, INPUT);
}

void loop() {
  int yellowbutton = digitalRead(4);
  int bluebutton = digitalRead(6);
  int greenbutton = digitalRead(7);
  Serial.println(yellowbutton);


  for (pos = 0; pos <= 180; pos += 1) {

    myservo.write(pos);
    delay(3);

    if (yellowbutton == HIGH) {
      digitalWrite(12, HIGH);
      tone(2, NOTE_C5, 4);

    } else if (bluebutton == HIGH) {
      digitalWrite(11, HIGH);
      tone(2, NOTE_D5, 4);

    } else if (greenbutton == HIGH) {
      digitalWrite(10, HIGH);
      tone(2, NOTE_E5, 4);

    } else {
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      noTone(2);


    }
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(3);


  }
}
