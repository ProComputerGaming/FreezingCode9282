void autonZero(){
				//NEW SYNCHRONOUS CODE
        setSyncMove(FORWARD, 400);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(LEFT, QUARTER);
        waitForTasks();
        setSyncMove(FORWARD, 475);
        waitForTasks();
        wait1Msec(200);
        closeClaw(750);
        setSyncLift(650);
        waitForTasks();
        DRIVEBASE_POWER = 63;
        setSyncMove(FORWARD, 350);
        waitForTasks();
        wait1Msec(300);
        setSyncMove(RIGHT, QUARTER);
        waitForTasks();
        wait1Msec(500);
        DRIVEBASE_POWER = 127;
        setSyncMove(FORWARD, 900);
        setSyncLift(675);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(BACKWARD, 700);
        waitForTasks();
        wait1Msec(750);
        setSyncMove(RIGHT, HALF);
        setSyncLift(25);
        waitForTasks();
        setSyncMove(FORWARD, 400);
        waitForTasks();
        closeClaw(800);
        waitForTasks();
        setSyncMove(BACKWARD, 200);
        waitForTasks();
        setSyncLift(600);
        setSyncMove(LEFT, HALF);
        waitForTasks();
        setSyncLift(650);
        setSyncMove(FORWARD, 750);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncLift(725);
        waitForTasks();
        setSyncMove(BACKWARD, 400);
        waitForTasks();
}

void autonOne(){
				//MOTOR_DEFAULT_SLEW_RATE = MOTOR_FAST_SLEW_RATE;
        //NEW SYNCHRONOUS CODE
        setSyncMove(FORWARD, 400);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(RIGHT, QUARTER);
        waitForTasks();
        setSyncMove(FORWARD, 475);
        waitForTasks();
        wait1Msec(200);
        closeClaw(750);
        setSyncLift(650);
        waitForTasks();
        setSyncMove(FORWARD, 350);
        waitForTasks();
        wait1Msec(300);
        setSyncMove(LEFT, QUARTER);
        waitForTasks();
        wait1Msec(500);
        setSyncMove(FORWARD, 900);
        setSyncLift(675);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(BACKWARD, 700);
        waitForTasks();
        wait1Msec(750);
        DRIVEBASE_POWER = 127;
        setSyncMove(LEFT, HALF);
        setSyncLift(25);
        waitForTasks();
        DRIVEBASE_POWER = 127;
        setSyncMove(FORWARD, 400);
        waitForTasks();
        closeClaw(800);
        waitForTasks();
        setSyncMove(BACKWARD, 200);
        waitForTasks();
        setSyncLift(600);
        setSyncMove(RIGHT, HALF);
        waitForTasks();
        setSyncLift(650);
        setSyncMove(FORWARD, 750);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncLift(725);
        waitForTasks();
        setSyncMove(BACKWARD, 400);
        waitForTasks();
}

void autonTwo(){
		openClaw();
		waitForTasks();
		setSyncMove(FORWARD, 300);
		waitForTasks();
}

void autonThree(){

}

void autonFour(){

}

void autonFive(){

}

void autonSix(){

}

void autonSeven(){

}

void autonEight(){

}

void autonNine(){

}

void autonTen(){

}

void autonEleven(){

}

void autonTwelve(){

}

void autonThirteen(){

}

//Robot Skills
void autonFourteen(){
				////First Cube Drop
				//driveForward(200);
    //    openClaw();
    //    wait1Msec(300);
    //    driveForward(550);
    //    closeClaw(1000);
    //    raiseLift(650);
    //    turnLeft(250);
    //    driveForward(900);
    //    openClaw();

    //    //Extra 2 StarS
    //    wait1Msec(200);
    //    driveBackward(500);
    //    turnLeft(1200);
    //    lowerLift(25);
    //    driveForward(300);
    //    closeClaw(400);
    //    driveBackward(200);
    //    raiseLift(650);
    //    turnRight(1250);
    //    driveForward(550);
    //    openClaw();

    //    //Skills Cube 1
    //    //driveBackward(100);
    //    turnLeft(875);
    //    lowerLift(25);
    //    driveForward(650);
    //    wait1Msec(500);
    //    closeClaw(750);
    //    driveBackward(100);
    //    raiseLift(675);
    //    turnRight(800);
    //    driveForward(650);
    //		openClaw();

    //		//Skills Cube 2
    //		//driveBackward(100);
    //		turnLeft(1000);
    //    lowerLift(25);
    //    driveForward(700);
    //    wait1Msec(500);
    //    closeClaw(750);
    //    driveBackward(100);
    //    raiseLift(675);
    //    turnRight(1000);
    //    driveForward(700);
    //		openClaw();
    //		driveBackward(300);

    		//NEW SYNCHRONOUS CODE
}
