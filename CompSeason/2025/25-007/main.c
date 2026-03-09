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
    }
void left(int speed, int time){
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
void rotate(int degree, int time){
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
int main()
{
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
       printf("got here");
        break;
    }
    
}
    timedStop(10);
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
    printf("Done");
        
        
    return 0;
}
