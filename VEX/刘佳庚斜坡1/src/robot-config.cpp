#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor lf = motor(PORT1, ratio18_1, false);
motor lb = motor(PORT2, ratio18_1, false);
motor rf = motor(PORT9, ratio18_1, true);
motor rb = motor(PORT10, ratio18_1, true);
motor arm = motor(PORT5, ratio18_1, false);
motor slop = motor(PORT6, ratio18_1, false);
motor sucker = motor(PORT3, ratio18_1, false);
motor sucker1 = motor(PORT8, ratio18_1, true);
controller Controller1 = controller(primary);
gyro Gyro = gyro(Brain.ThreeWirePort.A);

// VEXcode generated functions
// define variables used for controlling motors based on controller inputs
bool Controller1UpDownButtonsControlMotorsStopped = true;
bool Controller1XBButtonsControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_callback_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    // check the Up/Down Buttons status to control lf
    if (Controller1.ButtonUp.pressing()) {
      lf.spin(forward);
      Controller1UpDownButtonsControlMotorsStopped = false;
    } else if (Controller1.ButtonDown.pressing()) {
      lf.spin(reverse);
      Controller1UpDownButtonsControlMotorsStopped = false;
    } else if (!Controller1UpDownButtonsControlMotorsStopped){
      lf.stop();
      // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
      Controller1UpDownButtonsControlMotorsStopped = true;
    }
    // check the X/B buttons status to control rf
    if (Controller1.ButtonX.pressing()) {
      rf.spin(forward);
      Controller1XBButtonsControlMotorsStopped = false;
    } else if (Controller1.ButtonB.pressing()) {
      rf.spin(reverse);
      Controller1XBButtonsControlMotorsStopped = false;
    } else if (!Controller1XBButtonsControlMotorsStopped){
      rf.stop();
      Controller1XBButtonsControlMotorsStopped = true;
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_callback_Controller1);
}