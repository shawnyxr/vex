/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Steven                                           */
/*    Created:      Fri Nov 22 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// text1                motor         1               
// Controller1          controller                    
// text2                motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true){
  text1.spin(forward);
  //text1.setVelocity(50,percent);
  text1.setVelocity(Controller1.Axis3.value(),percent);
  //text1.spin(directionType::fwd,Controller1.Axis1.value(),velocityUnits::pct);
  text2.spin(forward);
  //text2.setVelocity(50,percent);
  text2.setVelocity(Controller1.Axis3.value(),percent);
  //text2.spin(directionType::fwd,Controller1.Axis1.value(),velocityUnits::pct);
  }

  while(true){
    Brain.Screen.print(Controller1.Axis1.value());
    wait(1,sec);
    
  }

  






  
}
