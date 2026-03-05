#include <kipr/wombat.h>
//TICKS -- 9.125in = 1800 ticks

int frontR = 3;
int frontL = 2;
int backL = 1;
int backR = 0;
int stop = 0;
// N = North 
// E = East
//S = South 
//W = West
int midB = 2000;

int leftL = 0;
int LWhite = 300;

int rightL = 5;
int RWhite = 500;

int two_in = 701;

void timedStop(int time){
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    disable_servos();
    msleep(time);
}

void N(int speed,int time){
    timedStop(50);
    motor(frontR, speed);
    motor(frontL, speed);
    motor(backL, speed);
    motor(backR, speed);
    msleep(time);
}

void S(int speed, int time){
    timedStop(50);
    motor(frontR, -speed);
    motor(frontL, -speed);
    motor(backL, -speed);
    motor(backR, -speed);
    msleep(time);
}

void E(int speed, int time){
    timedStop(50);
    motor(frontR, -speed);
    motor(frontL, speed);
    motor(backL, -speed);
    motor(backR, speed);
    msleep(time);
}

void W(int speed, int time){
    timedStop(50);
    motor(frontR, speed);
    motor(frontL, -speed);
    motor(backL, speed);
    motor(backR, -speed);
    msleep(time);
}

void NW(int speed, int time){
    timedStop(50);
    motor(frontR, speed);
    motor(frontL, 0);
    motor(backL, speed);
    motor(backR, 0);
    msleep(time);
}

void NE(int speed, int time){
    timedStop(50);
    motor(frontR, 0);
    motor(frontL, speed );
    motor(backL, 0);
    motor(backR, speed);
    msleep(time);
}

void SE(int speed, int time){
    timedStop(50);
    motor(frontR, -speed);
    motor(frontL, 0);
    motor(backL, -speed);
    motor(backR, 0);
    msleep(time);
}

void SW(int speed, int time){
    timedStop(50);
    motor(frontR, 0);
    motor(frontL, -speed);
    motor(backL, 0);
    motor(backR, -speed);
    msleep(time);
}

void left_nt(int speed){
    motor(frontR, speed);
    motor(backR, speed);
}

void right_nt(int speed){
    motor(frontL, speed);
    motor(backL, speed);
}

void right(int speed, int time){
    timedStop(50);
    motor(frontR, -speed);
    motor(frontL, speed);
    motor(backL, speed);
    motor(backR, -speed);
    msleep(time);
}
void left(int speed, int time){
    timedStop(50);
    motor(frontR, speed);
    motor(frontL, -speed);
    motor(backL, -speed);
    motor(backR, speed);
    msleep(time);
}

//_______________________________________________________________________________________________________________________
void left_pnt(int speed){
    motor(frontR, speed);
    motor(frontL, -speed);
    motor(backL, -speed);
    motor(backR, speed);
}

void right_pnt(int speed){
    motor(frontR, -speed);
    motor(frontL, speed);
    motor(backL, speed);
    motor(backR, -speed);

} 

void E_nt(int speed){
    motor(frontR, -speed);
    motor(frontL, speed);
    motor(backL, -speed);
    motor(backR, speed);
}
void W_nt(int speed){
    motor(frontR, speed);
    motor(frontL, -speed);
    motor(backL, speed);
    motor(backR, -speed);
}

void drive_nt(int speed){
    motor(frontR, speed);
    motor(frontL, speed);
    motor(backL, speed);
    motor(backR, speed);
}
//_____________________________________________________________________________________________________________________

void claw(int degree, int time){
    enable_servos();
    set_servo_position(0,degree);
    msleep(time);
    ao();
    disable_servos();
}

void arm(int degree, int time){
    enable_servos();
    set_servo_position(2,degree);
    msleep(time);
    ao();
    disable_servos();
}
void rotate(int degree, int time){
    enable_servos();
    set_servo_position(1,degree);
    msleep(time);
    ao();
    disable_servos();
}
void slowServo(int port, int position, int speed)
{   
    int servo_position = get_servo_position(port);        

    while(servo_position != position){ 
        if(servo_position > position){
            servo_position -= 75;
        }
        if(servo_position < position){
            servo_position += 75;
        }
        set_servo_position(port,servo_position);
        msleep(speed);
    }
    set_servo_position(port,servo_position);
    msleep(80);
}

void initialization(){
    claw(450,100);
    timedStop(100);
    rotate(1500,100);
    timedStop(100);
    
    arm(300,100);
    timedStop(500);
    claw(540,100);
    timedStop(100);
    rotate(1780,100);
    shut_down_in(119);
}

//--------------------------------------------------------------------------------------------------------------------------
int main()
{     
    shut_down_in(119);
	
    timedStop(50);
    arm(1000,100);
    
    /*    //1600 = 1 rot
    cmpc(3);
     while ((gmpc(3) < 351)){
        drive_nt(50);
        if ((gmpc(3) > 351)){
            break;
        }
    } */

    while (analog(leftL) < midB){
        drive_nt(50);
        if (analog(leftL) >= midB){
            timedStop(200);
            break;
        }
    }  while (analog(leftL) > midB){
        drive_nt(50);
        if (analog(leftL) <= midB){
            timedStop(200);
            break;
        }
    }
    right(50,2500);
    N(50,1000);

    /* cmpc(3);
    while ((gmpc(3) > -900)){
        drive_nt(-50);
        if ((gmpc(3) < -900)){
            printf("ran");
            break;
        }
    }*/

    //-----use 351 for 2in centering
    while (analog(leftL) < midB){
        W_nt(50);
        if (analog(leftL) >= midB){
            break;
        }
    }
    cmpc(3);
    while ((gmpc(3) < 351)){
        left_nt(50);
        if ((gmpc(3) > 351)){
            printf("ran");
            break;
        }
    } 
    N(50,1000);
    timedStop(250);
    while ((digital(0) == 0)){
        printf("line follow started");

        if ((analog(leftL) < (midB)) && (analog(rightL) < (midB))){
            drive_nt(50);
        }
        if (analog(leftL) > (midB)){
            left_pnt(40);
        }
        if (analog(rightL) > (midB)){
            right_pnt(40);
        }
        if ((analog(leftL) > (midB)) && (analog(rightL) > (midB))){
            printf("got to mid black tape");
            break;
        }
    }
    arm(1600,100);
    timedStop(100);
    rotate(1000,100);
    timedStop(250);
    claw(1400,100);
    timedStop(100);
    rotate(0,100);

    timedStop(100);
    N(50,2000);
    timedStop(10);
    while ((digital(0) == 0)){

        if ((analog(leftL) < (midB)) && (analog(rightL) < (midB))){
            drive_nt(50);
        }
        if (analog(leftL) > (midB)){
            left_pnt(50);
        }
        if (analog(rightL) > (midB)){
            right_pnt(50);
        }
        if ((analog(leftL) > (midB)) && (analog(rightL) > (midB))){
            break;
        }    
    }

    printf("Done w/ the line following");

    while ((analog(leftL) > (midB)) && (analog(rightL) > (midB))){
        drive_nt(50);
        if ((analog(leftL) < (midB)) && (analog(rightL) < (midB))){
            break;
        }
    }
	N(30,200);
   // left(50,1900); //90
 //tick left replaces the left(50,1900); -- 90 deg turn
    cmpc(3);
     while ((gmpc(3) < 1600)){
        left_pnt(50);
        if ((gmpc(3) > 1600)){
            break;
        }
    } 
    
    N(50,600);
     while ((digital(0) == 0)){
       if (analog(leftL) < midB){
        drive_nt(-30);
        if(analog(leftL) > midB){
            break;
        }
       }
    
    if (analog(leftL) > midB){
        drive_nt(-30);
        if(analog(leftL) < midB){
            break;
        }
    }
     }
   
	//S(35,200);
    timedStop(300); //300
    arm(750,100);
    
    timedStop(500);
    claw(400,100); //550
    
    timedStop(500);
    arm(2047,100);
    
//----------------POTATO GRABBED AND UP!!!!!------------------
   
    timedStop(500);
    rotate(2047,100);
    
    /*timedStop(250);
    rotate(200,100);
    timedStop(250);
    rotate(500,100);
    timedStop(250);
    rotate(700,100);
    timedStop(250);
    rotate(900,100);
    timedStop(250);
    rotate(1100,100);
    timedStop(250);
    rotate(1300,100);
    timedStop(250);
    rotate(1500,100);
    timedStop(250);
    rotate(1700,100);
    timedStop(250);
    rotate(1900,100);
    timedStop(250);
    rotate(2047,100); */
    
  cmpc(3);
     while ((gmpc(3) > -1610)){
        E_nt(50);
        if ((gmpc(3) < -1610)){
            break;
        }
    } 
    
	timedStop(100);
    S(45,1500);
    
  
    timedStop(250);
    claw(900,100);
        
    timedStop(250);
    claw(1100,100);
    timedStop(200);
    rotate(2000,100);
    timedStop(250);
    rotate(2040,100);
    timedStop(4000);
    
//-------------------POTATO DROPPED IN FRYER!!! BOT COLLECTS FRIES IN BASIN-------------------
    N(50,800);
    while(analog(rightL) < midB){
        drive_nt(30);
        if (analog(rightL) > midB){
            break;
        }
    }
    
    while (analog(rightL) > midB){
            drive_nt(30);
        if(analog(rightL) < midB){
            break;
        }
    }
    N(40,1000);
    left(50,2500);
    N(40,1000);
    
    //waiting for Wet Nellie to drop bottles!!
    timedStop(19000);
    
     while ((digital(0) == 0)){
        printf("line follow started");

        if ((analog(leftL) < (midB)) && (analog(rightL) < (midB))){
            drive_nt(30);
        }
        if (analog(leftL) > (midB)){
            left_pnt(40);
        }
        if (analog(rightL) > (midB)){
            right_pnt(40);
        }
        if ((analog(leftL) > (midB)) && (analog(rightL) > (midB))){
            printf("got to mid black tape");
            break;
        }
    }
    N(45,800);
    timedStop(1000);
    
    right(50,1600);

   while(analog(leftL) < midB){
        right_pnt(50);
        if(analog(leftL) > midB){
            break;
        }	
    }
    timedStop(100);
    
    while(analog(leftL) > midB){
        right_pnt(50);
        if(analog(leftL) < midB){
            break;
        }	
    }
	
    timedStop(200);
    N(40,500);
    timedStop(200);
    
    rotate(0,100);
    timedStop(200);
    
    N(50,2000);
    claw(1650,100);
    timedStop(100);
    
    N(50,1000);
    arm(1160,100);
    timedStop(500);
    
    claw(390,100);
    timedStop(500);
    
    arm(1630,100);
    
    S(50,1500);
     while ((analog(leftL) < (midB)) && (analog(rightL) < (midB))){
        drive_nt(-50);
        if ((analog(leftL) > (midB)) && (analog(rightL) > (midB))){
            break;
        }
    }
    timedStop(100);
    left(50,2100);
    
    N(50,1500);
     while ((digital(0) == 0)){
        printf("line follow started");

        if ((analog(leftL) < (midB)) && (analog(rightL) < (midB))){
            drive_nt(40);
        }
        if (analog(leftL) > (midB)){
            left_pnt(30);
        }
        if (analog(rightL) > (midB)){
            right_pnt(30);
        }
   		if ((analog(leftL) > (midB)) && (analog(rightL) > (midB))){
            printf("got to starting black tape");
            break;
        }
    }
    
	timedStop(500);
    S(45,1500);
 	timedStop(500);

    
    left(35,1000);
    
   // arm(1000,100);
    timedStop(200);
    claw(1200,100);
    
    N(50,4000);

    return 0;
}
