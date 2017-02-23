#ifndef programmingskills
#define programmingskills

#include "Globals.h"
#include "Movements.h"
#include "Tasks.h"


void pskills(){
	fence(true);
	distance = -15;
	startTask(moveMotor);
	deg = -180;
	up = false;
	while(driving) wait10Msec(1);
	while(driveb()) wait10Msec(1);
	startTask(lift);
	while(lifting) wait10Msec(2);
	startTask(rotate);
	while(driving)wait10Msec(10);
	distance = 19;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	closeTime = 4;
	close = true;
	startTask(claw);
	wait10Msec(1);
	distance= -19;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	up = true;
	startTask(lift);
	deg = 180;
	startTask(rotate);
	while(lifting) wait10Msec(2);
	distance = 15;
	startTask(moveMotor);
	while(driving) wait10Msec(2);
	closeTime = .7;
	close = false;
	startTask(claw);
	wait10Msec(2);
		distance = -15;
	startTask(moveMotor);
	deg = -180;
	up = false;
	while(driving) wait10Msec(1);
	while(driveb()) wait10Msec(1);
	startTask(lift);
	while(lifting) wait10Msec(2);
	startTask(rotate);
	while(driving)wait10Msec(10);
	distance = 19;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	closeTime = 4;
	close = true;
	startTask(claw);
	wait10Msec(1);
	distance= -19;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	up = true;
	startTask(lift);
	deg = 180;
	startTask(rotate);
	while(lifting) wait10Msec(2);
	distance = 15;
	startTask(moveMotor);
	while(driving) wait10Msec(2);
	closeTime = .7;
	close = false;
	startTask(claw);	distance = -15;
	startTask(moveMotor);
	deg = -180;
	up = false;
	while(driving) wait10Msec(1);
	while(driveb()) wait10Msec(1);
	startTask(lift);
	while(lifting) wait10Msec(2);
	startTask(rotate);
	while(driving)wait10Msec(10);
	distance = 19;
	startTask(moveMotor);
	while(driving) wait10Msec(1);
	closeTime = 4;
	close = true;
	startTask(claw);
	wait10Msec(1);
	distance= -19;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	up = true;
	startTask(lift);
	deg = 180;
	startTask(rotate);
	while(lifting) wait10Msec(2);
	distance = 15;
	startTask(moveMotor);
	while(driving) wait10Msec(2);
	closeTime = .7;
	close = false;
	startTask(claw);
	wait10Msec(2);
		distance = -15;
	startTask(moveMotor);
	deg = -90;
	up = false;
	closeTime = 0.3;
	close = true;
	startTask(claw);
	while(driving) wait10Msec(1);
	while(driveb()) wait10Msec(1);
	startTask(lift);
	while(lifting) wait10Msec(2);
	startTask(rotate);
	while(driving)wait10Msec(10);
	distance = 20;
	startTask(moveMotor);
	while(driving) wait10Msec(10);
	closeTime = 4;
	close = true;
	startTask(claw);
	up = true;
	wait(1);
	distance = 40;
	startTask(moveMotor);
	startTask(lift);
	while(driving) wait10Msec(1);
	deg = 80;
	while(lifting)wait10Msec(1);
	startTask(rotate);
	while(driving)wait10Msec(1);
	distance = 22.5;
	startTask(moveMotor);
	while(driving)wait10Msec(1);
	close = false;
	closeTime = 0.7;
	startTask(claw);
	up = true;
	startTask(lift);
	wait(1);
	liftTime = 0.25;


}


#endif
