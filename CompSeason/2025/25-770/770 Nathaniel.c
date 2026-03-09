#include <kipr/wombat.h>

void drive(int power, int time){
    motor(0,-power);
    motor(2,-power);
    msleep(time);
}

void left(int power, int time){
    motor(0,power);
    motor(2,-power);
    msleep(time);
}

void right(int power, int time){
    motor(0,-power);
    motor(2,power);
    msleep(time);
}

void arm(int degree, int time){
    enable_servos();
    set_servo_position(1, degree);
    msleep(time);
    ao();
}
void claw(int degree, int time){
    enable_servos();
    set_servo_position(3,degree);
    msleep(time);
    ao();
    //CLOSE VALUE = 360
    //OPEN VALUE = 1600
}
void cage(int degree, int time){
    enable_servos();
    set_servo_position(0,degree);
    msleep(time);
    ao();
}
void stop(int time){
    ao();
    msleep(time);
    enable_servos();
}
void initialization(){
    enable_servos();
    claw(2040,800);
    arm(0,1000);
    cage(1263,100);
}    
void moveArm(int op, int wp, int servoport, int speed)
{   
    //allows for the servo to change in any direction
    if(op > wp){
        while(op > wp){
            if(op - wp < speed){
                //just set the claw to the end position
                set_servo_position(servoport, wp);
                op = wp;
            }else{
                //increments the position
                op -= speed;  

                //sets the servo position to the incremented position
                enable_servos();
                set_servo_position(servoport, op);
                msleep(100);
                disable_servos();
            }
        }
    }else{
        while(wp > op){
             //if the position is less than one increment away from the wanted position
            if(wp - op < speed){
                //just set the claw to the end position
                enable_servos();
                set_servo_position(servoport, op); 
                msleep(100);
                disable_servos();
                op = wp;
            }else{
                
                //increments the position
                op += speed;
                //sets the servo position to the incremented position
                enable_servos();
                set_servo_position(servoport, op);
                msleep(100);
                disable_servos();
            }
        }
    }
}

//arm degree = degree<90 lower, degree>90 higher
//claw degree = degree<90 open, degree>90 close
//Calibrate wait_for_light everytime you run it [Find by clicking program -> program name]

//do not exceed 1700 on arm
       //                             -- START WITH AN ASTRONAUT ON BOT -- 
   //                       -- Make sure battery is pushed fully down in the center!! --
int main()
{
   initialization();
   wait_for_light(5);
   shut_down_in(119);
   stop(13000);
    
    
    //         -- go for botguy -- 
    //getting out of start
    arm(1750,1000);
    drive(70,5000);
    
    
    //forward for 2nd tape
    while(analog(1) < 3000){
        motor(3,-55);
        motor(1,-55);
    
    if(analog(1) >= 3000){
        break; }
    }
    
    drive(80,1100);
    
    //facing green cubes/bot guy
    left(65,1060); //1060
     stop(400);
    
    //if button keeps messing up just edit it out cz its being off
    
   // while (digital(0) == 0){
   //otor(2,-60);
   //otor(0,-60);
   //sleep(2100);
        
   //     if (digital(0) == 1){
   //         break;
   //     }}
        
    
    //line following to moon base 
    while (digital(0) == 0){
        
        
       if (analog(1) < 3500){         // left tophat --> should turn right 
        motor(0,-50);
      motor(2,1);
      msleep(350);
       }
        
         if (analog(2) < 3500){      // right tophat --> should turn left
       motor(0,1);
       motor(2,-50);
         msleep(350);
        }
        if (digital(0) == 1){
            break;
       }}
    
    stop(400);
   
 // claw open
    claw(1000,1000);
    drive(50,100);
    stop(700);
    arm(1300,1000);   //1500
    drive(50,200);
    stop(200);
    arm(1100,1000);
    stop(300);
        
    //closing claw --> grabbed botguy , 1st back --> dragging botguy to edge AND GRABS yippee
    claw(0,1000);    
    stop(300);
    arm(1500,100);
    stop(1000);
    drive(-100,1200);
    //stop(300);
   // arm(1000,100);
    stop(20000);
     
    //going for rock heap
  right(55,1020); //75,850
  drive(75,3800);
   right(20,100);
        
    //claw open
    arm(200,1000);
    stop(600);
    claw(1700,450);    
    right(40,100);
    //        --  go for FLAG RAISE --
    
    //servo(0) closed (astronaut in cage) --> 700 
    //servo(0) open (astronaut out cage) --> 1355 
    
    //backing up from rock heap
    drive(-70,400);
    right(75,1200);
    drive(55,3000);
    
  // while(analog(1) < 3000){
    //    motor(3,-70);
    //    motor(1,-70);
    
  //  if(analog(1) >= 3000){
   //    break; }
  // }    
    
    left(40,650);
    drive(55,1000);
    right(65,1250);
    drive(70,1000);
    right(65,100);
    stop(800);
    right(30,400);
    
    //literally right there might need to touch up a bit
    drive(20,1000);
    left(20,400);
    drive(40,500);
    right(20,200);
    left(20,400);
    drive(20,700);
    left(40,500);
    stop(1000);
    cage(1355,100);
    
    
       
    // moveArm(1400, 1000, 1, 50)
	
    
    

    stop(400);
    
    
     
    return 0;
}
