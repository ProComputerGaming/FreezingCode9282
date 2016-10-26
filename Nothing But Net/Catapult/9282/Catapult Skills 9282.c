#pragma config(Sensor, in1,    expander,       sensorAnalog)
#pragma config(Sensor, in2,    ,               sensorAnalog)
#pragma config(Sensor, dgtl1,  armQuad,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  gateSwitch,     sensorDigitalIn)
#pragma config(Sensor, dgtl4,  armSwitch,      sensorDigitalIn)
#pragma config(Sensor, dgtl5,  gateQuad,       sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  leftSonar,      sensorSONAR_cm)
#pragma config(Sensor, dgtl9,  backLeftSonar,  sensorSONAR_cm)
#pragma config(Sensor, dgtl11, backRightSonar, sensorSONAR_cm)
#pragma config(Motor,  port2,           yOne,          tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           yTwo,          tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           yThree,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           gate,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           frontRight,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           backRight,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           backLeft,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           frontLeft,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          intake,        tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"
#include "catapult.c"

//Sonar Values for autonomous movement
const int SONIC_STOP_SIDEWAYS = 40;
const int SONIC_STOP_FB = 13;
const int SONIC_STOP_AIM_LEFT = 46;
const int SONIC_STOP_AIM_RIGHT = 54;
float powerDivider = 4;
bool isLeftAimAligned = false;
bool isRightAligned = false;
bool isLeftAligned = false;

task alignLeftAim(){
	while(true){
		while(!isLeftAimAligned){
			if(SensorValue[backLeftSonar] > SONIC_STOP_AIM_LEFT){

				wait1Msec(50);
				while(SensorValue[backLeftSonar] > SONIC_STOP_AIM_LEFT){
					drive(true,true,FULL_POWER / powerDivider);
				}
				stopAllDrive();

				}else{
				wait1Msec(50);
				while(SensorValue[backLeftSonar] < SONIC_STOP_AIM_LEFT){
					drive(true,false,FULL_POWER / powerDivider);
				}
				stopAllDrive();
			}
		}
	}
}

task alignRightAim(){
	while(true){
		while(!isRightAligned){
			if(SensorValue[backRightSonar] > SONIC_STOP_AIM_RIGHT){

				wait1Msec(50);
				while(SensorValue[backRightSonar] > SONIC_STOP_AIM_RIGHT){
					drive(false,true,FULL_POWER / powerDivider);
				}
				stopAllDrive();

				}else{
				wait1Msec(50);
				while(SensorValue[backRightSonar] < SONIC_STOP_AIM_RIGHT){
					drive(false,false,FULL_POWER / powerDivider);
				}
				stopAllDrive();
			}
		}
	}
}

task alignLeft(){
	while(true){
		while(!isLeftAligned){
			if(SensorValue[leftSonar] > SONIC_STOP_SIDEWAYS){
				//wait1Msec(50);
				while(SensorValue[leftSonar] > SONIC_STOP_SIDEWAYS){
					mechanumDrive(true);
				}
				stopAllDrive();

				}else{
				//wait1Msec(50);
				while(SensorValue[leftSonar] < SONIC_STOP_SIDEWAYS){
					mechanumDrive(false);
				}
				stopAllDrive();
			}
			isLeftAligned = true;
		}
	}
}


//Align left side of robot with back wall using SONIC_STOP_FB value
void alignBackLeftFB(){
	wait1Msec(50);
	while(SensorValue[backLeftSonar] > SONIC_STOP_FB){
		drive(true,true,FULL_POWER / 4);
	}
	stopAllDrive();
}

//Align right side of robot with back wall using SONIC_STOP_FB value
void alignBackRightFB(){
	wait1Msec(50);
	while(SensorValue[backRightSonar] > SONIC_STOP_FB){
		drive(false,true,FULL_POWER / 4);
	}

	stopAllDrive();
}

//Move robot left until it is a set distance away from the side wall
void alignLeftSide(bool goingLeft){
	if(goingLeft){

		wait1Msec(50);
		while(SensorValue[leftSonar] > SONIC_STOP_SIDEWAYS){
			mechanumDrive(true);
		}
		stopAllDrive();

		}else{
		wait1Msec(50);
		while(SensorValue[leftSonar] < SONIC_STOP_SIDEWAYS){
			mechanumDrive(false);
		}
		stopAllDrive();
	}
}

task autonomous(){
	//Tell firing routine this is a skills run
	skills = true;

	//Set arm and gate to initial positions
	setGate(GATE_OPEN);
	setArm(ARM_LOAD);

	//Zero Sensors
	resetSensors();

	//Turn intake on
	motor[intake] = -127;

	//Start gate and arm monitoring processes
	startTask(armPosition);
	startTask(gatePosition);

	//Tweak Powers for the longer distance
	midPower = 60;
	mechanumPower = 127;

	//Shoot 32 balls
	ballCount = 0;

	while(ballCount < 32){
		setArm(ARM_FIRE);
		setDistance(MID);
		if(time1[T2] > 2500){
			override = true;
		}
	}
	wait1Msec(400);
	//Make robot parallel with back wall
	alignBackLeftFB();

	alignBackRightFB();

	alignBackLeftFB();

	alignBackRightFB();

	//Drive forward to avoid ball triangle
	drive(true,false,127);
	drive(false,false,127);
	wait1Msec(200);
	stopAllDrive();

	//Drive left initially blind to get sonar in range
	mechanumDrive(true);
	wait1Msec(1750);

	//Drive left using sonar
	alignLeftSide(true);

	//Lower strafe speed to get more accurate
	mechanumPower = mechanumPower - 92;

	//Drive left using sonar
	alignLeftSide(false);
	alignLeftSide(true);
	alignLeftSide(false);
	alignLeftSide(true);

	startTask(alignLeftAim);
	startTask(alignRightAim);

	wait1Msec(750);
	powerDivider = 4.8;

	//Lower firing power because it is a little closer to the net on the left side
	midPower -= 8;

	//Fire infinite balls
	ballCount = 0;
	while(ballCount < 60){
		setArm(ARM_FIRE);
		setDistance(MID);
		if(time1[T2] > 2500){
			override = true;
		}
	}
}

task usercontrol(){
	//Tell firing routine to go back to normal
	shortPower = 40;
	midPower = 49;
	tilePower = 82;
	cornerPower = 86;

	skills = false;

	//SAME AS MAIN DRIVER LOOP
	setGate(GATE_OPEN);
	setArm(ARM_FIRE);

	override = true;
	mechanumPower = FULL_POWER;

	startTask(armPosition);
	startTask(gatePosition);

	//Turn intake on
	motor[intake] = -127;

	while(true){
		//Firing Controls
	if(vexRT[Btn8D] == 1 && vexRT[Btn8L] == 1){
		override = true;
		setDistance(CORNER);
		setArm(ARM_FIRE);
	}else{
		if(vexRT[Btn7U] == 1){
			setDistance(CORNER);
			setArm(ARM_FIRE);
			}
			else{
			if(vexRT[Btn7L] == 1){
				setDistance(TILE);
				setArm(ARM_FIRE);
				}
				else{
				if(vexRT[Btn7D] == 1){
					setDistance(MID);
					setArm(ARM_FIRE);
					}
					else{
					if(vexRT[Btn7R] == 1){
						setDistance(SHORT);
						setArm(ARM_FIRE);
					}
				}
			}
		}
	}

		//Manual Gate Open
		if(vexRT[Btn8R] == true){
			setGate(GATE_OPEN);
		}

		//Drive Base controls
		if(vexRT[Btn6D] == true){
			rotate(false);
		}
		else{
			if(vexRT[Btn5D] == true){
				rotate(true);
			}
			else{
				if(vexRT[Btn6U] == true){
					mechanumDrive(false);
				}
				else{
					if(vexRT[Btn5U] == true){
						mechanumDrive(true);
					}
					else{
						tankDrive();
					}
				}
			}
		}
	}
}
