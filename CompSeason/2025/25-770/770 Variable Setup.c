#include <kipr/wombat.h>

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
void initialization(){
    enable_servos();
    claw(400,800);
    arm(0,1000);
    cage(700,100);
    
}    
int main()
{
    //initialization();
    right(55,1020);
    return 0;
}
