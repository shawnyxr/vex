/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lenovo                                           */
/*    Created:      Sat Nov 16 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Fast1                motor         9               
// Fast2                motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  wait(5,sec);
  repeat(4) {
  Fast1.spin(forward);
  Fast2.spin(forward);
  Fast1.setVelocity(30,percent);
  Fast2.setVelocity(30,percent);
  wait(2,sec);
  Fast1.spinFor(90, degrees); 
  Fast2.spinFor(-90, degrees); 
}
Fast1.stop(coast);
Fast2.stop(coast);
 
}
      

