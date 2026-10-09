#include <kipr/wombat.h>

//============
// Motors & Sensors
//============
int motorL = 2;
int motorR = 3;

//NOTE: light sensors should be SLIGHTLY tilted so the white values are >1000, but black values consistent >3000
int lightL = 0;
int lightR = 2;
int black = 2200;
int white = 1000;

int distance = 5;
//============
// Move Foward (no time)
//============
void drive_nt(int power){
    motor(motorL,power);
    motor(motorR,power);
}

//============
// Move Foward
//============
void drive(int power, int time){
    motor(motorL,power);
    motor(motorR,power);
    msleep(time);
}
//==========
// Stop Moving
//==========
void stop(int time){
    motor(motorL,0);
    motor(motorR,0);
    msleep(time);
    ao();
}

//==========
// Move Back
//==========
void back(int power, int time){
    motor(motorL, -power);
    motor(motorR, -power);
    msleep(time);
}

//==========
// Turn Left
//==========
void left(int power, int time){
    motor(motorL,-power);
    motor(motorR,power);
    msleep(time);
}

//===================
// Pivot Left Turn
//===================
void pLeft(int power, int time){
    motor(motorR,power);
    msleep(time);
}

//===========
// No Time Left
//===========
void left_nt(int power){
    motor(motorL,-power);
    motor(motorR,power);
}
//===========
// Turn Right
//===========
void right(int power, int time){
    motor(motorL,power);
    motor(motorR,-power);
    msleep(time);
}

//===========
// Pivot Right Turn
//===========
void pRight(int power, int time){
    motor(motorL,power);
    msleep(time);
}

//===========
// No Time Right
//===========
void right_nt(int power){
    motor(motorL,power);
    motor(motorR,-power);
}

//ARM PART
void arm(int degree){
    enable_servos();
    set_servo_position(3, degree);
    msleep(100);
    ao();
}

//=========
// Arm Down
//=========

void armDown(){
    enable_servos();
    set_servo_position(3,1850);
    msleep(100);
    disable_servos();
}

//=======
// Arm Up
//=======
void armUp(){
    enable_servos();
    set_servo_position(3,1290);
    msleep(100);
    disable_servos();
}

//======
// Claws
//======
void claw(int degree){
    enable_servos();
    set_servo_position(0,degree);
    msleep(100);
    ao();
}

//==========
// Claw Open
//==========
void clawOpen(){
    enable_servos();
    set_servo_position(0,0);
    msleep(100);
    disable_servos();
}
   
//===========
// Claw Close
//===========
void clawClose(){
    enable_servos();
    set_servo_position(0,1160);
    msleep(100);
    disable_servos();
}

//========================================================
// How Claw going to move in the beginning (Moving Upward)
//========================================================
void initialization(){
    armUp();
    clawClose();
    shut_down_in(119);
    
    //wait_for_light(x)
}    


int main(){         
 
    initialization();
    drive(45,2500);
    left(65,550);
    clawOpen();

    stop(200);
    
    while(digital(0) == 0){
		drive_nt(-25);
        if(digital(0) == 1){
            back(25,500);
            break;
        }}
stop(400);    
    
//====================
// First 2 Orange pom
//====================
    
    armDown(); 
    stop(200);
    drive(45,1200);
    
    
    //orange poms grabbed
  
    stop(350);
    armUp();
    drive(35,350);
    stop(350);
    
    claw(250);
    stop(200);
   // left(15,270);
    while(analog(lightL) < black){
        drive_nt(25);
        
        if (analog(lightL) >= black){
            while(analog(lightR) < black){
                left_nt(25);
                if(analog(lightR) >= black){
                    break;
                }}}}
    
    drive(50,1500); //adjust value
    armDown();
    stop(250);
    
    clawClose();
    
    //blue pom grabbed, forward drive to push poms
     cmpc(2);
    while (gmpc(2) < 600){
        drive_nt(25);
        
        if (gmpc(2) >=600){
            break;
        }}
    stop(350);
	claw(400);
    stop(350);
    armUp();
    stop(100);
    //change to sensor reverse onto tape behind bot
  while(analog(lightL) < black && analog(lightR) < black){
        drive_nt(-45);
        
        if (analog(lightL) >= black && analog(lightR) >= black){
            break;
        }}
 
    stop(400);
    
       cmpc(2);
    while (gmpc(2) <520){
        printf("works");
        drive_nt(25);
        
        if (gmpc(2) >=520){
            break;
        }}
        
    //faces orange poms for lineup
    
     cmpc(2);
    while (gmpc(2) < 1100){
        right_nt(25);
        
        if (gmpc(2) >=1100){
            break;
        }}
    stop(200);
    
    back(30,1400);
    stop(100);
    armDown();
    stop(200);
    
    //driving to poms NOW!!!
    drive(35,1500);
    claw(1010);
    drive(35,1900);
    right(25,150);
    stop(200);
    drive(35,2000); 
    
    claw(1090);
    
    drive(35,200);
    //MAJOR ORANGE POM LINEUP GRAB!!!
   
    stop(250);
    left(35,900);
    
    stop(200);
    drive(35,3200);
    
    stop(200);
    right(35,900);
    
    //stopping at black tape
    while(analog(lightL) < black && analog(lightR) < black){
        drive_nt(45);
        if (analog(lightL) >= black && analog(lightR) >= black){
            break;
        }}
            stop(250);
            
    //start first claw open
    arm(1350);
    stop(150);
    
    claw(1015);
    //POMS DROPPED BOOOOOM
    
    stop(100);
    drive(55,250);
    
    //going from black tape to white
    while(analog(lightL) >= black && analog(lightR) >= black){
        drive_nt(55);
        if (analog(lightL) < black && analog(lightR) < black){
            break;
        }}
            stop(250);
    
    //start 2nd pom drop
     while(analog(lightL) < black && analog(lightR) < black){
        drive_nt(45);
        if (analog(lightL) >= black && analog(lightR) >= black){
            break;
        }}
    
    stop(10000000);

    
    pLeft(25,450);
    drive(35,2500);
    
    stop(100);
    
    pLeft(25,250);
    drive(35,1000);
    
    stop(10000000);
    
       cmpc(3);
    while (gmpc(3) < 80){
        left_nt(25);
        
        if (gmpc(3) >=80){
            break;
        }}
    
    stop(100000);
   /* //distance sensor -- 1000(?) idk if neeeded totally yet
    while(analog(distance) != 1500){
        cmpc(3);
        left_nt(25);
        if(gmpc(3) >= 50){
            break;

        if (analog(distance) <= 2920){
            break;
            
        }}}
        */
    
    stop(250);
    
    drive(45,5000);
    stop(100000);
    
  //  drive(50,700);

  /*  //bot moves forward to push poms a bit father up
    stop(200);
    clawOpen();
    
    drive(45,1700);
    clawClose();
    stop(450);
    drive(35,950);
    stop(450);
    armUp();
    clawOpen();
    
	stop(200);
    armUp();
    stop(100);
    
    //robot drives to tape, sensors will end up on black tape
    while(analog(lightL) < black && analog(lightR) < black){
        drive_nt(55);
        
        if (analog(lightL) >= black && analog(lightR) >= black){
            break;
        }}
    stop(200);
    printf("done");

    //robot is on black tape, sensor will make bot drive until both touch white (bot passes tape to come onto white)
    while(analog(lightL) >= black && analog(lightR) >= black){
        drive_nt(55);
        
		if (analog(lightL) < white && analog(lightR) < white){
            break;
        }}        
printf("Hi");
  stop(100);
    
    
/* //PAST TAPE -- going forward until right turn to orange pom tape    
     cmpc(2);
    while (gmpc(2) < 900){
        drive_nt(25);
        
        if (gmpc(2) >=900){
            break;
        }}
    stop(100);
    
   
    //turn to face orange poms
	pRight(80,1950);
    
    //2nd square off
    back(75,2000);
	armDown();
    stop(500);
    //right(40,300);
    stop(500);
    claw(620);
    
    
        cmpc(2);
 while (gmpc(2) < 3600){
        drive_nt(45);
       // if(analog(lightR) < black){
         //   left(20,100);
        if (gmpc(2) >=3600){
            break;
        }}
//}
    stop(100);

//====================
// Second 2 Orange pom
//====================
    
   
    
    
      
    
    
    //squaring off
    //if (digital(0) == 1){
      //  drive(100, 1900);
    // }
    //reposition so bot can go to botguy
    //if (analog(0) < 2600){
        //motor(2,-50);
      //motor(3,1);
      //msleep(350);
       //}
    
    //if (analog(1) < 3900){
      // motor(2,1);
       //motor(3,-50);
        // msleep(350);
        //}
*/
    return 0;
}
//===========
//	Gameplan:
//		1. The bot going to starting with turning left, with the claw open
//		2. Push 2 orange pom into the first box
//		3. 
//===========
