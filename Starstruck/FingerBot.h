enum Direction{
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
};

int lightArray[6];

task fingerMonitor();
task lightMonitor();
task wheelMonitor();
void analogDrive();
void setAutonMove(Direction d, int targetTicks);
void dLeft(bool backwards);
void dRight(bool backwards);
void driveForward(int ticks);
void driveBackward(int ticks);
void turnRight(int ticks);
void turnLeft(int ticks);
void strafeRight(int millis);
void strafeLeft(int millis);
void raiseLift(int targetTicks);
void lowerLift(int targetTicks);
void raiseLift(int targetTicks, int speed);
void lowerLift(int targetTicks, int speed);
void closeClaw(int millis);
void openClaw();
void stopLift();
void stopLeft();
void stopRight();
void stopDrive();
void stopAllMotors();
void zeroDriveSensors();
int programSelected(int segments);
int clamp(int var, int min, int max);
