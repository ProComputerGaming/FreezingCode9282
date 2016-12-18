#ifndef FINGERBOT_H
#define FINGERBOT_H

const int MOTOR_NUM = kNumbOfTotalMotors;
const int MOTOR_MAX_VALUE = 127;
const int MOTOR_MIN_VALUE = -127;
const int MOTOR_DEFAULT_SLEW_RATE = 10;      // Default value of 10 will cause 375mS from full fwd to rev
																							//15 will cause 254 mS from full fwd to rev
const int MOTOR_FAST_SLEW_RATE = 256;   // essentially off
const int MOTOR_TASK_DELAY = 15;      // task 1/frequency in mS (about 66Hz)
const int MOTOR_DEADBAND = 10;
const int MOTOR_SLEW_TOTAL_TIME = ((MOTOR_MAX_VALUE * 2)/MOTOR_DEFAULT_SLEW_RATE) * MOTOR_TASK_DELAY;

enum WheelDirection{
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
};
float WHEEL_CIR=PI * 4;
float TOLERANCE = 1;
int FULL = (int)((360/WHEEL_CIR)*(PI*14.25) * TOLERANCE);
int QUARTER = FULL / 4;
int HALF = FULL / 2;
int THREE_QUARTER = FULL / 1.5;

int motorSlew[MOTOR_NUM];
int motorReq[MOTOR_NUM];
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
bool dLeftDirection = false;
bool dRightDirection = false;
bool runWheels = false;
bool leftDone = false;
bool rightDone = false;

bool runLift = false;

int lightArray[6];

task fingerMonitor();
task liftMonitor();
task lightMonitor();
task wheelMonitor();
task motorSlewTask();
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
              }
        }
}

task wheelMonitor(){
        while(true){
                while(runWheels){
                        if(abs(SensorValue(leftQuad)) < wheelTargetTicks){
                                switch(wheelDir){
                                        case FORWARD: dLeftDirection = false; break;
                                        case BACKWARD: dLeftDirection = true; break;
                                        case LEFT: dLeftDirection = true; break;
                                        case RIGHT: dLeftDirection = false; break;
                                }
                                dLeft(dLeftDirection);
                        }else{
                        	leftDone = true;
                        	stopLeft();
                      	}
                        if(abs(SensorValue(rightQuad)) < wheelTargetTicks){
                                switch(wheelDir){
                                        case FORWARD: dRightDirection = false; break;
                                        case BACKWARD: dRightDirection = true; break;
                                        case LEFT: dRightDirection = false; break;
                                        case RIGHT: dRightDirection = true; break;
                                }
                                dRight(dRightDirection);
                        }else{
                        	rightDone = true;
                        	stopRight();
                      	}
                        if(leftDone && rightDone)
                                runWheels = false;
                }
								stopDrive();
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
    }
}

task motorSlewTask()
{
    int motorIndex;
    int motorTmp;

    // Initialize stuff
    for(motorIndex=0;motorIndex<MOTOR_NUM;motorIndex++)
        {
        motorReq[motorIndex] = 0;
        motorSlew[motorIndex] = MOTOR_DEFAULT_SLEW_RATE;
        }

    // run task until stopped
    while( true )
        {
        // run loop for every motor
        for( motorIndex=0; motorIndex<MOTOR_NUM; motorIndex++)
            {
            // So we don't keep accessing the internal storage
            motorTmp = motor[ motorIndex ];

            // Do we need to change the motor value ?
            if( motorTmp != motorReq[motorIndex] )
                {
                // increasing motor value
                if( motorReq[motorIndex] > motorTmp )
                    {
                    motorTmp += motorSlew[motorIndex];
                    // limit
                    if( motorTmp > motorReq[motorIndex] )
                        motorTmp = motorReq[motorIndex];
                    }

                // decreasing motor value
                if( motorReq[motorIndex] < motorTmp )
                    {
                    motorTmp -= motorSlew[motorIndex];
                    // limit
                    if( motorTmp < motorReq[motorIndex] )
                        motorTmp = motorReq[motorIndex];
                    }

                // finally set motor
                motor[motorIndex] = motorTmp;
                }
            }

        // Wait approx the speed of motor update over the spi bus
        wait1Msec( MOTOR_TASK_DELAY );
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
	//if(vexRT[Ch2] >MOTOR_DEADBAND){
        motorReq[backRight] = vexRT[Ch2];
        motorReq[frontRight] = vexRT[Ch2];
      //}
     //if(vexRT[Ch3] > MOTOR_DEADBAND){
        motorReq[backLeft] = vexRT[Ch3];
        motorReq[frontLeft] = vexRT[Ch3];
      //}
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
        motorReq[backLeft] = backwards ?  -DRIVEBASE_POWER : DRIVEBASE_POWER;
        motorReq[frontLeft] = backwards ? -DRIVEBASE_POWER : DRIVEBASE_POWER;
}

void dRight(bool backwards){
        motorReq[backRight] = backwards ?  -DRIVEBASE_POWER : DRIVEBASE_POWER;
        motorReq[frontRight] = backwards ? -DRIVEBASE_POWER : DRIVEBASE_POWER;
}

void setSyncLift(int targetTicks){
        liftTargetTicks = targetTicks;
        runLift = true;
}

void dLift(bool down){
        motorReq[leftLiftY] = down ? -LIFT_POWER : LIFT_POWER;
        motorReq[rightLiftY] = down ? -LIFT_POWER : LIFT_POWER;
}

void strafeLeft(int millis){
        if(millis != 0){
                clearTimer(T1);
                while(time1[T1] < millis){
                        motorReq[backRight] = -127;
                        motorReq[frontRight] = 127;
                        motorReq[backLeft] = 127;
                        motorReq[frontLeft] = -127;
                }
                stopDrive();
        }else{
                motorReq[backRight] = -127;
                motorReq[frontRight] = 127;
                motorReq[backLeft] = 127;
                motorReq[frontLeft] = -127;
        }
}

void strafeRight(int millis){
        if(millis != 0){
                clearTimer(T1);
                while(time1[T1] < millis){
                        motorReq[backRight] = 127;
                        motorReq[frontRight] = -127;
                        motorReq[backLeft] = -127;
                        motorReq[frontLeft] = 127;
                }
                stopDrive();
        }else{
                motorReq[backRight] = 127;
                motorReq[frontRight] = -127;
                motorReq[backLeft] = -127;
                motorReq[frontLeft] = 127;
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
        motorReq[backLeft] = 0;
        motorReq[frontLeft] = 0;
}

void stopRight(){
        motorReq[backRight] = 0;
        motorReq[frontRight] = 0;
}

void stopDrive(){
        stopLeft();
        stopRight();
}

void stopLift(){
        motorReq[leftLiftY] = 0;
        motorReq[rightLiftY] = 0;
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
#endif
