#pragma config(Sensor, dgtl1,  limSwitch,      sensorDigitalIn)
#pragma config(Sensor, dgtl2,  solenoid1,      sensorDigitalOut)
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
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"

void pre_auton()
{
  bStopTasksBetweenModes = true;
}

task autonomous()
{
	bool lift = true;
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
	while (time1[T1] < 350)
	{
		motor[leftBack] = 127;
		motor[leftFront] = 127;
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

	while(lift){
		motor[liftMotor] = 127;
		motor[liftMotor2] = -127;
		if (SensorValue[dgtl1] == 0){
			lift = false;
		}
	}
	motor[liftMotor] = 0;
	motor[liftMotor2] = 0;
}

task usercontrol(){
	while (true)
	{
		//Joystick Movement
		motor[leftBack] = vexRT[Ch3];
		motor[leftFront] = vexRT[Ch3];
		motor[rightBack] = vexRT[Ch2];
		motor[rightFront] = vexRT[Ch2];


		//Joystick Digital Buttons using embedded if statements

		//Solonoid control
		if (vexRT[Btn7D]== 1)
		{
			SensorValue[dgtl2] = 1;
		}
		if (vexRT[Btn7L]== 1)
		{
			SensorValue[dgtl2] = 0;
		}

		//Scoop Control
		//Raise Scoop
		if (vexRT[Btn5U] == 1)
		{
			motor[scoopRight] = 40;
			motor[scoopLeft] = -40;
		}
		else
		{
			// Lower Scoop
			if (vexRT[Btn5D] == 1)
			{
				motor[scoopRight] = -40;
				motor[scoopLeft] = 40;
			}
			else
			{
				//turn motors off if no buttons on channel 5 are pressed
				motor[scoopRight] = 0;
				motor[scoopLeft] = 0;
			}
		}
		if (vexRT[Btn7U] == 1)
		{
			clearTimer(T2);
			while (time1[T2] < 350){
			motor[scoopLeft] = -127;
			motor[scoopRight] = 127;
		}
		motor[scoopLeft] = 0;
		motor[scoopRight] = 0;
		}
			if (vexRT[Btn7D] == 1)
		{
			clearTimer(T2);
			while (time1[T2] < 400){
			motor[scoopLeft] = 127;
			motor[scoopRight] = -127;
		}
		motor[scoopLeft] = 0;
		motor[scoopRight] = 0;
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
