void goLeftStep(double target) {  // SOLA DÖN
    rightEnc.write(0);
    while (true) {
  setMotors(defaultRightSpeed, -defaultLeftSpeed);
  long rightPos = rightEnc.read();
  double stepp = rightPos / (298.0 * 12);
  Serial.println(-stepp);
  if (-stepp >= target) 
     break;
  }
  resetEncoders();
  setMotors(0,0);
}

void goRightStep(double target) {  //SAĞA DÖN
       leftEnc.write(0);
       while (true) {
    setMotors(-defaultRightSpeed, defaultLeftSpeed);
    long leftPos = leftEnc.read();
    double stepp = leftPos / (298.0 * 12);
     Serial.println(stepp);
     if (stepp >= target) 
       break;
  }
  resetEncoders();
  setMotors(0,0);
}

void goBackStep(double target) {  // GERİ DÖN
  leftEnc.write(0);               // SOL ENCODER SIFIRLANDI
  while (true) {
    setMotors(-defaultRightSpeed , defaultLeftSpeed);  
    long leftPos = leftEnc.read();
    double stepp = leftPos / (298.0 * 12);
         Serial.println(stepp);
    if (stepp >= target) 
      break;
  }
  resetEncoders();
  setMotors(0,0);
}

void resetEncoders() { 
  leftEnc.write(0);
  rightEnc.write(0);
}

double encError() {
  long leftPos = leftEnc.read();
  long rightPos = rightEnc.read();
  double leftStep = leftPos / (297.92 * 12);
  double rightStep = rightPos / (297.92 * 12);
  //  Serial.print("left step: ");
  //  Serial.print(leftStep);
  //  Serial.print("***Right step: ");
  //  Serial.println(rightStep);
  return (rightStep - leftStep);
}
