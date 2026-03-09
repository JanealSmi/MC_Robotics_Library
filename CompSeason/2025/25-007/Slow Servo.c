#include <kipr/wombat.h>


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

//--------------------------------------------------------------------------------------------------------------------
void slowServo(int port, int position, int speed)
{   
    int servo_position = get_servo_position(port);        
    
    while(servo_position != position){ 
        if(servo_position > position){
            servo_position -= 50;
        }
        if(servo_position < position){
            servo_position += 50;
        }
        set_servo_position(port,servo_position);
        msleep(speed);
    }
    set_servo_position(port,servo_position);
    msleep(50);
}

                
int main()
{
    enable_servos();
     slowServo(2,1300,100);
     slowServo(2,0,100);
    return 0;
}
