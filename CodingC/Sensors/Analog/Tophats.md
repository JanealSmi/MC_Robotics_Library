Tophats in robotics are resposible for reading the gradient of an object, essentially looking at how light or dark something is and assigning a number range to it. This is helpful for things like distinguishing between white or black on the board, for things like line following. 

Tophats are often used in while or if loops to create a condition for the bot to look for or follow when it is met.

The code we can use when writing a tophat is: `if/while (analog(port) >=< value){ code goes here } `

Depending on the loop or task we are performing you can use an if statement (seperate or within a while) or a while loop with analogs.

For example if making a line follower you can specify what value to turn or go straight on, controlling the direction of the bot based on the gradient its detecting:

    #include <stdio.h>  
    #include <kipr/wombat.h>
    //ASSUME THERE IS A DRIVE FUNCTION HERE THAT DOESNT REQUIRE TIME
    
    // white < 1000
    //black > 1000
    
    int main(){
    while (analog(0) > 1000){
    drive(100); //No time bc its a while loop only power

    if (analog(0) <  1000){
    left(
    


