#include "main.h"

void autonomous() {
  start_auto();
  resetTimer(AUTO_TIMER);
  chassis.reset_chassis_auto_vars();
  while (getTime(AUTO_TIMER) < 15000) {
    //chassis.PID_turn(900, 100);
    ///*
    switch (selected_auto) {
      case 0 :
      flag_auto(RED);
      break;
      case 1 :
      flag_auto(BLUE);
      break;
      case 2 :

      break;
      case 3 :

      break;
      case 4 :

      break;
      case 5 :

      break;
      case 6 :

      break;
    }
    //*/
  }
}
