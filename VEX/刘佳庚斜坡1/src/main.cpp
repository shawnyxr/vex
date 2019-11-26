#include "vex.h"

using namespace vex;

competition Competition;

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\刘佳庚                                              */
/*    Created:      Sat Nov 09 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// lf                   motor         1               
// lb                   motor         2               
// rf                   motor         9               
// rb                   motor         10              
// arm                  motor         5               
// slop                 motor         6               
// sucker               motor         3               
// sucker1              motor         8               
// Controller1          controller                    
// Gyro                 gyro          A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

/*void reset(){}
  lf.resetRotation();
  lb.resetRotation();
  rf.resetRotation();
  rb.resetRotation();
}
void go(int left,int right){
  lf.spin(directionType::fwd,left,velocityUnits::pct);
  lb.spin(directionType::fwd,left,velocityUnits::pct);
  rf.spin(directionType::fwd,right,velocityUnits::pct);
  rb.spin(directionType::fwd,right,velocityUnits::pct);
}
void stopb(){
  lf.stop(brakeType::brake);
  lb.stop(brakeType::brake);
  rf.stop(brakeType::brake);
  rb.stop(brakeType::brake);
}
void suckerCtrl(){
  if(Controller1.ButtonR2.pressing()==1){
    sucker.spin(directionType::fwd,100,velocityUnits::pct);
    sucker1.spin(directionType::rev,100,velocityUnits::pct);
  }
  else if(Controller1.ButtonR1.pressing()==1){
    sucker.spin(directionType::rev,100,velocityUnits::pct);
    sucker1.spin(directionType::fwd,100,velocityUnits::pct);
  }
  else if(Controller1.ButtonX.pressing()==0){
    sucker.stop(brakeType::brake);
    sucker1.stop(brakeType::brake);
  }
}
void slopCtrl(){
  if(Controller1.Axis3.value()>0&&slop.rotation(rotationUnits::deg)<800){
    slop.spin(directionType::fwd,Controller1.Axis3.value(),velocityUnits::pct);
  }
  else if(Controller1.Axis3.value()>0&&slop.rotation(rotationUnits::deg)>800){
    slop.spin(directionType::fwd,15,velocityUnits::pct);
  }
  else if(Controller1.Axis3.value()<0){
    slop.spin(directionType::fwd,Controller1.Axis3.value(),velocityUnits::pct);
  }
  else if(Controller1.ButtonL1.pressing()==0&&Controller1.ButtonL2.pressing()==0){
    slop.stop(brakeType::hold);
  }
}
void armCtrl(){
  if(Controller1.ButtonL1.pressing()==1){
    if(arm.rotation(rotationUnits::deg)<380){
      arm.spin(directionType::fwd,100,velocityUnits::pct);
      slop.spin(directionType::fwd,60,velocityUnits::pct);
    }
    else{
      arm.spin(directionType::fwd,100,velocityUnits::pct);
    }
  }
  else if(Controller1.ButtonL2.pressing()==1){
    if(arm.rotation(rotationUnits::deg)<590){
      arm.spin(directionType::rev,100,velocityUnits::pct);
      slop.spin(directionType::rev,100,velocityUnits::pct);
    }
    else{
      arm.spin(directionType::rev,100,velocityUnits::pct);
    }
  }
  else{
    arm.stop(brakeType::hold);
  }
}
void back_out(){
  if(Controller1.ButtonX.pressing()==1){
    arm.resetRotation();
    reset();
    while(1){
      go(-40,-40);
      sucker.spin(directionType::rev,40,velocityUnits::pct);
      sucker1.spin(directionType::fwd,40,velocityUnits::pct);
      if(Controller1.Axis2.value()!=0||Controller1.Axis1.value()!=0){
        break;
      }
    }
    stopb();
    sucker.stop(brakeType::brake);
    sucker1.stop(brakeType::brake);
  }
}

void GoS(int distance,int speed){
  reset();
  if(distance>0){
    while(lf.rotation(rotationUnits::deg)<=distance){
      go(speed,speed);
      sucker.spin(directionType::fwd,100,velocityUnits::pct);
      sucker1.spin(directionType::fwd,100,velocityUnits::pct);
    }
  }
  else if(distance<0){
    while(lf.rotation(rotationUnits::deg)>=distance){
      go(-speed,-speed);
      sucker.spin(directionType::rev,100,velocityUnits::pct);
      sucker1.spin(directionType::rev,100,velocityUnits::pct);
    }
  }
  stopb();
  sucker.stop(brakeType::brake);
  sucker1.stop(brakeType::brake);
}

void tuL(int ldeg,int speed){
  while(Gyro.value(rotationUnits::deg)>=-ldeg){
    speed=(ldeg+Gyro.value(rotationUnits::deg))/ldeg+7;
    go(-speed,speed);
  }
  stopb();
}

void tuR(int rdeg,int speed){
  while(Gyro.value(rotationUnits::deg)<+rdeg){
    speed=(rdeg-Gyro.value(rotationUnits::deg))/rdeg+7;
    go(speed,-speed);
  }
  stopb();
}

void suckerA(int time,int speed){
  sucker.spin(directionType::fwd,speed,velocityUnits::pct);
  sucker1.spin(directionType::fwd,speed,velocityUnits::pct);
  task::sleep(time);
  sucker.stop(brakeType::brake);
  sucker1.stop(brakeType::brake);
}

void armA(int deg,int speed){
  arm.resetRotation();
  if(deg>=0){
    while(arm.rotation(rotationUnits::deg)<deg){
      arm.spin(directionType::fwd,speed,velocityUnits::pct);
    }
    arm.stop(brakeType::hold);
  }
  else{
    while(arm.rotation(rotationUnits::deg)>deg){
      arm.spin(directionType::rev,speed,velocityUnits::pct);
    }
    arm.stop(brakeType::hold);
  }
  arm.resetRotation();
}

void slopeA(int deg,int speed){
  slop.resetRotation();
  if(deg>=0){
    while(slop.rotation(rotationUnits::deg)<deg){
      slop.spin(directionType::fwd,speed,velocityUnits::pct);
    }
    slop.stop(brakeType::hold);
  }
  else{
    while(slop.rotation(rotationUnits::deg)>deg){
      slop.spin(directionType::rev,speed,velocityUnits::pct);
    }
    slop.stop(brakeType::hold);
  }
  slop.resetRotation();
}

void pre_auton(void) {
  vexcodeInit();
  Gyro.calibrate(2);
}


void autonomous(void) {
  GoS(950,40);
  suckerA(700,100);
  tuR(90,100);
  GoS(250,30);
  tuR(30,100);
  GoS(300,20);
}

int Left;
int Right;
bool slow;
void usercontrol(void) {
  while(1){
  Left=Controller1.Axis2.value()+Controller1.Axis1.value();
    Right=Controller1.Axis2.value()-Controller1.Axis1.value();
    slow=Controller1.ButtonUp.pressing()||Controller1.ButtonDown.pressing()||Controller1.ButtonLeft.pressing()||Controller1.ButtonRight.pressing();
    if(Controller1.Axis2.value()!=0||Controller1.Axis1.value()){
      if(slow){
        go(Left/5.5,Right/5.5);
      }
      else{
        go(Left,Right);
      }
    }
    else if(Controller1.ButtonX.pressing()==0){
      stopb();
    }
    suckerCtrl();
    slopCtrl();
    armCtrl();
    back_out();
    wait(20, msec); 
  }
  }


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}*/

int main(){
  
}


