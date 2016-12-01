#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    leftFrontLight, sensorNone)
#pragma config(Sensor, in2,    leftMidLight,   sensorLineFollower)
#pragma config(Sensor, in3,    leftBackLight,  sensorLineFollower)
#pragma config(Sensor, in4,    rightFrontLight, sensorLineFollower)
#pragma config(Sensor, in5,    rightMidLight,  sensorLineFollower)
#pragma config(Sensor, in6,    rightBackLight, sensorLineFollower)
#pragma config(Sensor, in7,    potOne,         sensorPotentiometer)
#pragma config(Sensor, in8,    potTwo,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  liftQuad,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftFingerSwitch, sensorDigitalIn)
#pragma config(Sensor, dgtl4,  rightFingerSwitch, sensorDigitalIn)
#pragma config(Sensor, dgtl5,  rightQuad,      sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  leftQuad,       sensorQuadEncoder)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           backRight,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           fingerY,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftLiftY,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           rightLiftY,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#define LIGHT_SENSE_EN 0

#include "Vex_Competition_Includes.c"
#include "FingerBot.h"
#include "autonomous.h"

void pre_auton()
{
	bStopTasksBetweenModes = true;
	bLCDBacklight = true;
	if( !(nVexRCReceiveState & 0x08)){
		while(!nLCDButtons){
			wait1Msec(5);
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Select Program: ");
			displayLCDNumber(1,0,programSelected(SEGMENTS));
		}
		autonSelection = programSelected(8);
		}else{
		autonSelection = programSelected(8);
	}
}

task autonomous()
{
	inAutonomous = true;
	startTask(fingerMonitor);
	startTask(wheelMonitor);
	startTask(liftMonitor);

	#if(LIGHT_SENSE_EN)
		startTask(lightMonitor);
	#endif

	zeroAllSensors();
	switch(autonSelection){
	case 0:
		autonZero();
		break;
	case 1:
		autonOne();
		break;
	case 2:
		autonTwo();
		break;
	case 3:
		autonThree();
		break;
	case 4:
		autonFour();
		break;
	case 5:
		autonFive();
		break;
	case 6:
		autonSix();
		break;
	case 7:
		autonSeven();
		break;
	case 8:
		autonEight();
		break;
	case 9:
		autonNine();
		break;
	case 10:
		autonTen();
		break;
	case 11:
		autonEleven();
		break;
	case 12:
		autonTwelve();
		break;
	case 13:
		autonThirteen();
		break;
	case 14:
		autonFourteen();
		break;
	default:
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0,0,"Invalid");
		displayLCDString(1,0,"Selection");
		break;
	}
}

task usercontrol()
{
	inAutonomous = false;
	stopTask(wheelMonitor);
	stopTask(liftMonitor);
	startTask(fingerMonitor);

	#if(LIGHT_SENSE_EN)
		startTask(lightMonitor);
	#endif

	while (true)
	{
		displayLCDString(0,0,"Running Program: ");
		displayLCDNumber(1,0,programSelected(SEGMENTS));
		if(vexRT[Btn6U] == 1){
			dLift(false);
		}
		if(vexRT[Btn6D] == 1){
			dLift(true);
		}
		if(vexRT[Btn6U] == OFF && vexRT[Btn6D] == OFF){
			stopLift();
		}

		if(vexRT[Btn5D] == 1){
			closeClaw(OFF);
			}else if(vexRT[Btn5U] == 1){
			openClaw();
		}

		if(vexRT[Btn7R] == 1){
			strafeRight(OFF);
		}
		if(vexRT[Btn7L] == 1){
			strafeLeft(OFF);
		}
		if(vexRT[Btn7R] == OFF && vexRT[Btn7L] == OFF){
			analogDrive();
		}
	}
}
