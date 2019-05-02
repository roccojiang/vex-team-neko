/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Authors:      Rocco Jiang, Katrina Tse, Jaden Yuen                      */
/*    Created:      Thu May 02 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;
// A global instance of vex::competition
vex::competition Competition;

// Global instances of motors and other devices
vex::motor LeftFrontMotor = vex::motor(vex::PORT1, true);
vex::motor LeftBackMotor = vex::motor(vex::PORT11, true);
vex::motor RightFrontMotor = vex::motor(vex::PORT10, true);
vex::motor RightBackMotor = vex::motor(vex::PORT20, true);
vex::controller Controller = vex::controller();

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void)
{
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void)
{
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void)
{
  // User control code here, inside the loop
  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    // Controller code
    RightBackMotor.spin(directionType::fwd, Controller.Axis3.value() + 0.5 * -Controller.Axis1.value(), velocityUnits::pct);
    RightFrontMotor.spin(directionType::fwd, Controller.Axis3.value() + 0.5 * -Controller.Axis1.value(),velocityUnits::pct);
    LeftFrontMotor.spin(directionType::fwd, -Controller.Axis3.value() + 0.5 * Controller.Axis1.value(), velocityUnits::pct);
    LeftBackMotor.spin(directionType::fwd, -Controller.Axis3.value() + 0.5 * Controller.Axis1.value(), velocityUnits::pct);

    vex::task::sleep(20); // Sleep the task for a short amount of time to prevent wasted resources
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
    // Set up callbacks for autonomous and driver control periods
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);
    
    // Run the pre-autonomous function
    pre_auton();
       
    // Prevent main from exiting with an infinite loop
    while (true)
    {
      vex::task::sleep(100); // Sleep the task for a short amount of time to prevent wasted resources
    }
}