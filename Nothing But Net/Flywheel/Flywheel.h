//Prevents a variable from going below min or over max
int clamp(int var, int min, int max);

//Do PID calculations for the left flywheel assembly
void computeLeft(void);

//Do PID calculations for the right flywheel assembly
void computeRight(void);

//Set PID gains for either left or right assembly
// 0 = left side, 1 = right side
void setTunings(float pGain, float iGain, float dGain, int side);

//Change the cumulative error portion of the calculation when setpoint changes
//Nothing will happen if NEW or LAST setpoint is 0, as there will be a divide by zero error, try to avoid setting setpoint to zero!
void cumErrorRatio(float newSetPoint);

//Zero Sensors
void resetSensors(void);

//Drive sideways at set power
void mechanumDrive(bool left, int power);

//Turn off all drive motors
void stopDrive(void);
