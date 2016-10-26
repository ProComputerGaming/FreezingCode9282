#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  IEM1,           sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  IEM2,           sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393_HBridge, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){
  wait1Msec(2000);

  //Clear the encoders associated with the left and right motors
  nMotorEncoder[rightMotor] = 0;
  nMotorEncoder[leftMotor] = 0;

  //While less than 1000 encoder counts of the right motor
  while(nMotorEncoder[rightMotor] < 392)
  {
    //Move forward at half power
    motor[rightMotor] = 127;
    motor[leftMotor] = 127;
  }

}
