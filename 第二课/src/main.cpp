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
// Fast1                motor         2               
// Fast2                motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Fast1.spin(forward);
  Fast2.spin(forward);
  Fast1.setVelocity(30,percent);
  Fast2.setVelocity(30,percent);  
  wait(5,sec);
  Fast1.stop(coast); 
  Fast2.stop(coast);
  wait(1,sec);
  Fast1.spin(forward);
  Fast2.spin(forward);
  Fast1.setVelocity(-60,percent);
  Fast2.setVelocity(-60,percent);    
  wait(3,sec);
  Fast1.stop(coast); 
  Fast2.stop(coast);
  }
  


 

