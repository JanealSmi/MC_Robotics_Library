Light Sensors often get mixed up with tophats and don't behave like normal sensors.

Usually Light Sensors are used during competition as the start for a code and require a calibration.

The code used for a light sensor is:
`wait_for_light(port);`
When the code is ran the bot will show a screen and ask for a light on value, it will save that value when pressing the button located next to the analog ports on the controller comfirming the calibration
It will then ask for a lights off value where it will save the value for when a light isn't on, this will lead the bot to wait for when it next detects the light on value which should be when the start of a round during seeding or double elimination commences.

Example Code:

    #include <stdio.h>  
    #include <kipr/wombat.h>

    int main(){
    
    wait_for_light(0);
    //Bot will only run when light value that its calibrated to is detected!
    
    motor(0,100);
    motor(3,100);
    msleep(5000);

    return 0;
    }
    
