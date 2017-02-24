#ifndef lcd
#define lcd
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------



//Declare count variable to keep track of our choice
int count = 0;
string mainBattery, backupBattery;

int getCount(){
	return count;
}

void lcdSetup()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.


	//bStopTasksBetweenModes = true;  //ADD THIS BACK TO COMP CODE!!!!!!!!!!!!


	//for lcd
	{
		//------------- Beginning of User Interface Code ---------------
		//Clear LCD
		clearLCDLine(0);
		clearLCDLine(1);
		//Loop while center button is not pressed
		while(nLCDButtons != centerButton)
		{
			//Switch case that allows the user to choose from 4 different options
			switch(count){
			case 0:
				//Display first choice
				displayLCDCenteredString(0, "Autonomous Left");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count = 6;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
			case 1:
				//Display second choice
				displayLCDCenteredString(0, "Auton Right Star");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
			case 2:
				//Display third choice
				displayLCDCenteredString(0, "Auton Left Cube");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
			case 3:
				//Display fourth choice
				displayLCDCenteredString(0, "Auton Right Cube");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
			default:
				count++;
				break;

			case 4:
				//Display third choice
				displayLCDCenteredString(0, "Autonomous Right");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
				case 6:
				//Display third choice
				displayLCDCenteredString(0, "Autonomous Left Star");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
					case 7:
				//Display third choice
				displayLCDCenteredString(0, "Skills");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;

			case 8:

				//Display the Primary Robot battery voltage
				displayLCDString(0, 0, "Primary: ");
				sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
				displayNextLCDString(mainBattery);

				//Display the Backup battery voltage
				displayLCDString(1, 0, "Backup: ");
				sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');	//Build the value to be displayed
				displayNextLCDString(backupBattery);

				//Short delay for the LCD refresh rate
				wait1Msec(100);
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count = 0;
				}
				break;
			case 5:
				//Display fourth choice
				displayLCDCenteredString(0, "User Control");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
			default:
				count = 0;
				break;
			}
		}
	}
}
#endif lcd
