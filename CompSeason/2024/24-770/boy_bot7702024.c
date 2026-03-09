#include <kipr/wombat.h>

void drive(int speed, int time)
{ 
    //create_connect();
    create_drive_direct(-speed, -speed);
    msleep(time);
    //create_disconnect();   
}

void reverse(int speed, int time)
{
    //create_connect();
    create_drive_direct(speed, speed);
    msleep(time);
    //create_disconnect();
}

void turnRight(int speed, int time)
{
    //create_connect();
    create_drive_direct(speed, -speed);
    msleep(time);
    //create_disconnect();  
}

void turnLeft(int speed, int time)
{
    //create_connect();
    create_drive_direct(-speed, speed);
    msleep(time);
    //create_disconnect();
}

void servomove(int port, int pos)
{
    enable_servos();
    set_servo_position(port, pos);
    msleep(1500);
}

//remove the slashes in line 46
int main() {

    drive(750, 1000);
    
    return 0;
}
