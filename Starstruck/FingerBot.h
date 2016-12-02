
enum WheelDirection{
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
};

const int QUARTER = 250;
const int HALF = QUARTER * 2;
const int THREE_QUARTER = QUARTER * 3;
const int FULL = QUARTER * 4;

int DRIVEBASE_POWER = 127;
int CLAW_POWER = 127;
int LIFT_POWER = 127;
const int OFF = 0;

int autonSelection = 0;
bool inAutonomous = false;

const int SEGMENTS = 8;
int wheelTargetTicks = 0;
int liftTargetTicks = 0;

bool downPressure = false;
bool runFinger = false;
bool fingerNeedsToOpen = false;

enum WheelDirection wheelDir = FORWARD;
bool runWheels = false;
bool leftDone = false;
bool rightDone = false;

bool runLift = false;

int lightArray[6];

task fingerMonitor();
task liftMonitor();
task lightMonitor();
task wheelMonitor();
void analogDrive();
void waitForTasks();
void setSyncMove(WheelDirection d,int targetTicks);
void dLeft(bool backwards);
void dRight(bool backwards);
void setSyncLift(int targetTicks);
void dLift(bool down);
void strafeRight(int millis);
void strafeLeft(int millis);
void closeClaw(int millis);
void openClaw();
void stopLift();
void stopLeft();
void stopRight();
void stopDrive();
void stopAllMotors();
void zeroDriveSensors();
int programSelected(int segments);
int clamp(int var, int min, int max);

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
                        if(fingerNeedsToOpen == false || (vexRT[Btn5D] == 1 && inAutonomous == false)){
                                runFinger = false;
                        }
                        EndTimeSlice();
                }
                EndTimeSlice();
        }
}

task wheelMonitor(){
        while(true){
                while(runWheels){
                        if(abs(SensorValue(leftQuad)) < wheelTargetTicks){
                                switch(wheelDir){
                                        case FORWARD: dLeft(false); break;
                                        case BACKWARD: dLeft(true); break;
                                        case LEFT: dLeft(true); break;
                                        case RIGHT: dLeft(false); break;
                                }
                        }else{
                                leftDone = true;
                                stopLeft();
                        }

                        if(abs(SensorValue(rightQuad)) < wheelTargetTicks){
                                switch(wheelDir){
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
								stopDrive();
								EndTimeSlice();
        }
}

task liftMonitor(){
    while(true){
        while(runLift){
            if(abs(SensorValue(liftQuad)) < liftTargetTicks){
                dLift(false);
            }else if(abs(SensorValue(liftQuad)) > liftTargetTicks){
                dLift(true);
            }else{
                stopLift();
                runLift = false;
            }
        }
        EndTimeSlice();
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

void waitForTasks(){
    while(runFinger == true || runWheels == true || runLift == true){

    }
}

void setSyncMove(WheelDirection d, int targetTicks){
        wheelTargetTicks = targetTicks;
        wheelDir = d;
        leftDone = false;
        rightDone = false;
        zeroDriveSensors();
        runWheels = true;

}

void dLeft(bool backwards){
        motor[backLeft] = backwards ?  -DRIVEBASE_POWER : DRIVEBASE_POWER;
        motor[frontLeft] = backwards ? -DRIVEBASE_POWER : DRIVEBASE_POWER;
}

void dRight(bool backwards){
        motor[backRight] = backwards ?  -DRIVEBASE_POWER : DRIVEBASE_POWER;
        motor[frontRight] = backwards ? -DRIVEBASE_POWER : DRIVEBASE_POWER;
}

void setSyncLift(int targetTicks){
        liftTargetTicks = targetTicks;
        runLift = true;
}

void dLift(bool down){
        motor[leftLiftY] = down ? -LIFT_POWER : LIFT_POWER;
        motor[rightLiftY] = down ? -LIFT_POWER : LIFT_POWER;
}

void strafeLeft(int millis){
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

void closeClaw(int millis){
        if(millis != 0){
                clearTimer(T1);
                while(time1[T1] < millis){
                        motor[fingerY] = CLAW_POWER;
                }
                motor[fingerY] = 0;
        }else{
                motor[fingerY] = CLAW_POWER;
        }
        downPressure = true;
}

void openClaw(){
        motor[fingerY] = -CLAW_POWER;
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
