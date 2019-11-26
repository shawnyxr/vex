/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;
vex::motor lf (vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor lb (vex::PORT3, vex::gearSetting::ratio18_1, true);
vex::motor rf (vex::PORT8, vex::gearSetting::ratio18_1, true);
vex::motor rb (vex::PORT9, vex::gearSetting::ratio18_1, true);
vex::motor arm (vex::PORT7, vex::gearSetting::ratio36_1, false);
vex::motor arm1 (vex::PORT20, vex::gearSetting::ratio36_1,false);
vex::motor claw (vex::PORT13, vex::gearSetting::ratio36_1, false);
vex::motor claw1 (vex::PORT12, vex::gearSetting::ratio36_1, false);
vex::controller Controller;