/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Steven                                           */
/*    Created:      Sat Nov 23 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// r1                   motor         2               
// l2                   motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true){
  r1.spin(forward);
  l2.spin(forward);
  //r1.setVelocity(50,percent);
  //l2.setVelocity(50,percent);
  r1.spin(directionType::fwd,Controller1.Axis4.value()*0.75-Controller1.Axis3.value(),velocityUnits::pct);
  l2.spin(directionType::fwd,Controller1.Axis3.value()+Controller1.Axis4.value()*0.75,velocityUnits::pct);
  //r1.spin(directionType::fwd,Controller1.Axis1.value(),velocityUnits::pct);
  //l2.spin(directionType::fwd,Controller1.Axis1.value(),velocityUnits::pct);
  }
}
//r1.spin(directionType::fwd,Controller1.Axis2.value()+Controller1.Axis1.value(),velocityUnits::pct);
  //l2.spin(directionType::fwd,Controller1.Axis1.value()-Controller1.Axis2.value(),velocityUnits::pct);