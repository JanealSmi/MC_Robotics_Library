#include <kipr/wombat.h>
void drive (int power, int time){
    motor(1, power);
    motor(3, power);
    msleep(time);
}
void right (int power, int time){
    motor(1,-power);
    motor(3, power);
    msleep(500);
}
void left (int power, int time){
    motor(1, power);
    motor(3,-power);
    msleep(500);
}
int main()
{ 
    camera_open();
    camera_update();
       if(get_object_count(0) > 0)
       {
           if (get_object_center_column(0,0) > 306 && get_object_center_column(0,0) < 332)
           {
    printf("Object is straight ahead");
           }
           if (get_object_center_column(0,0) > 316){
  printf("Object is to the right");
           }
           if (get_object_center_column(0,0) < 316){
  printf("Object is to the left");
           }
       }
    return 0;
}
