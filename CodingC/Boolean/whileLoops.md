Loops create a condition that the code reads for, if the condition is true the bot will continue to do the code under it, if not the bot will either not perform the action or stop doing so unless a `break;` line is added to get out of the loop. For example you could make the while loop wait for a botton to be pressed before doing an action, and while the button is pressed the action will loop until it is unpressed.

The code we can use in a while loop is:

    while("sensor(port)/codeCondition){}
    if ("sensor(port)/codeCondition){}

We can also use true (`1`) or false (`0`) or inequality values such as `< > = ` or combinations to make `<= >=` to specify a value we want the bot to go on.

When writing something like a button being pressed we must first define which sensor port and value we want, and because buttons are digital they only operate on a true or false.

    #include <stdio.h>  
	  #include <kipr/wombat.h>

    int main(){
      while (digital(0) == 0){ <-- the boolean must be doubled if it's equal
        motor(0,100);
        msleep(1000);
      }

      return 0;
    }

Here the bot will turn when the button connected to port 0 isn't pressed, however to get the bot out of this loop/ to stop we can add an `if` statment to `break;` the loop:

    #include <stdio.h>  
	  #include <kipr/wombat.h>

    int main(){
      while (digital(0) == 0){
        motor(0,100);
        msleep(1000);

        if (digital(0) == 1){
          break; <-- stops the loop and run any code after the while
      }
    } <-- remember to close the while statement or else the code won't compile

      return 0;
    } 

When doing inequalities we can use a similar format using a range we set, here I'll be using an ET/Distance sensor as it is an `analog` sensor:

    #include <stdio.h>  
	  #include <kipr/wombat.h>
    // to set a variable we could write, white == 3000; remembering that the inequality should point towards it to signify white however for the example we are going to use a made up value
    int main(){
      while (analog(0) <= 3000){  //<-- for this example any value < 3000 is white, we can also set a variable outside of the int main() as the border to make reading easier
        motor(0,100);
        msleep(1000);

        if (analog(0) >= 3000){
          break; <-- stops the loop and run any code after the while
      }
    } <-- remember to close the while statement or else the code won't compile

      return 0;
    } 

	


