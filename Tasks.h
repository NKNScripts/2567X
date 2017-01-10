#ifndef tasks
#define tasks

#include "Globals.h"
#include "Movements.h"

void auton_leftcube(){
	up = true;
	close = true;

	distance = 22;  //Bot moves forward
	startTask(moveMotor);
	close = true;
	startTask(claw);  //Bot closes claw on Pre-Load
	wait(2);
	up = true;
	startTask(lift);  //Bot lifts
	closeTime = 2.5;
	close = true;
	startTask(claw);  //claw closes for more support
	wait(1);
	distance = 45;
	startTask(moveMotor); //bot moves forward
	wait(1);
	closeTime = 1;
	close = false;
	startTask(claw);  //bot opens claw to drop Pre-Load
	wait(1);
	distance = -32;
	startTask(moveMotor);  //bot moves backward

	deg = -90;
	up = false;
	while(driving) wait10Msec(1);


	while(driveb()) wait10Msec(1);

	startTask(lift);
	while(lifting) wait10Msec(2);
	startTask(rotate);

	distance = 30;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	closeTime = 3;
	close = true;
	startTask(claw);
	up = true;
	wait(1.5);

	startTask(lift);
	deg = 145;
	startTask(rotate);
	while(driving)wait10Msec(1);
	distance = 35;
	startTask(moveMotor);
	while(driving)wait10Msec(1);
	close = false;
	closeTime = 0.6;
	startTask(claw);
	wait(1);
	liftTime = 0.4;
	distance = -10;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	up = false;
	while(driveb())wait10Msec(1);
	startTask(liftSecond);
	while(lifting) wait10Msec(1);
	liftTime = 0.1;
	up = true;
	startTask(liftSecond);
	while(lifting) wait10Msec(1);
	distance = 20;
	startTask(moveMotor);
}
void auton_rightcube(){
	up = true;
	close = true;

	distance = 22;  //Bot moves forward
	startTask(moveMotor);
	close = true;
	startTask(claw);  //Bot closes claw on Pre-Load
	wait(2);
	up = true;
	startTask(lift);  //Bot lifts
	closeTime = 2.5;
	close = true;
	startTask(claw);  //claw closes for more support
	wait(1);
	distance = 45;
	startTask(moveMotor); //bot moves forward
	wait(1);
	closeTime = 1;
	close = false;
	startTask(claw);  //bot opens claw to drop Pre-Load
	wait(1);
	distance = -32;
	startTask(moveMotor);  //bot moves backward

	deg = 90;
	up = false;
	while(driving) wait10Msec(1);


	while(driveb()) wait10Msec(1);

	startTask(lift);
	while(lifting) wait10Msec(2);
	startTask(rotate);

	distance = 30;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	closeTime = 3;
	close = true;
	startTask(claw);
	up = true;
	wait(1.5);

	startTask(lift);
	deg = -145;
	startTask(rotate);
	while(driving)wait10Msec(1);
	distance = 35;
	startTask(moveMotor);
	while(driving)wait10Msec(1);
	close = false;
	closeTime = 0.6;
	startTask(claw);
	wait(1);
	liftTime = 0.4;
	distance = -10;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	up = false;
	while(driveb())wait10Msec(1);
	startTask(liftSecond);
	while(lifting) wait10Msec(1);
	liftTime = 0.1;
	up = true;
	startTask(liftSecond);
	while(lifting) wait10Msec(1);
	distance = 20;
	startTask(moveMotor);
}
void auton_left(){

up = true;
	close = true;

	distance = 22;  //Bot moves forward
	startTask(moveMotor);
	close = true;
	startTask(claw);  //Bot closes claw on Pre-Load
	wait(2);
	up = true;
	startTask(lift);  //Bot lifts
	closeTime = 2.5;
	close = true;
	startTask(claw);  //claw closes for more support
	wait(1);
	distance = 45;
	startTask(moveMotor); //bot moves forward
	wait(1);
	closeTime = 1;
	close = false;
	startTask(claw);  //bot opens claw to drop Pre-Load
	wait(1);
	distance = -32;
	startTask(moveMotor);  //bot moves backward
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
