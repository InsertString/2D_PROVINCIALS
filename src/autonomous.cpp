#include "main.h"

void autonomous() {
  start_auto();
  resetTimer(AUTO_TIMER);
  chassis.reset_chassis_auto_vars();
  while (getTime(AUTO_TIMER) < 15000) {
    chassis.PID_drive(1000, 100);
    //chassis.PID_drive(500, 100);
    //chassis.PID_drive(1000, 50);
    //chassis.PID_drive(500, 50);
    //chassis.PID_turn(1800, 100);
    //chassis.PID_turn(900, 100);
    //chassis.PID_turn(1800, 50);
    //chassis.PID_turn(900, 50);
    /*
    switch (selected_auto) {
      case 0 :
      flag_auto(RED);
      break;
      case 1 :
      flag_auto(BLUE);
      break;
      case 2 :
      park_auto(RED);
      break;
      case 3 :
      park_auto(BLUE);
      break;
      case 4 :
      partner_auto(RED);
      break;
      case 5 :
      partner_auto(BLUE);
      break;
      case 6 :
      skills_auto();
      break;
    }
    //*/
  }
}
