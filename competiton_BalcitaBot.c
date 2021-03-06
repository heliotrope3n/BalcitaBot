#pragma config(Motor,  port3,           right_wheels,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           left_wheels,   tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           arm1,          tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           arm2,          tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           arm3,          tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           arm4,          tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           arm5,          tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*        Description: Competition template for VEX EDR                      */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(){
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  SensorType[in8] = sensorNone;
	wait1Msec(1000);
	SensorType[in8] = sensorGyro;
	wait1Msec(1500);

}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*---------------------------------------------------------------------------*/

task autonomous(){
	//forwardss
  motor[left_wheels] = -42;
  motor[right_wheels] = 42;
  wait1Msec(8000);
  motor[left_wheels] = 0;
  motor[right_wheels] = 0;
  wait1Msec(300);
  motor[arm1] = -100;
	motor[arm2] = -100;
	motor[arm3] = -100;
	motor[arm4] = -100;
	motor[arm5] = -100;
	wait1Msec(2000);
	motor[arm1] = 0;
	motor[arm2] = 0;
	motor[arm3] = 0;
	motor[arm4] = 0;
	motor[arm5] = 0;
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*---------------------------------------------------------------------------*/

task usercontrol(){
  // User control code here, inside the loop

	int vert_stick, hor_stick;
	int left_motors, right_motors;
	int arms;

  while (true){

		// DRIVING
		// inputs
		vert_stick = vexRT[Ch3];
		hor_stick = round(vexRT[Ch1] * 0.78);
		// deadzone
		if(-13 < vert_stick && vert_stick < 13){
			vert_stick = 0;
		}
		if(-13 < hor_stick && hor_stick< 13){
			hor_stick = 0;
		}
		// calculate speeds
		left_motors = vert_stick + hor_stick;
		right_motors = - vert_stick + hor_stick;
		// set speeds
		motor[left_wheels] = left_motors;
		motor[right_wheels] = right_motors;

		// SHOOTING
		// buttons
		if(vexRT[Btn6U] == 1||vexRT[Btn6UXmtr2] == 1){
			arms = -100;
		}
		else if(vexRT[Btn6D] == 1||vexRT[Btn6DXmtr2] == 1){
			arms = 100;
		}
		else{
			arms = -(vexRT[Ch2Xmtr2]);
		}
		// set speeds
		motor[arm1] = arms;
		motor[arm2] = arms;
		motor[arm3] = arms;
		motor[arm4] = arms;
		motor[arm5] = arms;
	}

}
