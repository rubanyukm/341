
//HW2 Problem 2 COSC-341
/*Write a function that computes the square root of a number. The square root of a
number x can be approximately computed as follows. First guess that the square root of x
is 1. Then repeatedly get the next guess from the last guess using the rule next =
0.5(last + x / last) where last is the last guess and next is the next guess.
Repeat ten times using a loop and the tenth guess will be approximately the square root.
The function prototype is double compute_sqrt(double x). The function
computes the square root of x and returns the square root.*/

#include <stdio.h>
#include <stdlib.h>

double compute_sqrt(double x) {

    int a = x;
    double sqrt;

      while (1) {
 
        sqrt = 0.5 * (a + (x / a));
 
        if (abs(sqrt - a) < 1)
            break;
 
         a = sqrt;
    }

    
    return sqrt;
}

int main() {

    printf("SQRT: %f",compute_sqrt(122));

}