void autonZero(){
//Left Square
        setSyncMove(FORWARD, 400);
        waitForTasks();
        setSyncMove(RIGHT, QUARTER);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(FORWARD, 475);
        waitForTasks();
        wait1Msec(200);
        closeClaw(750);
        setSyncLift(625);
        waitForTasks();
        setSyncMove(LEFT, QUARTER);
        waitForTasks();
        setSyncMove(FORWARD, 400);
        setSyncLift(625);
        waitForTasks();
        openClaw();
}

void autonOne(){
	//Left Square with Stars
        setSyncMove(FORWARD, 425);
        waitForTasks();
        setSyncMove(RIGHT, QUARTER);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(FORWARD, 425);
        waitForTasks();
        closeClaw(750);
        setSyncLift(625);
        waitForTasks();
        setSyncMove(LEFT, QUARTER - 15);
        waitForTasks();
        setSyncMove(FORWARD, 400);
        setSyncLift(625);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(BACKWARD, 300);
        waitForTasks();
        setSyncMove(RIGHT, HALF + 50);
        waitForTasks();
        setSyncMove(BACKWARD, 75);
        setSyncLift(50);
        waitForTasks();
        setSyncMove(FORWARD, 350);
        waitForTasks();
        closeClaw(750);
        setSyncMove(BACKWARD, 100);
        waitForTasks();
        setSyncLift(625);
        waitForTasks();
        setSyncMove(LEFT, HALF + 100);
        waitForTasks();
        setSyncMove(FORWARD, 350);
        waitForTasks();
        openClaw();
        waitForTasks();

}

void autonTwo(){
	//Right square
        setSyncMove(FORWARD, 400);
        waitForTasks();
        setSyncMove(LEFT, QUARTER);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(FORWARD, 475);
        waitForTasks();
        wait1Msec(200);
        closeClaw(750);
        setSyncLift(625);
        waitForTasks();
        setSyncMove(RIGHT, QUARTER);
        waitForTasks();
        setSyncMove(FORWARD, 400);
        setSyncLift(625);
        waitForTasks();
        openClaw();
}

void autonThree(){
	//Right Square with Stars
        setSyncMove(FORWARD, 425);
        waitForTasks();
        setSyncMove(LEFT, QUARTER);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(FORWARD, 425);
        waitForTasks();
        closeClaw(750);
        setSyncLift(625);
        waitForTasks();
        setSyncMove(RIGHT, QUARTER - 15);
        waitForTasks();
        setSyncMove(FORWARD, 400);
        setSyncLift(625);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(BACKWARD, 300);
        waitForTasks();
        setSyncMove(LEFT, HALF + 50);
        waitForTasks();
        setSyncMove(BACKWARD, 75);
        setSyncLift(50);
        waitForTasks();
        setSyncMove(FORWARD, 350);
        waitForTasks();
        closeClaw(750);
        setSyncMove(BACKWARD, 100);
        waitForTasks();
        setSyncLift(625);
        waitForTasks();
        setSyncMove(RIGHT, HALF + 100);
        waitForTasks();
        setSyncMove(FORWARD, 350);
        waitForTasks();
        openClaw();
        waitForTasks();
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
