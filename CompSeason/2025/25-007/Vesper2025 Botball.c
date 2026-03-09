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

void forward_nt(int speed){
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
    
    clear_motor_position_counter(3);
    while (get_motor_position_counter(3) < 1400){
        forward_nt(50);
    }
            ao();
    
return 0;
    }  