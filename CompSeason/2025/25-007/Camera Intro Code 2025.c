#include <kipr/wombat.h>
/*\/ for 4 motion wheels \/*/ 
    int frontR = 0;
    int frontL = 1;
    int backL = 2;
    int backR = 3;
    int stop = 0;
    
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
        motor(frontL, speed);
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
void right(int speed){
    motor(frontR, -speed);
    motor(frontL, speed);
    motor(backL, -speed);
    motor(backR, speed);
    }
int main()
{
    /*
    camera_open() turns on the camera
   
    camera_update() updates/ captures and image for the camera to use to detect the object with your default 
    channel's(in channels under settings on controller) color
    
    (get_object_count(0) >=< x) tells you if there is/isn't an object or certain amount of a certain colored object 
    infront of the bot
    
    if(get_object_center_column(0,0) >=< x) x equalling the mid-point of the image(imagine a numbered x,y graph over the photo, but you only care abt x)
    
    get_object_area checks for the area of the bounding box */
//___________________________________________________________________________________________________________________
    N(100,1000);
    while (analog(0) < 2000 || analog(5) < 2000) {
        forward_RW(50);
        forward_LW(50);
    if (analog(0) && analog(5) >= 2000){
        forward_RW(0);
        forward_LW(0);
    }       
}    
//______________________________________________________________________________________________________________
    camera_open();
    camera_update();
       if(get_object_count(0) > 0)
       {
           if (get_object_center_column(0,0) > 275 && get_object_center_column(0,0) < 350)
           {
    printf("Object is straight ahead");
           }
           if (get_object_center_column(0,0) > 350){
  printf("Object is to the right");
           }
           if (get_object_center_column(0,0) < 275){
               printf("Object is to the left");
               SW(100,1000);
               camera_update(); 
              if(get_object_area(0,0) > 10000){
                printf("Greater than 10000");
              if(get_object_area(0,0) < 10000){
                  printf("less than 10000");
              }
              }
       }
    }
    return 0;
}
