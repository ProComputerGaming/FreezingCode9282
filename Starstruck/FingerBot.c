#include "FingerBot.h"

const int FULL_SPEED = 127;
const int OFF = 0;

int autonSelection = 0;
const int SEGMENTS = 8;
int autonTargetTicks = 0;
enum Direction dir = FORWARD;

bool downPressure = false;
bool runFinger = false;
bool fingerNeedsToOpen = false;
bool runWheels = false;
bool leftDone = false;
bool rightDone = false;

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

task wheelMonitor(){
        while(true){
                while(runWheels){
                    if(SensorValue(leftQuad) < autonTargetTicks){
          							switch(dir){
          								case FORWARD: dLeft(false); break;
          								case BACKWARD: dLeft(true); break;
          								case LEFT: dLeft(true); break;
          								case RIGHT: dLeft(false); break;
          							}
                    }else{
                    	leftDone = true;
                    	stopLeft();
                  	}

                    if(SensorValue(rightQuad) < autonTargetTicks){
												switch(dir){
          								case FORWARD: dRight(false); break;
          								case BACKWARD: dRight(true); break;
          								case LEFT: dRight(false); break;
          								case RIGHT: dRight(true); break;
          							}
                    }else{
                    	rightDone = true;
                    	stopRight();
                  	}

                  	if(leftDone && rightDone)
                  		runWheels = false;
                }

        }
}

void analogDrive(){
        motor[backRight] = vexRT[Ch2];
        motor[frontRight] = vexRT[Ch2];
        motor[backLeft] = vexRT[Ch3];
        motor[frontLeft] = vexRT[Ch3];
}

void setAutonMove(Direction d, int targetTicks){
	autonTargetTicks = targetTicks;
	dir = d;
	leftDone = false;
	rightDone = false;
	runWheels = true;

}

void dLeft(bool backwards){
   motor[backLeft] = backwards ?  -FULL_SPEED : FULL_SPEED;
   motor[frontLeft] = backwards ? -FULL_SPEED : FULL_SPEED;
}

void dRight(bool backwards){
   motor[backRight] = backwards ?  -FULL_SPEED : FULL_SPEED;
   motor[frontRight] = backwards ? -FULL_SPEED : FULL_SPEED;
}


void driveForward (int ticks){
        zeroDriveSensors();
        if(ticks != 0){
                while(abs(SensorValue(leftQuad)) < ticks || abs(SensorValue(rightQuad)) < ticks){
                        if(abs(SensorValue(leftQuad)) < ticks){
                                dLeft(false);
                        }else{
                                stopLeft();
                        }
                        if(abs(SensorValue(rightQuad)) < ticks){
                                dRight(false);
                        }else{
                                stopRight();
                        }
                }
                stopDrive();
        }else{
                dLeft(false);
                dRight(false);
        }
}

void driveBackward (int ticks){
        zeroDriveSensors();
        if(ticks != 0){
                while(abs(SensorValue(leftQuad)) < ticks || abs(SensorValue(rightQuad)) < ticks){
                        if(abs(SensorValue(leftQuad)) < ticks){
                                dLeft(true);
                        }else{
                                stopLeft();
                        }
                        if(abs(SensorValue(rightQuad)) < ticks){
                                dRight(true);
                        }else{
                                stopRight();
                        }
                }
                stopDrive();
        }else{
            dRight(true);
            dLeft(true);
        }
}

void turnRight(int ticks){
        zeroDriveSensors();
        if(ticks != 0){
                while(abs(SensorValue(leftQuad)) < ticks || abs(SensorValue(rightQuad)) < ticks){
                        if(abs(SensorValue(leftQuad)) < ticks){
                                dLeft(false);
                        }else{
                                stopLeft();
                        }
                        if(abs(SensorValue(rightQuad)) < ticks){
                                dRight(true);
                        }else{
                                stopRight();
                        }
                }
                stopDrive();
        }else{
                dRight(true);
                dLeft(false);
        }
}

void turnLeft(int ticks){
        zeroDriveSensors();
        if(ticks != 0){
                while(abs(SensorValue(leftQuad)) < ticks || abs(SensorValue(rightQuad)) < ticks){
                        if(abs(SensorValue(leftQuad)) < ticks){
                                dLeft(true);
                        }else{
                                stopLeft();
                        }
                        if(abs(SensorValue(rightQuad)) < ticks){
                                dRight(false);
                        }else{
                                stopRight();
                        }
                }
                stopDrive();
        }else{
                dLeft(true);
                dRight(false);
        }
}

void strafeLeft (int millis){
        if(millis != 0){
                clearTimer(T1);
                while(time1[T1] < millis){
                        motor[backRight] = -127;
                        motor[frontRight] = 127;
                        motor[backLeft] = 127;
                        motor[frontLeft] = -127;
                }
                stopDrive();
        }else{
                motor[backRight] = -127;
                motor[frontRight] = 127;
                motor[backLeft] = 127;
                motor[frontLeft] = -127;
        }
}

void strafeRight(int millis){
        if(millis != 0){
                clearTimer(T1);
                while(time1[T1] < millis){
                        motor[backRight] = 127;
                        motor[frontRight] = -127;
                        motor[backLeft] = -127;
                        motor[frontLeft] = 127;
                }
                stopDrive();
        }else{
                motor[backRight] = 127;
                motor[frontRight] = -127;
                motor[backLeft] = -127;
                motor[frontLeft] = 127;
        }
}

void raiseLift(int targetTicks){
        raiseLift(targetTicks, FULL_SPEED);
}

void raiseLift(int targetTicks, int speed){
        if(targetTicks != 0){
                while(abs(SensorValue(liftQuad)) < targetTicks){
                        motor[leftLiftY] = speed;
                        motor[rightLiftY] = speed;
                }
                stopLift();
        }else{
                motor[leftLiftY] = speed;
                motor[rightLiftY] = speed;
        }
}

void lowerLift(int targetTicks){
        lowerLift(targetTicks, FULL_SPEED);
}

void lowerLift(int targetTicks, int speed){
        if(targetTicks != 0){
                while(abs(SensorValue(liftQuad)) > targetTicks){
                        motor[leftLiftY] = -speed;
                        motor[rightLiftY] = -speed;
                }
                stopLift();
        }else{
                motor[leftLiftY] = -speed;
                motor[rightLiftY] = -speed;
        }
}

void closeClaw(int millis){
        if(millis != 0){
                clearTimer(T1);
                while(time1[T1] < millis){
                        motor[fingerY] = 127;
                }
                motor[fingerY] = 0;
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

void stopLeft(){
    motor[backLeft] = 0;
    motor[frontLeft] = 0;
}

void stopRight(){
    motor[backRight] = 0;
    motor[frontRight] = 0;
}

void stopDrive(){
    stopLeft();
    stopRight();
}

void stopLift(){
        motor[leftLiftY] = 0;
        motor[rightLiftY] = 0;
}

void stopAllMotors(){
    stopDrive();
    stopLift();
    motor[fingerY] = 0;
}

void zeroDriveSensors(){
        SensorValue(leftQuad) = 0;
        SensorValue(rightQuad) = 0;
}

void zeroAllSensors(){
        zeroDriveSensors();
        SensorValue(liftQuad) = 0;
}

int programSelected(int segments){
        int oneValue = clamp(SensorValue(potOne)/(4095 / segments),0,SEGMENTS - 1);
        int twoValue = clamp(SensorValue(potTwo)/(4095 / segments),0,SEGMENTS - 1);
        return oneValue + twoValue;
}

int clamp(int var, int min, int max){
        if(var > max){
                return max;
        }else if( var < min){
                return min;
        }else{
                return var;
        }
}
