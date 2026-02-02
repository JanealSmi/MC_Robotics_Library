	#include <stdio.h>  
	#include <kipr/wombat.h>
	
	//Movement Functions
	void drive (int power, int time){
 	 	motor(0,power);
		motor(3,power);
 	 	msleep(time);
	}
	void right (int power, int time){
		motor(0,-power);
		motor(3,power);
 	 	msleep(time);
	}
	void left (int power, int time){
		motor(0,power);
		motor(3,-power);
 	 	msleep(time);
	}
	
	void arm (int degrees){
	  enable_servos();
		set_servo_position(0,degrees);
		msleeep(100);
		disable_servos();
	}
	void claw (int degrees);
		enable_servos();
		set_servo_position(3,degrees);
		msleep(100);
		disable_servos();
	}
	
	// Loop Functions
	void drive (int power){
	  motor(0,power);
	  motor(3,power);
	}
		void right (int power){
		motor(0,-power);
		motor(3,power);
	}
	void left (int power){
		motor(0,power);
		motor(3,-power);
	}
	
