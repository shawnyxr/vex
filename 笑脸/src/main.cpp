/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lenovo                                           */
/*    Created:      Fri Nov 15 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Screen.drawCircle(225,120,110);
  Brain.Screen.drawLine(180,160,230,180);
  Brain.Screen.drawLine(230,180,285,160);
  Brain.Screen.drawRectangle(225,110,10,30);
  Brain.Screen.setPenWidth(5);
  Brain.Screen.setFillColor(orange);
  Brain.Screen.setPenColor(blue);
  Brain.Screen.drawCircle(180,70,25);
  Brain.Screen.setOrigin(100,0);
  Brain.Screen.drawCircle(180,70,25);
  Brain.Screen.setFillColor(black);
  Brain.Screen.setPenWidth(3);
  Brain.Screen.drawCircle(170,75,8);
  Brain.Screen.setOrigin(0,0);
  Brain.Screen.drawCircle(190,75,8);
}
