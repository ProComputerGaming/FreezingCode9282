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
