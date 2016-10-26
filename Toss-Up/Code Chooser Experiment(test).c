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
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

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

void Reset()
{
	motor[scoopLeft] = 0;
	motor[scoopRight] = 0;
	motor[liftMotor] = 0;
	motor[liftMotor2] = 0;
	motor[leftBack] = 0;
	motor[leftFront] = 0;
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	clearTimer(T1);
}

void driveMotorsFullSpeedForward()
{
	motor[leftBack] = 127;
	motor[leftFront] = 127;
	motor[rightFront] = 127;
	motor[rightBack] = 127;
}

void driveMotorsFullSpeedReverse()
{
	motor[leftBack] = -127;
	motor[leftFront] = -127;
	motor[rightFront] = -127;
	motor[rightBack] = -127;
}

void driveMotorsHalfSpeedReverse()
{
	motor[leftBack] = -64;
	motor[leftFront] = -64;
	motor[rightFront] = -64;
	motor[rightBack] = -64;
}

void turnLeft()
{
	motor[leftBack] = 127;
	motor[leftFront] = 127;
}

void turnLeftReverse()
{
	motor[leftBack] = -127;
	motor[leftFront] = -127;
}

void turnRight()
{
	motor[rightBack] = 127;
	motor[rightFront] = 127;
}

void liftLower()
{
	motor[liftMotor] = 127;
	motor[liftMotor2] = -127;
}

void liftRaise()
{
	motor[liftMotor] = -127;
	motor[liftMotor2] = 127;
}

void scoopRaiseHalfSpeed()
{
	motor[scoopLeft] = -63;
	motor[scoopRight] = 63;
}

void scoopRaiseFullSpeed()
{
	motor[scoopLeft] = -127;
	motor[scoopRight] = 127;
}

void scoopLowerFullSpeed()
{
	motor[scoopLeft] = 127;
	motor[scoopRight] = -127;
}

void BlueAutonomous()
{
	bool lift = true;
	clearTimer(T1);
	//
	//						BLUE
	//						AUTONOMOUS
	//
	//Lower scoop in beginning to obtain ball later
	while (time1[T1] < 500)
	{
		scoopLowerFullSpeed();
	}
	//Reset motors and clear Timer1
	Reset();

	//Move forward and get scoop positioned under the ball and next to buckyballs on the bump
	while(time1[T1] < 1225)
	{
		driveMotorsFullSpeedForward();
	}
	//Reset motors and clear Timer1
	Reset();

	// Move back 100 milliseconds to get in line better with the buckyballs to knock them off
	// and to help with allignment with the bar later on
	while (time1[T1] < 100)
	{
		driveMotorsFullSpeedReverse();
	}
	//reset motors and clear Timer1
	Reset();

	//Raise the scoop a little bit to gain better hold of the large ball
	while (time1[T1] < 125)
	{
		scoopRaiseFullSpeed();
	}
	//Reset motors and clear Timer1
	Reset();

	//Turn using the left side going forward and knock off the three buckyballs on the bump
	while (time1[T1] < 550)
	{
		turnLeft();
	}
	//Reset motors and clear Timer1
	Reset();

	//Raise the scoop completely and gain complete hold of the large ball
	while (time1[T1] < 150)
	{
		scoopRaiseFullSpeed();
	}
	//Reset motors and clear Timer1
	Reset();

	//Drive backwards to have the lift hooks positioned perfectly over the bar.
	while (time1[T1] < 1450)
	{
		driveMotorsFullSpeedReverse();
	}
	//Reset motors and clearTimer1
	Reset();

	//Lower the lift to high hang with a ball
	while(lift)
	{
		liftLower();
		if (SensorValue[dgtl1] == 0){
			lift = false;
		}
	}
	//Reset motors anc clear Timer1
	Reset();
}

void RedAutonomous()
{
	bool lift = true;
	//
	//						RED
	//						AUTONOMOUS
	//
	clearTimer(T1);

	//Lower scoop in beginning to obtain ball later
	while (time1[T1] < 500)
	{
		scoopLowerFullSpeed();
	}
	//Reset motors and clear Timer1
	Reset();

	//Move forward and get scoop positioned under the ball and next to buckyballs on the bump
	while(time1[T1] < 1325)
	{
		driveMotorsFullSpeedForward();
	}
	//Reset motors and clear Timer1
	Reset();

	//Raise the scoop a little bit to gain better hold of the large ball
	while (time1[T1] < 100)
	{
		scoopRaiseHalfSpeed();
	}
	//Reset motors anc clear Timer1
	Reset();

	// Move back 100 milliseconds to get in line better with the buckyballs to knock them off
	// and to help with allignment with the bar later on
	while (time1[T1] < 100)
	{
		driveMotorsFullSpeedReverse();
	}
	//reset motors and clear Timer1
	Reset();

	while (time1[T1] < 100)
	{
		driveMotorsHalfSpeedReverse();
	}

	//Turn using the right side going forward and knock off the three buckyballs on the bump
	while (time1[T1] < 450)
	{
		turnRight();
	}
	//Reset motors and clear Timer1
	Reset();

	//Raise the scoop completely and gain complete hold of the large ball
	while (time1[T1] < 350)
	{
		scoopRaiseHalfSpeed();
	}
	//Reset motors and clear Timer1
	Reset();

	//Drive backwards to have the lift hooks positioned perfectly over the bar.
	while (time1[T1] < 1550)
	{
		driveMotorsFullSpeedReverse();
	}
	//Reset motors and clearTimer1
	Reset();

	//Lower the lift to high hang with a ball
	while(lift)
	{
		liftLower();
		if (SensorValue[dgtl1] == 0){
			lift = false;
		}
	}
	//Stop the motors once it is actually pressed
	Reset();
}

void RedWithoutBuckyAutonomous()
{
	bool lift = true;
	//
	//						RED
	//						AUTONOMOUS
	//
	clearTimer(T1);

	//Lower scoop in beginning to obtain ball later
	while (time1[T1] < 500)
	{
		scoopLowerFullSpeed();
	}
	//Reset motors and clear Timer1
	Reset();

	//Move forward and get scoop positioned under the ball and next to buckyballs on the bump
	while(time1[T1] < 1325)
	{
		driveMotorsFullSpeedForward();
	}
	//Reset motors and clear Timer1
	Reset();

	//Raise the scoop a little bit to gain better hold of the large ball
	while (time1[T1] < 450)
	{
		scoopRaiseHalfSpeed();
	}
	//Reset motors anc clear Timer1
	Reset();

	// Move back 100 milliseconds to get in line better with the buckyballs to knock them off
	// and to help with allignment with the bar later on
	while (time1[T1] < 100)
	{
		driveMotorsFullSpeedReverse();
	}
	//reset motors and clear Timer1
	Reset();



	//Turn using the right side going forward and knock off the three buckyballs on the bump
	while (time1[T1] < 350)
	{
		turnRight();
	}
	//Reset motors and clear Timer1
	Reset();

	//Raise the scoop completely and gain complete hold of the large ball
	while (time1[T1] < 350)
	{
		scoopRaiseHalfSpeed();
	}
	//Reset motors and clear Timer1
	Reset();

	//Drive backwards to have the lift hooks positioned perfectly over the bar.
	while (time1[T1] < 1700)
	{
		driveMotorsFullSpeedReverse();
	}
	//Reset motors and clearTimer1
	Reset();

	//Lower the lift to high hang with a ball
	while(lift)
	{
		liftLower();
		if (SensorValue[dgtl1] == 0){
			lift = false;
		}
	}
	//Stop the motors once it is actually pressed
	Reset();
}

void BlueWithoutBuckyAutonomous()
{
	bool lift = true;
	clearTimer(T1);
	//
	//						BLUE
	//						AUTONOMOUS
	//
	//Lower scoop in beginning to obtain ball later
	while (time1[T1] < 500)
	{
		scoopLowerFullSpeed();
	}
	//Reset motors and clear Timer1
	Reset();

	//Move forward and get scoop positioned under the ball and next to buckyballs on the bump
	while(time1[T1] < 1225)
	{
		driveMotorsFullSpeedForward();
	}
	//Reset motors and clear Timer1
	Reset();

	// Move back 100 milliseconds to get in line better with the buckyballs to knock them off
	// and to help with allignment with the bar later on
	while (time1[T1] < 100)
	{
		driveMotorsFullSpeedReverse();
	}
	//reset motors and clear Timer1
	Reset();

	//Raise the scoop a little bit to gain better hold of the large ball
	while (time1[T1] < 400)
	{
		scoopRaiseFullSpeed();
	}
	//Reset motors and clear Timer1
	Reset();

	//Turn using the left side going forward and knock off the three buckyballs on the bump
	while (time1[T1] < 550)
	{
		turnLeft();
	}
	//Reset motors and clear Timer1
	Reset();

	//Drive backwards to have the lift hooks positioned perfectly over the bar.
	while (time1[T1] < 1450)
	{
		driveMotorsFullSpeedReverse();
	}
	//Reset motors and clearTimer1
	Reset();

	//Lower the lift to high hang with a ball
	while(lift)
	{
		liftLower();
		if (SensorValue[dgtl1] == 0){
			lift = false;
		}
	}
	//Reset motors anc clear Timer1
	Reset();
}

void SkillsChallenge(){
		bool lift = true;
	//
	//						RED Skills
	//						AUTONOMOUS
	//
	clearTimer(T1);

	//**********************FIRST INFLATABLE**************************************************************************************

	//Drive forward and knock off first buckyball on barrier
	while (time1[T1] < 1500)
	{
		driveMotorsFullSpeedReverse();
	}
	Reset();

	//Drive back to the colored square in the middle zone
	while (time1[T1] <1350)
	{
		driveMotorsFullSpeedForward();
	}
	Reset();

	while (nLCDButtons != centerButton)
	{
	}
	Reset();

	//////////****************SECOND INFLATABLE***********************************************************************************

	//Drive forward to align with the second Big Ball
	while (time1[T1] < 1050)
	{
		driveMotorsFullSpeedReverse();
	}
	Reset();

	//Turn on at a 90 degree angle to face the second big ball
	while (time1[T1] < 1500)
	{
		turnLeftReverse();
	}
	Reset();

	//Drive forward to actually knock off the second big ball
	while (time1[T1] < 1000)
	{
		driveMotorsFullSpeedReverse();
	}
	Reset();

	//Drive backwards to realign with the colored square
	while (time1[T1] < 500)
	{
		driveMotorsFullSpeedForward();
	}
	Reset();

	//Turn using the left wheels 90 degrees forward
	while (time1[T1] < 1500)
	{
		turnLeft();
	}
	Reset();

	//Drive backwards to get back to the colored square
	while (time1[T1] < 1500)
	{
		driveMotorsFullSpeedForward();
	}
	Reset();

	while( nLCDButtons != centerButton)
	{
		//Wait until the cetner button is pressed
	}
	Reset();

	///////*************THIRD INFLATABLE***********************************************************************************

	//Drive forward to align with the second Big Ball
	while (time1[T1] < 2750)
	{
		driveMotorsFullSpeedReverse();
	}
	Reset();

	//Turn on at a 90 degree angle to face the second big ball
	while (time1[T1] < 1500)
	{
		turnLeftReverse();
	}
	Reset();

	//Drive forward to actually knock off the second big ball
	while (time1[T1] < 1000)
	{
		driveMotorsFullSpeedReverse();
	}
	Reset();

	//Drive backwards to realign with the colored square
	while (time1[T1] < 500)
	{
		driveMotorsFullSpeedForward();
	}
	Reset();

	//Turn using the left wheels 90 degrees forward
	while (time1[T1] < 1000)
	{
		turnLeft();
	}
	Reset();

	//Drive backwards to get back to the colored square
	while (time1[T1] < 2750)
	{
		driveMotorsFullSpeedForward();
	}
	Reset();

		while( nLCDButtons != centerButton)
	{
		//Wait until the cetner button is pressed
	}
	Reset();


	//****************************BUMP ACTION************************************************************************************


	//Drive backwards over the bump to get to the hanging zone colored square, where I reposition the bot for normal autonomous segment
	while(time1[T1] < 2000)
	{
		driveMotorsFullSpeedReverse();
	}
	Reset();

	while(nLCDButtons != centerButton)
	{
		//Wait until center button is pressed and then off goes normal autonomous
	}
	Reset();
	//Raise the lift all the way
	//while(time1[T1] < 11000)
	//{
	//	liftRaise();
	//}
	//Reset();

	//*******************************NORMAL AUTONOMOUS*********************************************

	//Lower scoop in beginning to obtain ball later
	while (time1[T1] < 500)
	{
		scoopLowerFullSpeed();
	}
	Reset();

	//Move forward and get scoop positioned under the ball and next to buckyballs on the bump
	while(time1[T1] < 1325)
	{
		driveMotorsFullSpeedForward();
	}
	Reset();

	//Raise the scoop a little bit to gain better hold of the large ball
	while (time1[T1] < 100)
	{
		scoopRaiseHalfSpeed();
	}
	Reset();

	// Move back 100 milliseconds to get in line better with the buckyballs to knock them off
	// and to help with allignment with the bar later on
	while (time1[T1] < 100)
	{
		driveMotorsHalfSpeedReverse();
	}
	Reset();



	//Turn using the right side going forward and knock off the three buckyballs on the bump
	while (time1[T1] < 500)
	{
		turnRight();
	}
	Reset();

	//Raise the scoop completely and gain complete hold of the large ball
	while (time1[T1] < 350)
	{
		scoopRaiseHalfSpeed();
	}
	Reset();

	//Drive backwards to have the lift hooks positioned perfectly over the bar.
	while (time1[T1] < 1550)
	{
		driveMotorsFullSpeedReverse();
	}
	Reset();

	//Lower the lift to high hang with a ball
	while(lift)
	{
		liftLower();
		if (SensorValue[dgtl1] == 0){
			lift = false;
		}
	}
	Reset();
}

task autonomous()
{
	int count = 0;

	clearLCDLine(0);
	clearLCDLine(1);
	while(nLCDButtons != centerButton){
		switch(count){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "Blue");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 4;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 1;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "Red");
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
				count = 2;
			}
			break;
				case 2:
			//Display second choice
			displayLCDCenteredString(0, "Red w/o Bucky");
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
				count = 3;
			}
			break;
			case 3:
			//Display second choice
			displayLCDCenteredString(0, "Blue w/o Bucky");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 2;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 4;
			}
			break;
				case 4:
			//Display second choice
			displayLCDCenteredString(0, "Red Skills");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 3;
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
		BlueAutonomous();
		break;
	case 1:
		BlueAutonomous();
		break;
	case 2:
		BlueAutonomous();
		break;
	case 3:
		BlueAutonomous();
		break;
	case 4:
		BlueAutonomous();
		break;
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
