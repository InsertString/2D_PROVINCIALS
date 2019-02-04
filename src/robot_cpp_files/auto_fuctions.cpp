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





void partner_auto(int colour) {
  switch (auto_step) {
  }
}





void flag_auto(int colour) {
  switch (auto_step) {
  }
}





void park_auto(int colour) {
  switch (auto_step) {
  }
}




void skills_auto() {
  switch (auto_step) {
  }
}
