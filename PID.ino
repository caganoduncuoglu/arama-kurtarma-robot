

PID myPID(&Input, &Output, &Setpoint, kp, ki, kd, DIRECT);



void initPID() {  
  Setpoint = 0;
  Input = 0;
  myPID.SetOutputLimits(-255, 255);               
  myPID.SetMode(AUTOMATIC);
}



void followLine() {      //ÇİZGİ TAKİP
  pos = getPosition();
  positionLast = pos;
  Input = pos; 
  myPID.Compute();
  setMotors(defaultRightSpeed + Output, defaultLeftSpeed - Output);

}
