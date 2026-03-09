#include <kipr/wombat.h>
//LABELS
//4/30/25
//Sensors [black/white]
int frontLeft = 4; 
int FLblack = 2800; //greater
int FLwhite = 300; //lesser

int frontRight = 3;
int FRblack = 3500; //greater
int FRwhite = 2800; //lesser

int backRight = 1;
int BRblack = 3400; //likewise
int BRwhite = 2000;

int frontRightBump = 9;
int frontRightDistance = 2;

int leftWheel = 0;
int rightWheel = 3;
int armTilt = 2;
int armFork = 3;

//Functions
void drive(int speed, int time){
        motor(leftWheel,speed);
        motor(rightWheel,speed);
        msleep(time);
    }
void reverse(int speed, int time){
        motor(leftWheel,-speed);
        motor(rightWheel,-speed);
        msleep(time);
    }
    void left(int speed, int time){
        motor(leftWheel,-speed);
        motor(rightWheel,speed);
        msleep(time);
    }
    void right(int speed, int time){
        motor(leftWheel,speed);
        motor(rightWheel,-speed);
        msleep(time);
    }

    void arm (int degree,int time){
//  !ALL DEGREES SHOULD BE LESS THAN 550!
        enable_servos();
        set_servo_position(armTilt,degree);
        msleep(time);
        disable_servos();
    }
    void hook (int degree,int time){
//  !ALL DEGREES SHOULD BE GREATER THAN 600!
        enable_servos();
        set_servo_position(armFork,degree);
        msleep(time);
        disable_servos();
    }
//_____________________________________!functions for loops!___________________________________________________________
   void drive_nt (int speed){
        motor(leftWheel,speed);
        motor(rightWheel,speed);
    }
   void reverse_nt (int speed){
        motor(leftWheel,-speed);
        motor(rightWheel,-speed);
    }
   void right_nt (int speed){
        motor(leftWheel,speed);
        motor(rightWheel,-speed);
    }
   void left_nt (int speed){
        motor(leftWheel,-speed);
        motor(rightWheel,speed);
    }
   void stopWheel (int wheel){
       motor(wheel, 0);
       msleep(50);
   }
        
//__________________________________________________________________________________________________________________________
    void initialization(){
        arm(380,100);
        hook(570,100);
     //   wait_for_light(5);
       // shut_down_in(119);
        
        
    }
    void stop(int time){
        drive(0,time);
    }

void slowServo(int port, int position, int speed)
{   
    int servo_position = get_servo_position(port);        
    
    while(servo_position != position){ 
        if(servo_position > position){
            servo_position -= 5;
        }
        if(servo_position < position){
            servo_position += 5;
        }
        set_servo_position(port, servo_position);
        msleep(speed);
        msleep(100);
    }
}
//_______________________________________/\/\__________Functions___________/\/\___________________________________________
//________________________\/\/_________________________Main Code___________________________________\/\/__________________

int main()
{    
    initialization();
   // stop(10000);
    
    arm(135, 500);
    right(65,1270);
  
    reverse(100, 700); //squares off
    drive(80,2300); //passes first black line
//mess up here------------------------------------------------------------------------------------------------------------    
    //reads for 2nd black line
    while (analog(backRight) < BRblack){ 
        drive_nt(65);
        if (analog(backRight) > BRblack){
            stop(300);
            drive(50, 1000);
            stop(100);
            break;
        }
    }
    stop(1000);
    
    //turns until right  sees black line
    while (analog(frontRight) < FRblack){ 
        left_nt(65);
        if (analog(frontRight) > FRblack){
            break;
        }}
    stop(500);
    
    //turns until right sees white 
    while (analog(frontRight) > FRblack){ 
        left_nt(45);
        if (analog(frontRight) < FRblack){
            break;
        }}
    
    while (analog(frontLeft) < FLblack){ 
        left_nt(30);
        if (analog(frontLeft) > FLblack){
            break;
        }}
    stop(150);

    while (analog(frontRight) < FRblack){
        motor(rightWheel, -20);
        if (analog(frontRight) > FRblack){
            break;
        }}
        stop(500);

    //reversing cross board starts here
    
    reverse(45, 1000);
    //until sees middle line
    while (analog(frontRight) < FRblack){
        reverse_nt(35);
        if (analog(frontRight) > FRblack){
            break;
        }}
   
    reverse(45, 1000);
    
    //until sees white
    while (analog(frontRight) > FRblack){
        reverse_nt(35);
        if (analog(frontRight) < 3000){
            break;
        }}
    reverse(45, 1500);
    
    left(45,1600);
    reverse(60,3000);
    
    
    //-----------ARM POSITIONING--------------
    arm(495,100); //450  //varies on battery, maybe also servo dying
    hook(1060,100);  //1640 , 1110
    
	while (digital(frontRightBump) == 0){
  	  right_nt(50);
  		  if (digital(frontRightBump) == 1) {
     	   break;
          }
    }
  //  left(20,720); //700 ticks? .75in. = 159 ticks
    
    cmpc(3);
    while((gmpc(3)) < 210){
        left_nt(20);
        if((gmpc(3)) > 210){
            break;
        }
    }
        
    
    while (analog(frontLeft) < FLblack){
        drive_nt(20);
        if (analog(frontLeft) > FLblack){
            printf("read black line");
            //drive(20,5500); 
            break;
        }}
    printf("hrllo");
   // stop(800);
    drive(20,5520);    
    drive(20,200);
    stop(500);
    
    //diy slow servo
    arm(440,100);
    stop(200);
    arm(400,100);
    stop(200);
    arm(350,100);
    stop(250);
    arm(300,100);
    stop(100);
    arm(250,100);
    stop(200);
    arm(200,100);
    stop(100);
    arm(150,100);
    stop(100);
    arm(100,100);
    
    hook(470, 50);
    stop(800);
 //------------BOTTLES ARE GRABBED AND UP!!!-------------------------
    
    //drives until black
    while(analog(backRight) < BRblack){
        drive_nt(35);
        if (analog(backRight) > BRblack){
            break;
        }
    }
    
    //drives until other side of tape (on white)
    while(analog(backRight) > BRblack){
        drive_nt(35);
        if (analog(backRight) < BRblack){
            break;
        }
    }
    
    //^^^^^^ back right tophat is past the mid black tape (on white) ^^^^^^
    
    
    while(analog(frontLeft) < FLblack){
        left_nt(25);
        if(analog(frontLeft) > FLblack){
            break;
        }
    }
    left(25, 150);
    stop(50);
    right(30, 120);
    stop(50);
    drive(35, 1000);
    
//^^  should end up on the white, past the mid tape ^^
    
    while(analog(backRight) < BRblack){
        drive_nt(100);
        if (analog(backRight) > BRblack){
            drive(30, 900);
            break;
        }
    }
    
    stop(500);

    while(analog(frontRight) < FLblack){
        motor(rightWheel, 45);
        if (analog(frontRight) > FRblack){
            break;
        }
    }
    //left(30, 800);
    left(30,400);
	stop(100);
    drive(50, 1500);
    stop(300);
    reverse(35,500);
    drive(45,500);

    hook(470,100);
    stop(100);
    hook(570,100);
    stop(100);
    hook(670,100);
    stop(100);
    hook(670,100);
    stop(100);
    hook(770,100);
    stop(100);
    hook(870,100);
    stop(200);
    
        
    arm(200, 100);
    stop(100);
    arm(300, 100);
    stop(100);
    arm(400, 100);
    stop(100);
    arm(500, 100);
    stop(100);
    arm(600, 100);
    stop(100);
    
    hook(960,100);
    stop(200);
    hook(1000,100);
    stop(100);
    hook(1050,100);
    stop(100);
    hook(1070,100);
    stop(100);
    hook(1100,100);
    stop(100);
    hook(1140,100);
    
    stop(100);
    
   reverse(40,2100); //<--- Changed
  /*  while(analog(frontRight) < FLblack){
        motor(rightWheel, -30);
        if (analog(frontRight) > FRblack){
            break;
        }
    } */
    arm(350,100);
    right(65,1230);
    stop(400);
    
    while((analog(frontRight) < FRblack)){
        drive_nt(60);
                if ((analog(frontRight) > FRblack)){
            break;
        }
    }
    
    
       
    hook(200, 100);
    stop(400);
    right(50,800);
    drive(100,1000);
    right(50,1000);
    drive(90, 1000);
    //right(50,800);
    //drive(100,1000);
     /* 
    reverse(60,3500);
              while((analog(frontLeft) < FLblack)){
        left_nt(50);
                if ((analog(frontLeft) > FLblack)){
            break;
        }
    }
   // left(50,850);
                    
         while((analog(frontLeft) > FLblack)){
        right_nt(50);
              if ((analog(frontLeft) < FLblack)){
            break;
        }
    }
    
    right(40,580);     
    stop(400);
    reverse(40,4500);
    // ^^ gets caught at middle from cable :'(
    stop(200);
    left(20,80);
    stop(200);
    reverse(55,4000);
    */
    return 0;
}
