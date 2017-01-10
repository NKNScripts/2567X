#ifndef movements
#define movements

#include "Globals.h"
bool driveb(){
	int count = SensorValue[rightEncoder];
	wait10Msec(2);
	return count != SensorValue[rightEncoder];
}
task rotate(){
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
task moveMotor(){
	while(driving) wait10Msec(10);
	driving = true;
	if(distance > 0){
		float cycle = distance / inPerEncoder;
		string s = cycle;
		displayLCDCenteredString(0,s);
		SensorValue[rightEncoder] = 0;
		motor[port3] = 127;
		motor[port8] = 127;
		while(SensorValue[rightEncoder] <= cycle)
			wait1Msec(1);

		} else {
		float cycle = (distance / inPerEncoder);
		string s = cycle;
		displayLCDCenteredString(0,s);
		SensorValue[rightEncoder] = 0;
		motor[port3] = -127;
		motor[port8] = -127;
		while(SensorValue[rightEncoder] >= cycle){
			wait1Msec(1);

		}
	}

	stopMotor(Leftdrive);
	stopMotor(Rightdrive);
	driving = false;
}

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

#endif
