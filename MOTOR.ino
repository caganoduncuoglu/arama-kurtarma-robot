void setMotors(int RightSpeed, int LeftSpeed) {
  if (RightSpeed > 0) {
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, LOW);
  }
   else {
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
  }
  if (LeftSpeed > 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } 
  else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  analogWrite(enA,abs(RightSpeed));
  analogWrite(enB,abs(LeftSpeed));
  }


void goForward(){  // DÜZ GİT
  leftEnc.write(0);
  while(true){
  setMotors(defaultRightSpeed,defaultLeftSpeed);
  long leftPos = leftEnc.read();
  double stepp = leftPos / (298.0 * 12);
  Serial.println(stepp);
   if (stepp >= 5) 
       break;
  }
  resetEncoders();
  setMotors(0,0);
}




void turnLeft() {
  goLeftStep(0.07);

  setMotors(-defaultRightSpeed / 2, defaultLeftSpeed / 2);
  delay(100);
  setMotors(0, 0);
}

void turnRight() {
  goRightStep(0.43);

  setMotors(defaultRightSpeed / 2, -defaultLeftSpeed / 2);
  delay(100);
  setMotors(0, 0);
}

void turnBack() {
  goBackStep(0.96);

  setMotors(defaultRightSpeed / 2, -defaultLeftSpeed / 2);
  delay(100);
  setMotors(0, 0);
}
