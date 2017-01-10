#ifndef background
#define background
#include "Globals.h"

task preventClawDrop(){
 displayLCDCenteredString(0,"TASK");
	while(true){
		if(!vexRT(Btn5U)){
			string s = SensorValue[liftEncoder];
			displayLCDCenteredString(1,s);
			string c = liftCount;
			displayLCDCenteredString(0,c);
			if(SensorValue[liftEncoder] < liftCount){
				liftInUse = true;
				motor[port4] = -50;
				motor[port5] = -50;
				motor[port6] = -50;
				motor[port7] = -50;
				while(SensorValue[liftEncoder] < liftCount){
					wait1Msec(10);
				}
				liftInUse = false;
				stopMotor(port4);
				stopMotor(port5);
				stopMotor(port6);
				stopMotor(port7);

			}
		}
		wait10Msec(1);
	}

}
#endif background
