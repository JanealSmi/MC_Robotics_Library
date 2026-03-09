#include <kipr/wombat.h>
void initialization(){
    enable_servos();
    arm(1400,1000);
    claw(500,1000);
}
    
        
void drive(int power, int time){
    motor(1,power);
    motor(3,power);
    msleep(time);
}

void left(int power, int time){
    motor(3,power);
    motor(1,-power);
    msleep(time);
}

void right(int power, int time){
    motor(3,-power);
    motor(1,power);
    msleep(time);
}

void arm(int degree, int time){
    enable_servos();
    set_servo_position(3, degree);
    msleep(time);
    ao();
}

void claw(int degree, int time){
    enable_servos();
    set_servo_position(2, degree);
    msleep(time);
    ao();
}

//arm degree = degree<90 lower, degree>90 higher
//claw degree = degree<90 open, degree>90 close
//Calibrate wait_for_light everytime you run it [Find by clicking program -> program name]
   
int main()
{
    arm(1300,1000);
    drive(100,2350);
    left(100,300);
//knocks off lower shelf of blocks
    right(100,600);
    drive(100,1200);
    left(100,600);
    arm(1400,1000);
    //left(100,500);
//knocks off higher shelf of blocks
    
    return 0;
}
