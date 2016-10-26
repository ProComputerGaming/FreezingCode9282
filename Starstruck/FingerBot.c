int autonSelection = 0;
bool downPressure = false;
bool runFinger = false;
bool fingerNeedsToOpen = false;

int lightArray[6];


task fingerMonitor();
task lightMonitor();
void analogDrive();
void driveForward(int ticks);
void driveBackward(int ticks);
void turnRight(int ticks);
void turnLeft(int ticks);
void strafeRight(int millis);
void strafeLeft(int millis);
void raiseLift(int targetTicks);
void lowerLift(int targetTicks);
void closeClaw(int millis);
void openClaw();
void stopLift();
void stopDrive();
void stopAllMotors();
void zeroDriveSensors();
int programSelected(int segments);

task fingerMonitor(){
        fingerNeedsToOpen = (SensorValue[leftFingerSwitch] == 1 || SensorValue[rightFingerSwitch] == 1);
        while(true){
                if(downPressure == true && runFinger == false){
                        motor[fingerY] = 30;
                }else if(downPressure == false && runFinger == false){
                        motor[fingerY] = -5;
                }else if(runFinger == true){
                        fingerNeedsToOpen = (SensorValue[leftFingerSwitch] == 1 || SensorValue[rightFingerSwitch] == 1);
                }
                while(runFinger && fingerNeedsToOpen){
                        motor[fingerY] = -127;
                        fingerNeedsToOpen = (SensorValue[leftFingerSwitch] == 1 || SensorValue[rightFingerSwitch] == 1);
                        if(fingerNeedsToOpen == false){
                                runFinger = false;
                        }
                }
        }
}

task lightMonitor(){
        while(true){
                lightArray[0] = SensorValue(leftFrontLight);
                lightArray[1] = SensorValue(leftMidLight);
                lightArray[2] = SensorValue(leftBackLight);
                lightArray[3] = SensorValue(rightFrontLight);
                lightArray[4] = SensorValue(rightMidLight);
                lightArray[5] = SensorValue(rightBackLight);
                wait1Msec(2);
        }
}

void analogDrive(){
        motor[backRight] = vexRT[Ch2];
        motor[frontRight] = vexRT[Ch2];
        motor[backLeft] = vexRT[Ch3];
        motor[frontLeft] = vexRT[Ch3];
}

void driveForward (int ticks){
        zeroDriveSensors();
        if(ticks != 0){
                while(abs(SensorValue(leftQuad)) < ticks || abs(SensorValue(rightQuad)) < ticks){
                        if(abs(SensorValue(leftQuad)) < ticks){
                                motor[backLeft] = 127;
                                motor[frontLeft] = 127;
                        }else{
                                motor[backLeft] = 0;
                                motor[frontLeft] = 0;
                        }
                        if(abs(SensorValue(rightQuad)) < ticks){
                                motor[backRight] = 127;
                                motor[frontRight] = 127;
                        }else{
                                motor[backRight] = 0;
                                motor[frontRight] = 0;
                        }
                }
        }else{
                motor[backRight] = 127;
                motor[frontRight] = 127;
                motor[backLeft] = 127;
                motor[frontLeft] = 127;
        }
}

void driveBackward (int ticks){
        zeroDriveSensors();
        if(ticks != 0){
                while(abs(SensorValue(leftQuad)) < ticks || abs(SensorValue(rightQuad)) < ticks){
                        if(abs(SensorValue(leftQuad)) < ticks){
                                motor[backLeft] = -127;
                                motor[frontLeft] = -127;
                        }else{
                                motor[backLeft] = 0;
                                motor[frontLeft] = 0;
                        }
                        if(abs(SensorValue(rightQuad)) < ticks){
                                motor[backRight] = -127;
                                motor[frontRight] = -127;
                        }else{
                                motor[backRight] = 0;
                                motor[frontRight] = 0;
                        }
                }
        }else{
                motor[backRight] = -127;
                motor[frontRight] = -127;
                motor[backLeft] = -127;
                motor[frontLeft] = -127;
        }
}

void turnRight(int ticks){
        zeroDriveSensors();
        if(ticks != 0){
                while(abs(SensorValue(leftQuad)) < ticks || abs(SensorValue(rightQuad)) < ticks){
                        if(abs(SensorValue(leftQuad)) < ticks){
                                motor[backLeft] = 127;
                                motor[frontLeft] = 127;
                        }else{
                                motor[backLeft] = 0;
                                motor[frontLeft] = 0;
                        }
                        if(abs(SensorValue(rightQuad)) < ticks){
                                motor[backRight] = -127;
                                motor[frontRight] = -127;
                        }else{
                                motor[backRight] = 0;
                                motor[frontRight] = 0;
                        }
                }
        }else{
                motor[backRight] = -127;
                motor[frontRight] = -127;
                motor[backLeft] = 127;
                motor[frontLeft] = 127;
        }
}

void turnLeft(int ticks){
        zeroDriveSensors();
        if(ticks != 0){
                while(abs(SensorValue(leftQuad)) < ticks || abs(SensorValue(rightQuad)) < ticks){
                        if(abs(SensorValue(leftQuad)) < ticks){
                                motor[backLeft] = -127;
                                motor[frontLeft] = -127;
                        }else{
                                motor[backLeft] = 0;
                                motor[frontLeft] = 0;
                        }
                        if(abs(SensorValue(rightQuad)) < ticks){
                                motor[backRight] = 127;
                                motor[frontRight] = 127;
                        }else{
                                motor[backRight] = 0;
                                motor[frontRight] = 0;
                        }
                }

        }else{
                motor[backRight] = 127;
                motor[frontRight] = 127;
                motor[backLeft] = -127;
                motor[frontLeft] = -127;
        }
}

void strafeLeft (int millis){
        if(millis == 0){
                clearTimer(T1);
                while(time1[T1] < millis){
                        motor[backRight] = -127;
                        motor[frontRight] = 127;
                        motor[backLeft] = 127;
                        motor[frontLeft] = -127;
                }
        }else{
                motor[frontRight] = 127;
                motor[backLeft] = 127;
                motor[frontLeft] = -127;
        }
}

void strafeRight(int millis){
        if(millis == 0){
                clearTimer(T1);
                while(time1[T1] < millis){
                        motor[backRight] = 127;
                        motor[frontRight] = -127;
                        motor[backLeft] = -127;
                        motor[frontLeft] = 127;
                }
        }else{
                motor[frontRight] = -127;
                motor[backLeft] = -127;
                motor[frontLeft] = 127;
        }
}

void raiseLift(int targetTicks){
        if(targetTicks != 0){
                while(SensorValue(liftQuad) < targetTicks){
                        motor[leftLiftY] = 127;
                        motor[rightLiftY] = 127;
                }
                stopLift();
        }else{
                motor[leftLiftY] = 127;
                motor[rightLiftY] = 127;
        }
}

void lowerLift(int targetTicks){
        if(targetTicks != 0){
                while(SensorValue(liftQuad) > targetTicks){
                        motor[leftLiftY] = -127;
                        motor[rightLiftY] = -127;
                }
                stopLift();
        }else{
                motor[leftLiftY] = -127;
                motor[rightLiftY] = -127;
        }
}

void closeClaw(int millis){
        if(millis == 0){
                clearTimer(T1);
                while(time1[T1] < millis){
                        motor[fingerY] = 127;
                }
        }else{
                motor[fingerY] = 127;
        }
        downPressure = true;
}

void openClaw(){
        motor[fingerY] = -127;
        downPressure = false;
        fingerNeedsToOpen = true;
        runFinger = true;
}

void stopDrive(){
        motor[backRight] = 0;
        motor[frontRight] = 0;
        motor[backLeft] = 0;
        motor[frontLeft] = 0;
}

void stopLift(){
        motor[leftLiftY] = 0;
        motor[rightLiftY] = 0;
}

void stopAllMotors(){
        motor[backRight] = 0;
        motor[frontRight] = 0;
        motor[backLeft] = 0;
        motor[frontLeft] = 0;
        motor[leftLiftY] = 0;
        motor[rightLiftY] = 0;
        motor[fingerY] = 0;
}

void zeroDriveSensors(){
        SensorValue(leftQuad) = 0;
        SensorValue(rightQuad) = 0;
}

int programSelected(int segments){
        int oneValue = (4095 / segments)/SensorValue(potOne);
        int twoValue = (4095 / segments)/SensorValue(potTwo);

        return oneValue + twoValue;
}
