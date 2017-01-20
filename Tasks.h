#ifndef tasks
#define tasks

#include "Globals.h"
#include "Movements.h"
/**
*desc: Auton for the left start position to grab back cube
*
*/
void auton_leftcube(){
	motor[Leftdrive] = 50;
	motor[Rightdrive] = 127;
	wait(0.3);
	motor[Leftdrive] = 127;
	closeTime = 0.7;
	close = true;
	startTask(claw);
	wait(0.4);
	lCount = 70;
	startTask(liftC);
	wait(0.3);
	motor[Rightdrive] = 30;
	wait(0.5);
	motor[Rightdrive] = 127;
	wait(0.9);
	distance = -10;
	startTask(moveMotor);
	deg = -100;
	up = false;
	while(driving) wait10Msec(1);
	while(driveb()) wait10Msec(1);
	startTask(lift);
	while(lifting) wait10Msec(2);
	startTask(rotate);
	distance = 10;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	closeTime = 3;
	close = true;
	startTask(claw);
	up = true;
	wait(1);
	distance = 3;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	startTask(lift);
	deg = 165;
	startTask(rotate);
	while(driving)wait10Msec(1);
	distance = 10;
	startTask(moveMotor);
	while(driving)wait10Msec(1);
	close = false;
	closeTime = 0.6;
	startTask(claw);
	wait(1);
	liftTime = 0.25;
	distance = -10;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	up = false;
	while(driveb())wait10Msec(1);
	startTask(liftSecond);
	while(lifting) wait10Msec(1);
	liftTime = 0.10;
	up = true;
	startTask(liftSecond);
	while(lifting) wait10Msec(1);
	distance = 20;
	startTask(moveMotor);

}
/**
*desc: Auton for the right start position to grab cube
*
*/

void auton_rightcube(){
	motor[Leftdrive] = 127;
	motor[Rightdrive] = 50;
	wait(0.3);
	motor[Rightdrive] = 127;
	closeTime = 0.7;
	close = true;
	startTask(claw);
	wait(0.4);
	lCount = 70;
	startTask(liftC);
	wait(0.3);
	motor[Leftdrive] = 30;
	wait(0.5);
	motor[Leftdrive] = 127;
	wait(0.9);
	distance = -10;
	startTask(moveMotor);
	deg = 100;
	up = false;
	while(driving) wait10Msec(1);
	while(driveb()) wait10Msec(1);
	startTask(lift);
	while(lifting) wait10Msec(2);
	startTask(rotate);
	distance = 10;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	closeTime = 3;
	close = true;
	startTask(claw);
	up = true;
	wait(1);
	distance = 3;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	startTask(lift);
	deg = -165;
	startTask(rotate);
	while(driving)wait10Msec(1);
	distance = 10;
	startTask(moveMotor);
	while(driving)wait10Msec(1);
	close = false;
	closeTime = 0.6;
	startTask(claw);
	wait(1);
	liftTime = 0.25;
	distance = -10;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	up = false;
	while(driveb())wait10Msec(1);
	startTask(liftSecond);
	while(lifting) wait10Msec(1);
	liftTime = 0.10;
	up = true;
	startTask(liftSecond);
	while(lifting) wait10Msec(1);
	distance = 20;
	startTask(moveMotor);
}

/**
*desc: Auton for the left start position to hit fence stars
*
*/
void auton_left(){

	motor[Leftdrive] = 50;
	motor[Rightdrive] = 127;
	wait(0.3);
	motor[Leftdrive] = 127;
	closeTime = 0.7;
	close = true;
	startTask(claw);
	wait(0.4);
	lCount = 70;
	startTask(liftC);
	wait(0.3);
	motor[Rightdrive] = 30;
	wait(0.5);
	motor[Rightdrive] = 127;
	wait(0.9);
	distance = -5;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	while(driveb()) wait10Msec(1);
}
/**
*desc: Auton for the right start position to knock fence stars off
*
*/
void auton_right() {

	motor[Leftdrive] = 127;
	motor[Rightdrive] = 50;
	wait(0.3);
	motor[Rightdrive] = 127;
	closeTime = 0.7;
	close = true;
	startTask(claw);
	wait(0.4);
	lCount = 70;
	startTask(liftC);
	wait(0.3);
	motor[Leftdrive] = 30;
	wait(0.5);
	motor[Leftdrive] = 127;
	wait(0.9);
	distance = -5;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	while(driveb()) wait10Msec(1);
}

/**
*desc: Auton for the left start position to grab back stars.
*
*/
void Auton_Left_Star() {
	motor[Leftdrive] = 50;
	motor[Rightdrive] = 127;
	wait(0.3);
	motor[Leftdrive] = 127;
	closeTime = 0.7;
	close = true;
	startTask(claw);
	wait(0.4);
	lCount = 70;
	startTask(liftC);
	wait(0.3);
	motor[Rightdrive] = 30;
	wait(0.5);
	motor[Rightdrive] = 127;
	wait(0.9);
	distance = -17;
	startTask(moveMotor);
	wait(0.5);
	closeTime = 0.46;
	close = true;
	startTask(claw);
	deg = -125;
	up = false;
	while(driving) wait10Msec(1);
	wait(0.50);
	startTask(rotate);
	while(driving) wait10Msec(1);
	startTask(lift);
	while(lifting) wait10Msec(2);
	distance = 11;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	closeTime = 3.5;
	close = true;
	startTask(claw);
	up = true;
	wait(1);
	distance = -13;
	startTask(moveMotor);
	startTask(lift);
	wait(2);
	deg = 140;
	startTask(rotate);
	while(driving)wait10Msec(1);
	distance = 17;
	startTask(moveMotor);
	up = true;
	startTask(lift);
	wait(3);
	close = false;
	closeTime = 0.6;
	startTask(claw);

}

/**
*desc: Auton for the right start position to grab back stars.
*
*/
void Auton_Right_Star() {
	motor[Leftdrive] = 127;
	motor[Rightdrive] = 50;
	wait(0.3);
	motor[Rightdrive] = 127;
	closeTime = 0.7;
	close = true;
	startTask(claw);
	wait(0.4);
	lCount = 70;
	startTask(liftC);
	wait(0.3);
	motor[Leftdrive] = 30;
	wait(0.5);
	motor[Leftdrive] = 127;
	wait(0.9);
	distance = -17;
	startTask(moveMotor);
	wait(0.5);
	closeTime = 0.46;
	close = true;
	startTask(claw);
	deg = 125;
	up = false;
	while(driving) wait10Msec(1);
	wait(0.50);
	startTask(rotate);
	while(driving) wait10Msec(1);
	startTask(lift);
	while(lifting) wait10Msec(2);
	distance = 11;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	closeTime = 3.5;
	close = true;
	startTask(claw);
	up = true;
	wait(1);
	distance = -13;
	startTask(moveMotor);
	startTask(lift);
	wait(2);
	deg = -140;
	startTask(rotate);
	while(driving)wait10Msec(1);
	distance = 17;
	startTask(moveMotor);
	up = true;
	startTask(lift);
	while(driving)wait10Msec(1);
	close = false;
	closeTime = 0.6;
	startTask(claw);
}

void userControl()
{
	// User control code here, inside the loop

	while (true)
	{
		// This is the main execution loop for the user control program.
		// Each time through the loop your program should update motor + servo
		// values based on feedback from the joysticks.
		// ........................................................................
		// Insert user code here. This is where you use the joystick values to
		// update your motors, etc.
		// ........................................................................

		// Remove this function call once you have "real" code.
		//base drive
		motor[port3] = vexRT[Ch3]; //left
		motor[port8] = vexRT[Ch2]; //right

		//lift
		if(vexRT[Btn5U] == 1) //Button 5U bar lift up if limit switch is not pushed
		{
			motor[port5] = -127;
			motor[port6] = -127;
			motor[port4] = -127;
			motor[port7] = -127;
			liftCount = SensorValue[liftEncoder];
		}
		else if(vexRT[Btn5D] == 1) //Button 5D bar lift down
		{
			motor[port5] = 127;
			motor[port6] = 127;
			motor[port4] = 127;
			motor[port7] = 127;
			liftCount = 0;
		}
		else if(!liftInUse)
		{

			motor[port5] = 0; //Neither, all lift motors stopped
			motor[port6] = 0;
			motor[port4] = 0;
			motor[port7] = 0;

		}
		if(vexRT[Btn6U] == 1) //Opens Claw
		{
			motor[port2]=127;
			motor[port9]=127;
		}
		else if(vexRT[Btn6D] == 1) //Closes Claw
		{
			motor[port2]=-127;
			motor[port9]=-127;
		}
		else
		{
			motor[port2]=0;
			motor[port9]=0;
		}
		string s = SensorValue(liftEncoder);
		//displayLCDCenteredString(1,s);


	}
}
#endif
