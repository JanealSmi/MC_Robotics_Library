#include <kipr/wombat.h>
//functions

void drive(int speed, int time)
{ 
    create_connect();
    create_drive_direct(-speed, -speed);
    msleep(time);
    create_disconnect();   
}

void reverse(int speed, int time)
{
    create_connect();
    create_drive_direct(speed, speed);
    msleep(time);
    create_disconnect();
}

void turnRight(int speed, int time)
{
    create_connect();
    create_drive_direct(speed, -speed);
    msleep(time);
    create_disconnect();  
}

void turnLeft(int speed, int time)
{
    create_connect();
    create_drive_direct(-speed, speed);
    msleep(time);
    create_disconnect();
}

void arm(int degree, int time)
{
    enable_servos();
    set_servo_position(1, degree);
    msleep(time);
}

void stop(int time)
{
    create_drive_direct(0, 0);
    msleep(time);
    create_disconnect(); 
}

//the coding part --> movement
int main() {
    arm(700,1000);
    arm(1400,1000);
    drive(100,2000);
    turnLeft(100,700);
    drive(100,650);
    arm(600,1000);
    drive(-100,500);
    turnRight(100,700);
    drive(100,4000);
    turnLeft(100,700);
    return 0;
}