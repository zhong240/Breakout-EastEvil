#include "../includes/Ball.h"
#include <iostream>
/*This file is used to test the ball, especialliy for the onCollide function and onTriggerCollide function*/

int main(int argc, char* args[]){
    Ball ballA = Ball();
    Ball ballB = Ball();
    ballA.onCollide( ballB );
    return 0;
}
