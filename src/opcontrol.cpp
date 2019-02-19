#include "main.h"

void opcontrol() {

	while (true) {
		printf("HELLLO %5d\n", pros::millis());
		if (!master.get_digital(DIGITAL_LEFT)) {
			chassis.drive();
			lift.drive();
			ball_system.drive();
		}
		else {
			flipper = 0;
			cBar = 0;
			gyro.reset();
		}

		if (master.get_digital(DIGITAL_UP)) {
			autonomous();
		}



		lcd_control();

		pros::delay(20);
	}
}
