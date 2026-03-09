#include <kipr/wombat.h>


   int frontR = 0;
    int frontL = 1;
    int backL = 2;
    int backR = 3;
    int stop = 0;
// N = North 
// E = East
//S = South 
//W = West
int leftL = 0;
int rightL = 2;
    void N(int speed,int time){
        motor(frontR, speed);
        motor(frontL, speed);
        motor(backL, speed);
        motor(backR, speed);
        msleep(time);
    }
    
    void S(int speed, int time){
        motor(frontR, -speed);
        motor(frontL, -speed);
        motor(backL, -speed);
        motor(backR, -speed);
        msleep(time);
    }
    
    void E(int speed, int time){
        motor(frontR, -speed);
        motor(frontL, speed);
        motor(backL, -speed);
        motor(backR, speed);
        msleep(time);
    }
    
    void W(int speed, int time){
        motor(frontR, speed);
        motor(frontL, -speed);
        motor(backL, speed);
        motor(backR, -speed);
        msleep(time);
    }
    
    void NW(int speed, int time){
        motor(frontR, speed);
        motor(frontL, 0);
        motor(backL, speed);
        motor(backR, 0);
        msleep(time);
    }
    
    void NE(int speed, int time){
        motor(frontR, 0);
        motor(frontL, speed );
        motor(backL, 0);
        motor(backR, speed);
        msleep(time);
    }
    
    void SE(int speed, int time){
        motor(frontR, -speed);
        motor(frontL, 0);
        motor(backL, -speed);
        motor(backR, 0);
        msleep(time);
    }
    
    void SW(int speed, int time){
        motor(frontR, 0);
        motor(frontL, -speed);
        motor(backL, 0);
        motor(backR, -speed);
        msleep(time);
    }

void forward_RW(int speed){
motor(frontR, speed);
motor(backR, speed);
}

void forward_LW(int speed){
motor(frontL, speed);
motor(backL, speed);
}

void right(int speed, int time){
    motor(frontR, -speed);
    motor(frontL, speed);
    motor(backL, speed);
    motor(backR, -speed);
    msleep(time);
    }
void left(int speed, int time){
    motor(frontR, speed);
    motor(frontL, -speed);
    motor(backL, -speed);
    motor(backR, speed);
    msleep(time);
    }

//_______________________________________________________________________________________________________________________
void right_nt(int speed){
    motor(frontR, -speed);
    motor(frontL, speed);
    motor(backL, -speed);
    motor(backR, speed);
    }
void left_nt(int speed){
    motor(frontR, speed);
    motor(frontL, -speed);
    motor(backL, speed);
    motor(backR, -speed);
    }

void forward(int speed){
        motor(frontR, speed);
        motor(frontL, speed);
        motor(backL, speed);
        motor(backR, speed);
    }
//_____________________________________________________________________________________________________________________
void timedStop(int time){
    motor(0,0);
    motor(1,0);
    motor(2,0);
    motor(3,0);
    disable_servos();
    msleep(time);
}

void claw(int degree, int time){
    enable_servos();
    set_servo_position(3,degree);
    msleep(time);
    ao();
    disable_servos();
}

void arm(int degree, int time){
    enable_servos();
    set_servo_position(1,degree);
    msleep(time);
    ao();
    disable_servos();
}
void rot(int degree, int time){
    enable_servos();
    set_servo_position(0,degree);
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

int main(){
   
    rot(1050,1000);    
    arm(1200,100);
    claw(1400,100);
    wait_for_light(4);
    shut_down_in(119);
    // \/\/ Intitialization \/\/
    camera_load_config("two");

    
    timedStop(10850);
    

    
    N(50,1000);
    while (analog(leftL) < 2000 || analog(rightL) < 2000) {
        forward_RW(50);
        forward_LW(50);
    if (analog(leftL) && analog(rightL) >= 2000){
        forward_RW(0);
        forward_LW(0);
    }       
}
    W(50,1000);
    S(50,200);
timedStop(100);
//_______________________________________^^_______________DONE________________^^______________________________________________
  camera_open();
    camera_update();
       if(get_object_count(0) > 0)
       {
           if (get_object_center_column(0,0) < 260){
               printf("Object is to the left"); //needs adjustments-- servo might be too weak
               rot(1200,1000);
               claw(1400,100);
               arm (1700,100);
               S(50,350);
               SW(50,500);
           while (analog(5) < 2100){ 
                           forward(30);
                       if (analog(5) >= 2100){
                           N(50,1000);
                               break;  
                                                    
                       }
                    		   }}

           //If the blue cup is infront (find way to make is lined up with claw)
           if (get_object_center_column(0,0) >= 260 && get_object_center_column(0,0) <= 415)
           {
    printf("Object is straight ahead");
              
               arm (1700,100);
               S(50,350);
               SW(50,500);
S(50,300);
               
// ------------ ALIGNING FOR CUP GRAB -------------------------------         
       
               while (analog(2) < 2500){
                   right_nt(30);
					
                   if (analog(2) >= 2500){
                       W(50,1100);
                       while (analog(5) < 2100){ 
                           forward(30);
                       if (analog(5) >= 2100){
                           N(50,500);
                               break;  
                                                    
                       }
                    		   }
                      break;
                   }
               }
           }

//If the object is to the right the bot straightens out on side and moves to right adjust claw infront/inline with it
           if (get_object_center_column(0,0) > 415){
  printf("Object is to the right");
               S(50,350);
               SW(50,500);

// ------------ ALIGNING FOR CUP GRAB -------------------------------         
       S(50,300);
               while (analog(0) < 3000){
                   right_nt(30);
					
                   if (analog(0) >= 3000){ 
                       W(50,500);
                       arm (1700,100);
                       N(50,2350);
                       while (analog(5) < 2100){ 
                           forward(25);
                           
                       if (analog(5) >= 2100){
                           N(50,500);
                               break;  
                                                    
                       }
                    		   }
                       break;  
                       
                   }
               }
           }   
          
                  
    //---------------------- GRABBING CUP -----------------------------------
           N(25,100);  
           claw(1050,100);      
           timedStop(100);
           arm(1900,100);
       
    // -------------------------^^ CUP HAS BEEN GRABBED!! ^^--------------------------------
           //S(50,450);
           right(50,200);
           
           while (analog(0) < 3000){
               forward(-50);
               if (analog(0) >= 3000){
                   break;
               }
           }
           S(50,1000);
    //-------------------------vv PLACE CUP IN HOLDER vv-----------------------------
           arm(600,100);
           timedStop(1000);
           rot(0,1000);
           timedStop(1000);
           arm(1200,100);
           timedStop(2000);
           claw(1400,100);
           timedStop(1000);
           arm(600,100);
           timedStop(1000);
           rot(1050,1000);
          
//--------------------------GOING TO BEV STATION
W(50,200);

           
           while (analog(0) > 3000){
           right_nt(-50);
               if (analog(0) < 3000){
                   break;
           }
           }
            while (analog(0) < 3000){
                printf("got here");
           left_nt(-50);
               if (analog(0) > 3000){
                   break;
           }
           }
//------------------------------MOVING INFORNT FO DRINKS --------------------------------
           E(50,950);
//------------------------------GETTING DRINK 1-------------------------------------------
           arm(2047,100);
           rot(856,1000);
           claw(1475,100);

           N(50,2700);
           right(50,200);
           N(50,2300);
           left(50,100);
           claw(850,100);
           S(50,1000);
 //--------------------------------------------------------------------------          
           arm(600,100);
           timedStop(1000);
           rot(0,100);
           timedStop(1000);
           arm(1100,100);
           timedStop(2000);
           claw(1400,100);
           timedStop(1000);
           arm(600,100);
           timedStop(1000);
           rot(1050,1000);
           
           //------------------------------GETTING DRINK 2-------------------------------------------
           S(50,100);
           right(50,100);
           timedStop(100);
           arm(2047,100);
           rot(856,1000);
           claw(1475,100);

            N(50,1000);
            claw(900,100);
           S(50,1000);
//------------------------------DRINK IN CUP 2------------------------------
           arm(600,100);
           timedStop(1000);
           rot(0,1000);
           timedStop(1000);
           arm(1100,100);
           timedStop(2000);
           claw(1400,100);
           timedStop(1000);
           arm(600,100);
           timedStop(1000);
           rot(1050,1000);
  /*         
//-----------------------ICE-------------------------------------
           W(50,100);
           right(50,400);
           N(50,200);
           timedStop(100);
           
           rot(1200,100);
           arm(2047,100);
           claw(1400,100);
           */
 //-----------------------------getting Drink 3-------------------------------------          
             S(50,100);
           right(50,100);
           timedStop(100);
           arm(2047,100);
           
           rot(856,1000);
           claw(1475,100);

            N(50,1000);
            claw(900,100);
           S(50,1000);
//--------------------Drink 3 in cup--------------------------
           arm(600,100);
           timedStop(1000);
           rot(0,1000);
           timedStop(1000);
           arm(1100,100);
           timedStop(2000);
           claw(1400,100);
           timedStop(1000);
           arm(600,100);
           timedStop(1000);
//----------------------------Getting drink 4-------------------------------           
           S(50,100);
           right(50,100);
           timedStop(100);
           rot(856,1000);
           arm(2047,100);
           claw(1475,100);

            N(50,1000);
            claw(900,100);
           S(50,1000);
//------------------------------DRINK IN CUP 4------------------------------
           arm(600,100);
           timedStop(1000);
           rot(0,1000);
           timedStop(1000);
           arm(1100,100);
           timedStop(2000);
           claw(1400,100);
           timedStop(1000);
           arm(600,100);
           timedStop(1000);
           rot(1050,1000);
//--------------------------------Getting drink 5------------------------
             S(50,100);
           right(50,100);
           timedStop(100);
            rot(856,1000);
           arm(2047,100);
           claw(1475,100);

            N(50,1000);
            claw(900,100);
           S(50,1000);
//------------------------------DRINK IN CUP 5------------------------------
           arm(600,100);
           timedStop(1000);
           rot(0,1000);
           timedStop(1000);
           arm(1100,100);
           timedStop(2000);
           claw(1400,100);
           timedStop(1000);
           arm(600,100);
           timedStop(1000);
           rot(1050,1000);
           
           
           
           
           
           
           while (analog(0) < 3000){
               left_nt(50);
               if  (analog(0) >= 3000){
                   ao();
               }
           }
   
    return 0;
} } 