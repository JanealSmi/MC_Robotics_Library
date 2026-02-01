Lines of code used:
`motor(port,power);`,
`msleep(time);`

The variables (temporary place holders), port, power, and time are all integers/numbers and indicate a value the programer must replace within a code.

`motor(port,power);` allows the bot to know which wheel, connected by its wire to the numbered controller ports, to move for whatever specified power between -100 to 100

`msleep(time);` specifies how long any time dependent code above it (motors) should run, this allows things like motors and servos to run for a specific amount of time, stopping once it ends
this time variable must be converted from seconds to milliseconds in order to function properly, ex. 1 second = 1000 milliseconds

An example of a working motor code would be:
  ```
int main(0){

  motor(0,100);
  motor(3,100);
  
  msleep(5000);
return 0;
}
  ```
Here the bot will move forward on both wheels, connected to port 0 and 3 at 100 power for 5 seconds.

Try experimenting with the direction by changing the +100 to a -100
