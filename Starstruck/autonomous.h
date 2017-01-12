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
        setSyncMove(FORWARD, 450);
        waitForTasks();
        setSyncMove(RIGHT, QUARTER - 50);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(FORWARD, 425);
        waitForTasks();
        closeClaw(750);
        setSyncLift(625);
        waitForTasks();
        setSyncMove(LEFT, QUARTER - 75);
        waitForTasks();
        setSyncMove(FORWARD, 400);
        setSyncLift(625);
        waitForTasks();
        openClaw();
        waitForTasks();
        setSyncMove(BACKWARD, 300);
        waitForTasks();
        setSyncMove(RIGHT, HALF - 100);
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
        setSyncMove(LEFT, HALF);
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

void autonFourteen(){
	setSyncMove(FORWARD, 100);
	waitForTasks();
	openClaw();
	waitForTasks();
	wait1Msec(200);
	setSyncLift(650);
	waitForTasks();
	setSyncMove(BACKWARD, 100);
	waitForTasks();
	wait1Msec(1500);
	closeClaw(750);
	wait1Msec(1500);
	setSyncMove(FORWARD, 950);
	waitForTasks();
	openClaw(); //Drop 3 star and cube combo
	waitForTasks();

	setSyncMove(BACKWARD, 950);
	waitForTasks();
	wait1Msec(1000);
	closeClaw(750);
	wait1Msec(1000);
	setSyncMove(FORWARD, 950);
	waitForTasks();
	openClaw();
	waitForTasks(); //Drop the one cube preload

	setSyncMove(BACKWARD, 475);
	waitForTasks();
	setSyncMove(RIGHT, QUARTER);
	waitForTasks();
	setSyncLift(25);
	waitForTasks();
	setSyncMove(FORWARD, 350);
	waitForTasks();
	closeClaw(400);
	setSyncLift(625);
	waitForTasks();
	setSyncMove(FORWARD, 100);
	waitForTasks();
	wait1Msec(400);
	setSyncMove(LEFT, QUARTER);
	waitForTasks();
	setSyncMove(FORWARD, 475);
	waitForTasks();
	openClaw(); //Drop field cube

	waitForTasks();
	setSyncMove(BACKWARD, 275);
	waitForTasks();
	wait1Msec(400);
	setSyncMove(RIGHT, HALF + 50);
	waitForTasks();
	setSyncMove(BACKWARD, 100);
	waitForTasks();
	setSyncLift(25);
	waitForTasks();
	DRIVEBASE_POWER = 127;
	setSyncMove(FORWARD, 350);
	waitForTasks();
	closeClaw(750);
	setSyncMove(BACKWARD, 275);
	waitForTasks();
	setSyncLift(625);
	waitForTasks();
	DRIVEBASE_POWER = 63;
	setSyncMove(LEFT, HALF + 50);
	waitForTasks();
	wait1Msec(400);
	setSyncMove(FORWARD, 350);
	waitForTasks();
	openClaw(); //Drop field stars

	waitForTasks();
	setSyncMove(BACKWARD, 400);
	waitForTasks();
	setSyncLift(50);
	waitForTasks();
	setSyncMove(FORWARD, 400);
	waitForTasks();
	closeClaw(750);
	setSyncMove(BACKWARD, 400);
	waitForTasks();
	setSyncLift(625);
	waitForTasks();
	setSyncMove(FORWARD, 500);
	waitForTasks();
	openClaw();
	waitForTasks();
}
