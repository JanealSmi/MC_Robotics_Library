#include <kipr/wombat.h>


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
        motor(frontR, speed);
        motor(frontL, speed);
        motor(backL, speed);
        motor(backR, speed);
        msleep(time);
    timedStop(250);
    }
    
    void S(int speed, int time){
        motor(frontR, -speed);
        motor(frontL, -speed);
        motor(backL, -speed);
        motor(backR, -speed);
        msleep(time);
        timedStop(250);
    }
    
    void E(int speed, int time){
        motor(frontR, -speed);
        motor(frontL, speed);
        motor(backL, -speed);
        motor(backR, speed);
        msleep(time);
        timedStop(250);
    }
    
    void W(int speed, int time){
        motor(frontR, speed);
        motor(frontL, -speed);
        motor(backL, speed);
        motor(backR, -speed);
        msleep(time);
        timedStop(250);
    }
    
    void NW(int speed, int time){
        motor(frontR, speed);
        motor(frontL, 0);
        motor(backL, speed);
        motor(backR, 0);
        msleep(time);
        timedStop(250);
    }
    
    void NE(int speed, int time){
        motor(frontR, 0);
        motor(frontL, speed );
        motor(backL, 0);
        motor(backR, speed);
        msleep(time);
        timedStop(250);
    }
    
    void SE(int speed, int time){
        motor(frontR, -speed);
        motor(frontL, 0);
        motor(backL, -speed);
        motor(backR, 0);
        msleep(time);
        timedStop(250);
    }
    
    void SW(int speed, int time){
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
    motor(frontR, -speed);
    motor(frontL, speed);
    motor(backL, speed);
    motor(backR, -speed);
    msleep(time);
    timedStop(250);
    }
void left(int speed, int time){
    motor(frontR, speed);
    motor(frontL, -speed);
    motor(backL, -speed);
    motor(backR, speed);
    msleep(time);
    timedStop(250);
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
    set_servo_position(3,degree);
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
 rotate(142,100);
    arm(0,100);
    claw(1330,100);
}

//--------------------------------------------------------------------------------------------------------------------------
int main()
{ 
    initialization();
    timedStop(500);
    arm(500,100);
 //   claw(750,100);
    
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
         timedStop(1000);
         break;
     }
    }  while (analog(leftL) > midB){
     drive_nt(50);
     if (analog(leftL) <= midB){
         timedStop(1000);
         break;
     }
    }

    right(50,3000);
    N(50,1500);

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
 /*   }
        cmpc(3);
    while ((gmpc(3) < 351)){
        left_nt(50);
        if ((gmpc(3) > 351)){
            printf("ran");
            break;
        }
    } */
    //N(50,1000);
   timedStop(500);
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
       claw(1350,100);
         timedStop(100);
     //    claw(750,100);
       printf("got to mid black tape");
        break;
    }
}
   /* arm(840,100);
    timedStop(100);
    claw(1400,100);
   */
    
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
    
      
    timedStop(100);
    arm(840,100);
    timedStop(100);
    claw(1400,100);
    timedStop(100);
         
    
    while ((analog(leftL) > (midB)) && (analog(rightL) > (midB))){
        drive_nt(50);
        if ((analog(leftL) < (midB)) && (analog(rightL) < (midB))){
            break;
        }
    }
    
   NE(50,1000);
    N(50,1000); 
    timedStop(100);
    S(50,1000);
    claw(1740,100);
    timedStop(100);
   rotate(0, 100);
    left(50,2800);
    S(50,500);
    if ((rightL) < midB){
        right_pnt(50);
    }

         
    // arm(900,100); //540,690
   
   /*     while ((analog(leftL) > (midB)) && (analog(rightL) > (midB))){
        drive_nt(-50);
        if ((analog(leftL) < (midB)) && (analog(rightL) < (midB))){
            break;
        }
    } */
  //  arm(500,100);
    timedStop(100);
    claw(600,100);
    timedStop(100);
    
         S(50,875); //875
    timedStop(100);
    arm(2047,100);
    timedStop(100);
    
         
         
         
        //----------------------POTATO GRABBED!!!----------------------

 /*    
        while ((analog(leftL) < (midB)) && (analog(rightL) < (midB))){
        drive_nt(50);
        if ((analog(leftL) > (midB)) && (analog(rightL) > (midB))){
            break;
        }
    } 
    //N(50,900);
    timedStop(100);
   // S(50,800);
    
    //backup after potato grab
        cmpc(3);
    while ((gmpc(3) < -690)){
        drive_nt(-50);
        if ((gmpc(3) > -690)){
            printf("back up complete, start potato drop");
            break;
        }
    } 
    S(50,875); //875
    timedStop(100);
    arm(2047,100);
    timedStop(100);
    
     	//left(45,5000);
    
    while(analog(leftL) < midB){
        left_pnt(50);
        if (analog(leftL) > midB){
            break;
        }
            }
    
     while(analog(leftL) > midB){
        left_pnt(50);
        if (analog(leftL) < midB){
            break;
        }
            }
    
     while(analog(leftL) < midB){
        drive_nt(15);
        if (analog(leftL) > midB){
            break;
        }
            }
    S(30,900);
       while(analog(leftL) > midB){
        left_pnt(30);
        if (analog(rightL) > midB){
            break;
        }
            } 
    
 	//left(45,5000);
	left(30,2000);
    timedStop(100);
    N(50,875);
    timedStop(500);
    
	claw(1400,100);
    timedStop(500);
//------------------POTATO IN FRYER!!!------------------
    claw(600,100);
   timedStop(100);
    right(50,2000);
    timedStop(100);
    arm(1500,100);
    left(50,2000);
//------------------GO FOR BOTGUY-----------------------
    timedStop(100);
    while(analog(leftL) < midB){
        drive_nt(-50);
        if(analog(leftL) > midB){
            break;
        }
    }
    right(50,2500);
    N(50,2000);
    
     while ((digital(0) == 0)){
        printf("2nd line follow started");
    
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
digital    
    
    
 */   
    
    return 0;
}}
