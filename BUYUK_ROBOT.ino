#include <Encoder.h>
#include <PID_v1.h>

#define qtr 8
#define lim 9

const byte IN1 = 44, IN2 = 45;
const byte IN3 = 46, IN4 = 47;
const byte enA = 4, enB = 5;

const byte encLeft1 = 20, encLeft2 = 21;
const byte encRight1 = 19, encRight2 = 18;
const byte qtrPins[] = {22, 23, 24, 25, 26, 27, 28, 29};
int defaultLeftSpeed = 38;
int defaultRightSpeed = 48;
Encoder leftEnc(encLeft2, encLeft1);
Encoder rightEnc(encRight1, encRight2);
double Setpoint, Input, Output;

int qtrVal[] = {0, 0, 0, 0, 0, 0, 0, 0};


int positionLast;
int pos;

float kp = 3;
float ki = 0.03;
float kd = 0.5;



void setup() {
  Serial.begin(9600);
    defineQtr();
    defineMotors();
    //setMotors(defaultRightSpeed, defaultLeftSpeed);
    initPID();
    //goLeftStep(0.07);
    //goRightStep(0.13);
    //goBackStep(0.5);
    //goForward();
    }


void loop() {
    followLine();
    //readQtr();
   //setMotors(defaultRightSpeed, defaultLeftSpeed);
}
