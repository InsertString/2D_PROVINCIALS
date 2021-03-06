#include "main.h"
#include "robot_includes/robot_includes.h"

#define CHAINBAR 1
#define FLIPPER 2
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define NONE 0

#define SCORING -1850
#define LIFTING -4150
#define GRABBING -310

Lift_Systems::Lift_Systems() {
  curr_system = FLIPPER;
  flipper_state = DOWN;
  cBar_state = NONE;
}


void Lift_Systems::setFlipperPower(int power) {
  flipper = power;
}


void Lift_Systems::setCBarPower(int power) {
  cBar = power;
}



int Lift_Systems::button_pressed() {
  int rv = NONE;
  if (master.get_digital(DIGITAL_UP)) {
    rv = UP;
  }
  else if (master.get_digital(DIGITAL_LEFT)) {
    rv = LEFT;
  }
  else if (master.get_digital(DIGITAL_DOWN)) {
    rv = DOWN;
  }
  else if (master.get_digital(DIGITAL_RIGHT)) {
    rv = RIGHT;
  }
  return rv;
}

int step;
int cap_score_step;

void Lift_Systems::drive() {
  if (master.get_digital_new_press(DIGITAL_R2)) {
    if (flipper_state == UP) flipper_state = DOWN;
    else if (flipper_state == DOWN) flipper_state = UP;
  }

  if (flipper_state == UP) {
    flipper.move_absolute(GRABBING, 100);
  }
  else if (flipper_state == DOWN) {
    flipper.move_absolute(0, 100);
  }

  if (master.get_digital_new_press(DIGITAL_X)) {
    cBar_state = UP;
    step = 0;
  }
  else if (master.get_digital_new_press(DIGITAL_A)) {
    cBar_state = LEFT;
  }
  else if (master.get_digital_new_press(DIGITAL_Y)) {
    cBar_state = RIGHT;
  }
  else if (master.get_digital(DIGITAL_B)) {
    cBar_state = DOWN;
  }
  else if (master.get_digital(DIGITAL_RIGHT)) {
    cBar_state = 1000;
  }

  if (cBar_state == UP) {
    //cBar.move_absolute(1850, 150);
    if (cBar.get_position() < 1750 && step == 0) {
      cBar = 127;
    }
    else {
      step = 1;
      if (cBar_limit.get_value() == false) {
        cBar = -127;
      }
      else {
        if (cBar.get_position() != 0) {
          cBar.tare_position();
        }

        cBar = 0;
      }
    }
  }
  else if (cBar_state == LEFT) {
    cBar.move_absolute(550, 100);
  }
  else if (cBar_state == RIGHT) {
    if (cBar.get_position() < 1050 && cBar.get_position() > 650)
      cBar = 50;
    else if (cBar.get_position() <= 650) {
      cBar = 100;
    }
    else
      cBar = 0;
  }
  else if (cBar_state == 1000) {
    cBar.move_absolute(2630, 200);
  }
  else if (cBar_state == DOWN) {
    if (cBar_limit.get_value() == false) {
      cBar = -127;
    }
    else {
      if (cBar.get_position() != 0) {
        cBar.tare_position();
      }

      cBar = 0;
    }
  }


}
