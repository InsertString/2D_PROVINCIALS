#include "main.h"
#include "robot_includes/robot_includes.h"




int auto_step;

Auto_Function i;
Auto_Function f;
Auto_Function c;




void start_auto() {
  reset_auto_variables();
  auto_step = 0;
}




void reset_auto_variables() {
  chassis.reset_chassis_auto_vars();
  ball_system.shoot_step = 0;
  resetTimer(AUTO_STEP_TIMEOUT);
}





void advance_auto_step() {
  auto_step++;
  reset_auto_variables();
  resetTimer(AUTO_STEP_TIMEOUT);
  i = f = c = INCOMPLETE;
}
























int placeholderaaaaa = 0;


void flag_auto(int colour) {
  switch (auto_step) {
    case 0 :
      if (colour == BLUE) {
        i = chassis.PID_drive(1150, 100);
      }
      else if (colour == RED) {
        i = chassis.PID_drive(1200, 100);
      }

      ball_system.setIntakePower(127);

      cBar.move_absolute(800, 200);

      if (i == COMPLETE) {
        //cBar = 0;
        //cBar.tare_position();
        advance_auto_step();
      }
    break;
    case 1 :
      flipper.move_absolute(-300, 100);
      cBar.move_absolute(0, 200);
      if (flipper.get_position() < -270) {
        i = chassis.PID_drive(-310, 100);
        if (i == COMPLETE && cBar_limit.get_value() == true) {
          advance_auto_step();
        }
      }
    break;
    case 2 :
      i = chassis.PID_drive(200, 100);
      cBar.move_absolute(550, 200);
      if (i == COMPLETE && cBar.get_position() > 500) {
        advance_auto_step();
      }
    break;
    case 3 :
      if (colour == RED) {
        i = chassis.PID_drive(-1200, 100);
      }
      else if (colour == BLUE) {
        i = chassis.PID_drive(-1210, 100);
      }

      if (i == COMPLETE) {
        advance_auto_step();
      }
    break;
    case 4 :
      if (colour == RED) {
        i = chassis.PID_turn(600, 100);
      }
      else if (colour == BLUE) {
        i = chassis.PID_turn(-640, 100);
      }

      //i = chassis.PID_turn(640, 100);
      if (i == COMPLETE) {
        advance_auto_step();
      }
    break;
    case 5 :
      i = chassis.PID_drive(-100, 100);
      if (i == COMPLETE && getTime(AUTO_STEP_TIMEOUT) > 700) {
        advance_auto_step();
      }
    break;
    case 6 :
      i = ball_system.shoot();
      if (i == COMPLETE) {
        advance_auto_step();
      }
    break;
    case 7 :
      i = chassis.PID_drive(-2250, 100);
      flipper.move_absolute(0, 100);
      if (i == COMPLETE && flipper.get_position() > -10) {
        advance_auto_step();
      }
    break;
    case 8 :
      if (colour == RED) {
        i = chassis.PID_turn(-550, 100);
      }
      else if (colour == BLUE) {
        i = chassis.PID_turn(550, 100);
      }

      //i = chassis.PID_turn(-550, 100);
      if (i == COMPLETE) {
        advance_auto_step();
      }
    break;
    case  9 :
      i = chassis.PID_drive(570, 100);

      if (chassis.right_pos() > 500)
        flipper.move_absolute(-380, 100);

      if (i == COMPLETE && flipper.get_position() < -300) {
        advance_auto_step();
      }
    break;
    case 10 :
      i = chassis.PID_drive(-600, 100);
      if (i == COMPLETE) {
        advance_auto_step();
      }
    break;
    case 11 :
      i = chassis.PID_drive(700, 100);

      if (chassis.right_pos() > 600)
        flipper.move_absolute(0, 100);

      if (i == COMPLETE && flipper.get_position() > -10) {
        advance_auto_step();
      }
    break;
    case 12 :
      if (colour == RED) {
        i = chassis.PID_turn(-510, 100);
      }
      else if (colour == BLUE) {
        i = chassis.PID_turn(510, 100);
      }

      //i = chassis.PID_turn(-510, 100);
      if (i == COMPLETE) {
        advance_auto_step();
      }
    break;
    case 13 :
      i = chassis.PID_drive(2550, 100);
      if (i == COMPLETE) {
        advance_auto_step();
      }
    break;
    case 14 :
      if (colour == RED) {
        i = chassis.PID_turn(1240, 100);
      }
      else if (colour == BLUE) {
        i = chassis.PID_turn(-1240, 100);
      }

      //i = chassis.PID_turn(1250, 100);
      if (i == COMPLETE || getTime(AUTO_STEP_TIMEOUT) > 800) {
        advance_auto_step();
      }
    break;
    case 15 :
      //i = chassis.PID_drive(-200, 100);
      //if (i == COMPLETE) {
        advance_auto_step();
      //}
    break;
    case 16 :
      if (colour == RED) {
        i = chassis.PID_turn(-130, 100);
      }
      else if (colour == BLUE) {
        i = chassis.PID_turn(130, 100);
      }

      //i = chassis.PID_turn(-130, 100);
      if (i == COMPLETE || getTime(AUTO_STEP_TIMEOUT) > 400) {
        ball_system.setIntakePower(0);
        advance_auto_step();
      }
    break;
    case 17 :
      i = chassis.PID_drive(1600, 100);
      if (i == COMPLETE) {
        advance_auto_step();
      }
    break;
    case 18 :
      i = chassis.PID_drive(700, 50);

      if (chassis.right_pos() > 300) ball_system.setIntakePower(127);

      if (i == COMPLETE) {
        //ball_system.setIntakePower(127);
        advance_auto_step();
      }
    break;
    case 19 :
      if (getTime(AUTO_TIMER) > 14000)
        chassis.PID_drive(-300, 100);

      if (getTime(AUTO_TIMER) > 14700) {
        i = ball_system.shoot();
        if (cat_pot.get_value() < 1000) {
          ball_system.setIntakePower(-20);
        }
      }
    break;
  }
}




































int plllllll = 0;


void park_auto(int colour) {
  switch (auto_step) {
    case 0 :
    ball_system.setIntakePower(127);

    cBar.move_absolute(800, 200);

    if (cBar.get_position() > 790) {
      //cBar = 0;
      //cBar.tare_position();
      advance_auto_step();
    }
    break;
    case 1 :
    i = chassis.PID_drive(-2700, 100);
    cBar.move_absolute(0, 200);
    if (i == COMPLETE && cBar_limit.get_value() == true) {
      advance_auto_step();
    }
    break;
    case 2 :
    cBar.move_absolute(550, 100);
    if (cBar.get_position() > 540) {
      i = chassis.PID_drive(1500, 70);
    }

    if (i == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 3 :
    if (colour == RED) {
      i = chassis.PID_turn(-250, 70);
    }
    else if (colour == BLUE) {
      i = chassis.PID_turn(300, 70);
    }

    if (i == COMPLETE) {
      ball_system.setIntakePower(0);
      advance_auto_step();
    }
    break;
    case 4 :
    i = chassis.PID_drive(1500, 50);
    if (i == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 5 :
    if (cBar.get_position() < 1750 && plllllll == 0) {
      cBar = 127;
    }
    else {
      plllllll = 1;
      if (cBar_limit.get_value() == false) {
        cBar = -127;
      }
      else {
        cBar.tare_position();
        cBar = 0;
        advance_auto_step();
      }
    }
    break;
    case 6 :
    i = chassis.PID_drive(-2000, 100);
    if (i == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 7 :
    if (colour == RED) {
      i = chassis.PID_turn(-450, 100);
    }
    else if (colour == BLUE) {
      i = chassis.PID_turn(450, 100);
    }
    if ( i == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 8 :
    i = chassis.PID_drive(-500, 100);
    if (i == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 9 :
    if (colour == RED) {
      i = chassis.PID_turn(450, 100);
    }
    else if (colour == BLUE) {
      i = chassis.PID_turn(-450, 100);
    }
    if (i == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 10 :
    i = chassis.PID_drive(-600, 100);
    if (i == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 11 :
    i = chassis.PID_drive(300, 100);
    if (i == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 12 :
    cBar.move_absolute(550, 200);
    if (colour == RED) {
      i = chassis.PID_turn(-900, 100);
    }
    else if (colour == BLUE) {
      i = chassis.PID_turn(900, 100);
    }
    if (i == COMPLETE && cBar.get_position() > 540) {
      advance_auto_step();
    }
    break;
    case 13 :
    i = chassis.PID_drive(-2000, 100);
    break;
  }
}























int fhfhfh = 0;

void skills_auto() {
  switch (auto_step) {
    case 0 :
    i = chassis.PID_drive(3000, 100);
    ball_system.setIntakePower(127);
    flipper.move_absolute(-250, 200);

    cBar.move_absolute(800, 200);

    if (cBar.get_position() > 790 && i == COMPLETE) {
      //cBar = 0;
      //cBar.tare_position();
      advance_auto_step();
    }
    break;
    case 1 :
    i = chassis.PID_drive(-3700, 100);
    if (i == COMPLETE && cBar_limit.get_value() == true) {
      advance_auto_step();
    }
    break;
    case 2 :
    cBar.move_absolute(550, 200);

    int delta_position;
    int past_position;

    delta_position = chassis.right_pos() - past_position;

    chassis.setLeftPower(-10);
    chassis.setRightPower(-10);

    past_position = chassis.right_pos();

    if (delta_position == 0 || getTime(AUTO_STEP_TIMEOUT) > 2000) {
      chassis.setLeftPower(0);
      chassis.setRightPower(0);
      chassis.reset_drive_sensors(true);
      advance_auto_step();
    }
    break;
    case 3 :
    i = chassis.PID_drive(800, 100);
    if (i == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 4 :
    if (cBar_limit.get_value() == false) {
      cBar = -127;
    }
    else {
      cBar.tare_position();
      cBar = 0;
      advance_auto_step();
    }
    if (getTime(AUTO_STEP_TIMEOUT) > 200) {
      i = chassis.PID_turn(950, 100);
      if (i == COMPLETE) {
        advance_auto_step();
      }
    }
    break;
    case 5 :
    cBar.move_absolute(550, 200);
    i = chassis.PID_drive(-3900, 100);
    if (i == COMPLETE) {
      f = ball_system.shoot();
      if (f == COMPLETE) {
        advance_auto_step();
      }
    }
    break;
  }
}
