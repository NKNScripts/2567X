#ifndef movements
#define movements

#include "Globals.h"
/**
*
*desc: Method to show if the bot is moving
* return: bool, true if moving
*/
bool driveb(){
	int count = SensorValue[rightEncoder];
	wait10Msec(2);
	return count != SensorValue[rightEncoder];
}
task rotate(){
	SensorValue[in1] = 0;
	float tDegrees = deg * 10;
	while(driving) wait10Msec(10);
	driving = true;
	if(tDegrees > 0){
		int read = SensorValue[in1];
		motor[Leftdrive] = -60;
		motor[Rightdrive] = 60;
		while(read < (tDegrees-350)){
			wait1Msec(5);
			read = SensorValue[in1];
		}
		motor[Leftdrive] = -35;
		motor[Rightdrive] = 35;
		while(read < tDegrees){
			wait1Msec(5);
			read = SensorValue[in1];
		}
		motor[Leftdrive] = 20;
		motor[Rightdrive] = -20;
		wait1Msec(20);
		stopMotor(Leftdrive);
		stopMotor(Rightdrive);
		string s = SensorValue[in1];
		displayLCDCenteredString(0,s);
	} else {
		int read = SensorValue[in1];
		motor[Leftdrive] = 60;
		motor[Rightdrive] = -60;
		while(read > (tDegrees+350)){
			wait1Msec(5);
			read = SensorValue[in1];
		}
		motor[Leftdrive] = 35;
		motor[Rightdrive] = -35;
		while(read > tDegrees){
			wait1Msec(5);
			read = SensorValue[in1];
		}
		motor[Leftdrive] = -20;
		motor[Rightdrive] = 20;
		wait1Msec(20);
		stopMotor(Leftdrive);
		stopMotor(Rightdrive);
		string s = SensorValue[in1];
		displayLCDCenteredString(0,s);
	}
	driving = false;
}
/**
*desc: Takes input from degrees in globals.h and rotates the bot the appropriate degrees.
*
*/
task rotateBackup(){
	while(driving) wait10Msec(10);
	driving = true;
	if(deg > 0){
		float cycle = deg / degreePerEncoder;
		string s = cycle;
		displayLCDCenteredString(0,s);
		SensorValue[rightEncoder] = 0;
		motor[port3] = -75;
		motor[port8] = 75;
		wait(cycle);

		} else {
		float cycle = -(deg / degreePerEncoder);
		string s = cycle;
		displayLCDCenteredString(0,s);
		SensorValue[rightEncoder] = 0;
		motor[port3] = 75;
		motor[port8] = -75;
		wait(cycle);


	}

	stopMotor(Leftdrive);
	stopMotor(Rightdrive);
	driving = false;
}
/**
*desc: Takes input from distance in globals.h and moves the bot the appopriate distance.
*
*/
task moveMotor(){
	while(driving) wait10Msec(10);
	driving = true;
	if(distance > 0){
		float cycle = distance / inPerEncoder;
		SensorValue[rightEncoder] = 0;
		motor[port3] = 127;
		motor[port8] = 127;
		while(SensorValue[rightEncoder] <= cycle)
			wait1Msec(1);

		} else {
		float cycle = (distance / inPerEncoder);
		SensorValue[rightEncoder] = 0;
		motor[port3] = -127;
		motor[port8] = -127;
		while(SensorValue[rightEncoder] >= cycle){
			wait1Msec(1);

		}
	}
	motor[Leftdrive] = -25;
	motor[Rightdrive] = -25;
	wait(0.2);
	stopMotor(Leftdrive);
	stopMotor(Rightdrive);
	driving = false;
}
/**
*
*desc: Takes a second input from globals.h and lifts the barlift for that amount
*/
task liftSecond(){
	lifting = true;
	if(up){
		motor[lift1] = -125;
		motor[lift2] = -125;
		motor[lift3] = -125;
		motor[lift4] = -125;
		wait(liftTime);
		stopMotor(lift1);
		stopMotor(lift2);
		stopMotor(lift3);
		stopMotor(lift4);
		} else {
		motor[lift1] = 125;
		motor[lift2] = 125;
		motor[lift3] = 125;
		motor[lift4] = 125;
		wait(liftTime);
		stopMotor(lift1);
		stopMotor(lift2);
		stopMotor(lift3);
		stopMotor(lift4);
	}
	lifting = false;
}

/**
*desc: Lifts the motors until it reaches 115 encoder count
*
*/
task lift(){
	lifting = true;
	if(up){
		motor[lift1] = -125;
		motor[lift2] = -125;
		motor[lift3] = -125;
		motor[lift4] = -125;
		while(SensorValue[liftEncoder] < 115) wait1Msec(5);
		stopMotor(lift1);
		stopMotor(lift2);
		stopMotor(lift3);
		stopMotor(lift4);
		} else {
		motor[lift1] = 125;
		motor[lift2] = 125;
		motor[lift3] = 125;
		motor[lift4] = 125;
		while(SensorValue[liftEncoder] > 5) wait1Msec(5);
		stopMotor(lift1);
		stopMotor(lift2);
		stopMotor(lift3);
		stopMotor(lift4);
	}
	lifting = false;
}
/**
*
*desc: Lifts lift from lCount encoder
*/
task liftC(){
	lifting = true;
	if(up){
		motor[lift1] = -125;
		motor[lift2] = -125;
		motor[lift3] = -125;
		motor[lift4] = -125;
		while(SensorValue[liftEncoder] < lCount) wait1Msec(5);
		stopMotor(lift1);
		stopMotor(lift2);
		stopMotor(lift3);
		stopMotor(lift4);
		} else {
		motor[lift1] = 125;
		motor[lift2] = 125;
		motor[lift3] = 125;
		motor[lift4] = 125;
		while(SensorValue[liftEncoder] > 5) wait1Msec(5);
		stopMotor(lift1);
		stopMotor(lift2);
		stopMotor(lift3);
		stopMotor(lift4);
	}
	lifting = false;
}
/**
*desc: Opens or closes claw
*
*/
task claw(){
	if(close){
		motor[Leftclaw] = 127;
		motor[Rightclaw] = 127;
		wait(closeTime);
		stopMotor(Rightclaw);
		stopMotor(Leftclaw);
		} else {
		motor[Leftclaw] = -127;
		motor[Rightclaw] = -127;
		wait(closeTime);
		stopMotor(Rightclaw);
		stopMotor(Leftclaw);
	}
}

task moveMotorCC(){
	while(driving) wait10Msec(10);
	driving = true;
	if(distance > 0){
		float cycle = distance / inPerEncoder;
		SensorValue[rightEncoder] = 0;
		motor[port3] = 127;
		motor[port8] = 70;
		while(SensorValue[rightEncoder] <= cycle)
			wait1Msec(1);

		} else {
		float cycle = (distance / inPerEncoder);
		SensorValue[rightEncoder] = 0;
		motor[port3] = -127;
		motor[port8] = -70;
		while(SensorValue[rightEncoder] >= cycle){
			wait1Msec(1);

		}
	}
	motor[Leftdrive] = -25;
	motor[Rightdrive] = -25;
	wait(0.2);
	stopMotor(Leftdrive);
	stopMotor(Rightdrive);
	driving = false;
}

task moveMotorC(){
	while(driving) wait10Msec(10);
	driving = true;
	if(distance > 0){
		float cycle = distance / inPerEncoder;
		SensorValue[rightEncoder] = 0;
		motor[port3] = 70;
		motor[port8] = 127;
		while(SensorValue[rightEncoder] <= cycle)
			wait1Msec(1);

		} else {
		float cycle = (distance / inPerEncoder);
		SensorValue[rightEncoder] = 0;
		motor[port3] = -70;
		motor[port8] = -127;
		while(SensorValue[rightEncoder] >= cycle){
			wait1Msec(1);

		}
	}
	motor[Leftdrive] = -25;
	motor[Rightdrive] = -25;
	wait(0.2);
	stopMotor(Leftdrive);
	stopMotor(Rightdrive);
	driving = false;
}


#endif
