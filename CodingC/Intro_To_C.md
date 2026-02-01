Most if not all code is read the same way by an IDE (the place you code) 
The order in which you write it is the order it will read it

This means code must be written chronologically or in the order you wish the actions to take place

When first opening the IDE you will find 
```
    #include <stdio.h>  
    #include <kipr/wombat.h>
    
    int main(){
    
    return 0;
    }

```
Here the code shows the #includes which a allow the code to access the kipr library

Do not delete these, they are required for any code to function!

From the ``int main(){ ``down to the ``return 0; }`` is where any active code being done by the robot should go, anything written outside of these lines will not be read or acted by the robot.

Commenting allows a programmer to leave notes, reminders or most importantly explanations as to what a code does. A coder who doesn't comment can get lost or when allowing someone else to look at a code the function or actions being done may not be clear to read. You can use `//` to comment out a line or `/*` to comment out multiple, closing this with `*/` when at the end of the comment.

Anything written in a comment will not be read by the program, making it a helpful way to test code as well without having to delete sections and rewrite them in order to test code.

Comments can go anywhere within the IDE
