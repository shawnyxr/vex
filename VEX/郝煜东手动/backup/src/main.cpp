#include "vex.h"
using namespace vex;
vex::brain       Brain;
/*                                                      ↑配置↑
-----------------------------------------------------神奇的分割线-----------------------------------------------------
                                                      ↓程序↓                                                       */

void go(int left,int right) {
  lf.spin(directionType::fwd, left, vex::velocityUnits::pct);
  lb.spin(directionType::fwd, left, vex::velocityUnits::pct);
  rf.spin(directionType::rev, right, vex::velocityUnits::pct);
  rb.spin(directionType::rev, right, vex::velocityUnits::pct);
}
void reset() {
  lf.resetRotation();
  lb.resetRotation();
  rf.resetRotation();
  rb.resetRotation();
}
void stopb() {
  lf.stop(brakeType::brake);
  lb.stop(brakeType::brake);
  rf.stop(brakeType::brake);
  rb.stop(brakeType::brake);
}
/*void wheelCtrl(int left,int right) {
  if(Controller.Axis1.value()!=0||Controller.Axis1.value()!=0) {
    if(Controller.ButtonUp.pressing()==1||Controller.ButtonDown.pressing()==1||Controller.ButtonLeft.pressing()==1||Controller.ButtonRight.pressing()==1==true) {
      go(left/5.5,right/5.5);
    }
    else {
      go(left,right);
    }
  }
  else {
    stopb();
  }
}*/
void fwa(int fwavau,int fwadeg) {
  while(lf.rotation(rotationUnits::deg)<fwadeg||lb.rotation(rotationUnits::deg)<fwadeg||rf.rotation(rotationUnits::deg)<fwadeg||rb.rotation(rotationUnits::deg)<fwadeg) {
    go(fwavau,fwavau);
  }
  reset();
  stopb();
}
void bak(int bakvau,int bakdeg) {
  while(lf.rotation(rotationUnits::deg)<bakdeg||lb.rotation(rotationUnits::deg)<bakdeg||rf.rotation(rotationUnits::deg)<bakdeg||rb.rotation(rotationUnits::deg)<bakdeg) {
    go(bakvau,bakvau);
  }
  reset();
  stopb();
}
void armCtrl() {
  if(Controller.ButtonR1.pressing()==1) {
    arm.spin(directionType::fwd, 100, vex::velocityUnits::pct);
    arm1.spin(directionType::rev, 100, vex::velocityUnits::pct);
  }
  else if(Controller.ButtonR2.pressing()==1) {
    arm.spin(directionType::rev, 100, vex::velocityUnits::pct);
    arm1.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  }
  else {
    arm.stop(brakeType::brake);
    arm1.stop(brakeType::brake);
  }/*
  if(Controller.Axis3.value()==0){
    arm.stop(brakeType::brake);
    arm1.stop(brakeType::brake);
  }
  else{
    arm.spin(directionType::fwd,Controller.Axis3.value(),velocityUnits::pct);
    arm1.spin(directionType::fwd,-Controller.Axis3.value(),velocityUnits::pct);
  }*/
}
void armCtrl_slow() {
  if(Controller.Axis3.value()!=0) {
    arm.spin(directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
    arm1.spin(directionType::rev, Controller.Axis3.value(), vex::velocityUnits::pct);
  }
  else {
    arm.stop(brakeType::hold);
    arm1.stop(brakeType::hold);
  }
}
void armup(){
  arm.resetRotation();
  while(arm.rotation(rotationUnits::deg)<40){
    arm.spin(directionType::fwd,40,velocityUnits::pct);
    arm1.spin(directionType::rev,40,velocityUnits::pct);
  }
  arm.stop(brakeType::brake);
  arm1.stop(brakeType::brake);
  arm.resetRotation();
}
void arm_clawCtrl_auto() {
  if(Controller.ButtonA.pressing()==1) {
    claw.resetRotation();
    while(claw.rotation(rotationUnits::deg)<100) {
      claw.spin(directionType::fwd,100,vex::velocityUnits::pct);
      claw1.spin(directionType::fwd,100,vex::velocityUnits::pct);
      if(Controller.ButtonB.pressing()==1) {
        break;
      }
    }
    claw.stop(brakeType::hold);
    claw1.stop(brakeType::hold);
    arm.resetRotation();
    while(arm.rotation(rotationUnits::deg)>-100) {
      arm.spin(directionType::rev,100,vex::velocityUnits::pct);
      arm1.spin(directionType::fwd,100,vex::velocityUnits::pct);
      if(Controller.ButtonB.pressing()==1) {
        break;
      }
    }
    arm.resetRotation();
    claw.resetRotation();
    arm.stop(brakeType::brake);
    arm1.stop(brakeType::brake);
  }
}
void clawCtrl() {
  if(Controller.ButtonL2.pressing()==1) {
    claw.spin(directionType::fwd, -100, vex::velocityUnits::pct);
    claw1.spin(directionType::fwd, -100, vex::velocityUnits::pct);
  }
  else if(Controller.ButtonL1.pressing()==1) {
    claw.spin(directionType::rev,-100, vex::velocityUnits::pct);
    claw1.spin(directionType::rev, -100, vex::velocityUnits::pct);
  }
  else {
    //claw.setMaxTorque(2.1, torqueUnits::Nm);
    //claw1.setMaxTorque(2.1, torqueUnits::Nm);
    claw.stop(brakeType::hold);
    claw1.stop(brakeType::hold);
  }
}
int left;
int right;
bool left_Ctrl;
int a1;
int a2;
int highTower=680;
int mediumTower=450;
int lowTower=320;
bool lock_;
bool slow;

int main() {
  arm.resetRotation();
  Controller.Screen.clearLine(0);
  while(true) {
    arm.setMaxTorque(100,percentUnits::pct);
    arm1.setMaxTorque(100,percentUnits::pct);
    a1=Controller.Axis1.value();
    a2=Controller.Axis2.value();
    left=a2+a1;
    right=a2-a1;
    slow=Controller.ButtonUp.pressing()==1||Controller.ButtonDown.pressing()==1||Controller.ButtonLeft.pressing()==1||Controller.ButtonRight.pressing()==1;
    if(a1!=0||a2!=0) {
      if(slow==true) {
        go(left/5.5,right/5.5);
      }
      else {
        go(left,right);
     }
    }
    else {
      stopb();
    }
    if(slow==true) {
      armCtrl();
    }
    else {
      armCtrl_slow();
    }
    clawCtrl();
    arm_clawCtrl_auto();
    if(Controller.ButtonX.pressing()==1){
      armup();
    }
    if(Controller.ButtonY.pressing()==1) {
      claw.resetRotation();
    }
  }

}
