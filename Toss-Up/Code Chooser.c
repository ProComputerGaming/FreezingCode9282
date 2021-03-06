#pragma config(Sensor, in1,    potent,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  limSwitch,      sensorDigitalIn)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           liftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           scoopRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           scoopLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftBack,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           liftMotor2,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
int potentValue = SensorValue[potent];

void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}

void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}

void pre_auton()
{
  bStopTasksBetweenModes = true;
}

task autonomous()
{
	int count = 0;
	bool lift = true;
	clearLCDLine(0);
	clearLCDLine(1);
	while(nLCDButtons != centerButton){
		switch(count){
			case 0:
				//Display first choice
				displayLCDCenteredString(0, "GetRektPlebBlue");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count = 1;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count = 1;
				}
				break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "GetRektN00bRed");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 0;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		default:
			count = 0;
			break;
		}
	}
	switch(count){
		case 0:
		clearTimer(T1);
			//
			//						BLUE
			//						AUTONOMOUS
			//
		//Lower scoop in beginning to obtain ball later
		while (time1[T1] < 500)
		{
			motor[scoopLeft] = 127;
			motor[scoopRight] = -127;
		}
		//Reset motors and clear Timer1
		motor[scoopLeft] = 0;
		motor[scoopRight] = 0;
		clearTimer(T1);

		//Move forward and get scoop positioned under the ball and next to buckyballs on the bump
		while(time1[T1] < 1225)
		{
			motor[leftBack] = 127;
			motor[leftFront] = 127;
			motor[rightFront] = 127;
			motor[rightBack] = 127;
		}
		//Reset motors and clear Timer1
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		motor[rightFront] = 0;
		motor[rightBack] = 0;
		clearTimer(T1);

		// Move back 100 milliseconds to get in line better with the buckyballs to knock them off
		// and to help with allignment with the bar later on
  	while (time1[T1] < 100)
  	{
  		motor[leftBack] = -127;
			motor[leftFront] = -127;
			motor[rightFront] = -127;
			motor[rightBack] = -127;
		}
		//reset motors and clear Timer1
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		motor[rightFront] = 0;
		motor[rightBack] = 0;
		clearTimer(T1);

		//Raise the scoop a little bit to gain better hold of the large ball
		while (time1[T1] < 300)
		{
			motor[scoopLeft] = -63;
			motor[scoopRight] = 63;
		}
		//Reset motors anc clear Timer1
		motor[scoopLeft] = 0;
		motor[scoopRight] = 0;
		clearTimer(T1);

		//Turn using the left side going forward and knock off the three buckyballs on the bump
		while (time1[T1] < 450)
		{
			motor[leftBack] = 127;
			motor[leftFront] = 127;
		}
		//Reset motors and clear Timer1
		motor[leftFront] = 0;
		motor[leftBack] = 0;
		clearTimer(T1);

		//Raise the scoop completely and gain complete hold of the large ball
		while (time1[T1] < 350)
		{
			motor[scoopLeft] = -50;
			motor[scoopRight] = 50;
		}
		//Reset motors and clear Timer1
		motor[scoopLeft] = 0;
		motor[scoopRight] = 0;
		clearTimer(T1);

		//Drive backwards to have the lift hooks positioned perfectly over the bar.
		while (time1[T1] < 1350)
		{
			motor[leftBack] = -127;
			motor[leftFront] = -127;
			motor[rightFront] = -127;
			motor[rightBack] = -127;
		}
		//Reset motors and clearTimer1
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		motor[rightFront] = 0;
		motor[rightBack] = 0;
		clearTimer(T1);

		//Lower the lift to high hang with a ball
		while(lift)
		{
			motor[liftMotor] = 127;
			motor[liftMotor2] = -127;
			if (SensorValue[dgtl1] == 0){
				lift = false;
			}
		}

		//Reset motors anc clear Timer1
		motor[liftMotor] = 0;
		motor[liftMotor2] = 0;
		clearTimer(T1);
		break;
	case 1:
		//
		//						RED
		//						AUTONOMOUS
		//
		clearTimer(T1);

		//Lower scoop in beginning to obtain ball later
		while (time1[T1] < 500)
		{
			motor[scoopLeft] = 127;
			motor[scoopRight] = -127;
		}
		//Reset motors and clear Timer1
		motor[scoopLeft] = 0;
		motor[scoopRight] = 0;
		clearTimer(T1);

		//Move forward and get scoop positioned under the ball and next to buckyballs on the bump
		while(time1[T1] < 1325)
		{
			motor[leftBack] = 127;
			motor[leftFront] = 127;
			motor[rightFront] = 127;
			motor[rightBack] = 127;
		}
		//Reset motors and clear Timer1
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		motor[rightFront] = 0;
		motor[rightBack] = 0;
		clearTimer(T1);

		// Move back 100 milliseconds to get in line better with the buckyballs to knock them off
		// and to help with allignment with the bar later on
  	while (time1[T1] < 200)
  	{
  		motor[leftBack] = -127;
			motor[leftFront] = -127;
			motor[rightFront] = -127;
			motor[rightBack] = -127;
		}
		//reset motors and clear Timer1
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		motor[rightFront] = 0;
		motor[rightBack] = 0;
		clearTimer(T1);

		//Raise the scoop a little bit to gain better hold of the large ball
		while (time1[T1] < 200)
		{
			motor[scoopLeft] = -63;
			motor[scoopRight] = 63;
		}
		//Reset motors anc clear Timer1
		motor[scoopLeft] = 0;
		motor[scoopRight] = 0;
		clearTimer(T1);

		//Turn using the right side going forward and knock off the three buckyballs on the bump
		while (time1[T1] < 450)
		{
			motor[rightBack] = 127;
			motor[rightFront] = 127;
		}
		//Reset motors and clear Timer1
		motor[rightFront] = 0;
		motor[rightBack] = 0;
		clearTimer(T1);

		//Raise the scoop completely and gain complete hold of the large ball
		while (time1[T1] < 350)
		{
			motor[scoopLeft] = -50;
			motor[scoopRight] = 50;
		}
		//Reset motors and clear Timer1
		motor[scoopLeft] = 0;
		motor[scoopRight] = 0;
		clearTimer(T1);

		//Drive backwards to have the lift hooks positioned perfectly over the bar.
		while (time1[T1] < 1450)
		{
			motor[leftBack] = -127;
			motor[leftFront] = -127;
			motor[rightFront] = -127;
			motor[rightBack] = -127;
		}
		//Reset motors and clearTimer1
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		motor[rightFront] = 0;
		motor[rightBack] = 0;
		clearTimer(T1);

		//Lower the lift to high hang with a ball
		while(lift)
		{
			motor[liftMotor] = 127;
			motor[liftMotor2] = -127;
			if (SensorValue[dgtl1] == 0){
				lift = false;
			}
		}
		//Stop the motors once it is actually pressed
		motor[liftMotor] = 0;
		motor[liftMotor2] = 0;
		break;
	}
}
task potentiometer(){
	while(true)
	{
		potentValue = abs(SensorValue[potent]);
		string ie = potentValue;
		displayLCDString(1,1,ie);
	}
}
task usercontrol()
{
	while (true)
	{


		//Joystick Movement
		motor[leftBack] = vexRT[Ch3];
		motor[leftFront] = vexRT[Ch3];
		motor[rightBack] = vexRT[Ch2];
		motor[rightFront] = vexRT[Ch2];


		//Joystick Digital Buttons using embedded if statements

		//Raise Scoop
		if (vexRT[Btn5U] == 1)
		{
			motor[scoopRight] = 80;
			motor[scoopLeft] = -80;
		}
		else
		{
			// Lower Scoop
			if (vexRT[Btn5D] == 1)
			{
				motor[scoopRight] = -80;
				motor[scoopLeft] = 80;
			}
			else
			{
				if (vexRT[Btn8D] == 1)
				{
					motor[scoopLeft] = 45;
					motor[scoopRight] = -45;
				}
				else
				{
					if (vexRT[Btn8U] == 1)
					{
						motor[scoopRight] = 55;
						motor[scoopLeft] = -55;
					}
					else
					{
						//turn motors off if no buttons on channel 5 are pressed
						motor[scoopRight] = 0;
						motor[scoopLeft] = 0;
					}
				}
			}
		}

		//Lift Control
		//Raise Lift
		if (vexRT[Btn6U] == 1)
		{
			motor[liftMotor] = -127;
			motor[liftMotor2] = 127;
		}
		else
		{
			//Lower Lift
			if (vexRT[Btn6D] == 1)
			{
				motor[liftMotor] = 127;
				motor[liftMotor2] = -127;
			}
			else
			{
				// Turn motors off if no buttons are pressed on Channel 6
				motor[liftMotor] = 0;
				motor[liftMotor2] = 0;
			}
		}
	}
}
