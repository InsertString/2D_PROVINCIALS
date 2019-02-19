#include "main.h"

Auto_Function bbb;

void autonomous() {
  start_auto();
  resetTimer(AUTO_TIMER);
  chassis.reset_chassis_auto_vars();
  while (getTime(AUTO_TIMER) < 15000) {
    pros::delay(20);
    if (getTime(AUTO_TIMER) % 20 == 0 && bbb == INCOMPLETE)
        chassis.turn_pid.display_output();

    //bbb = chassis.PID_drive(1000, 100);
    //bbb = chassis.PID_drive(500, 100);
    //chassis.PID_drive(1000, 50);
    //chassis.PID_drive(500, 50);
    bbb = chassis.PID_turn(-900, 50);
    //chassis.PID_turn(900, 100);
    //chassis.PID_turn(1800, 50);
    //bbb = chassis.PID_turn(900, 50);
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
