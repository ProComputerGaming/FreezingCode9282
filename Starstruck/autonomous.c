void autonZero(){
        driveForward(200);
        openClaw();
        wait1Msec(300);
        driveForward(550);
        closeClaw(1000);
        raiseLift(650);
        turnRight(250);
        driveForward(900);
        openClaw();
        wait1Msec(200);
        driveBackward(500);
        turnLeft(1000);
        lowerLift(25);
        driveForward(300);
        closeClaw(400);
        driveBackward(200);
        raiseLift(525);
        turnRight(1250);
        driveForward(550);
        openClaw();
}

void autonOne(){
        driveForward(200);
        openClaw();
        wait1Msec(300);
        driveForward(550);
        closeClaw(1000);
        raiseLift(650);
        turnLeft(250);
        driveForward(900);
        openClaw();
        wait1Msec(200);
        driveBackward(500);
        turnRight(1000);
        lowerLift(25);
        driveForward(300);
        closeClaw(400);
        driveBackward(200);
        raiseLift(525);
        turnLeft(1250);
        driveForward(550);
        openClaw();
}

void autonTwo(){

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
				//First Cube Drop
				driveForward(200);
        openClaw();
        wait1Msec(300);
        driveForward(550);
        closeClaw(1000);
        raiseLift(650);
        turnLeft(250);
        driveForward(900);
        openClaw();

        //Extra 2 StarS
        wait1Msec(200);
        driveBackward(500);
        turnLeft(1200);
        lowerLift(25);
        driveForward(300);
        closeClaw(400);
        driveBackward(200);
        raiseLift(650);
        turnRight(1250);
        driveForward(550);
        openClaw();

        //Skills Cube 1
        //driveBackward(100);
        turnLeft(875);
        lowerLift(25);
        driveForward(650);
        wait1Msec(500);
        closeClaw(750);
        driveBackward(100);
        raiseLift(675);
        turnRight(800);
        driveForward(650);
    		openClaw();

    		//Skills Cube 2
    		//driveBackward(100);
    		turnLeft(1000);
        lowerLift(25);
        driveForward(700);
        wait1Msec(500);
        closeClaw(750);
        driveBackward(100);
        raiseLift(675);
        turnRight(1000);
        driveForward(700);
    		openClaw();
    		driveBackward(300);
}
