void BlueAutonomous()
{
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
}
