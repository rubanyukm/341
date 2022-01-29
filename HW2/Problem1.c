
//Problem 1 from HW2 written in C
/* Write a function that computes the value of the mathematical constant π. The value of
π can be approximately computed using the infinite sum 4(1 - 1/3 + 1/5 - 1/7
+ 1/9 - 1/11 + 1/13 - 1/15 + . . .) The function prototype is double
compute_pi(int n). The function computes the value of π using the first n terms of
the infinite sum and returns the value. */

#include <stdio.h>
#include <math.h>

double compute_pi(int n) {

    long int i;
    double sum=0.0, term, pi;
 

    for(i = 0; i < n; i++) {
        term = pow(-1, i) / (2*i+1);
        sum += term;
    }

    pi = 4 * sum;
 
    return pi;

}


int main() {

    int computation;
    printf("Enter an integer: ");
    scanf("%d", &computation); 

    printf("\nThe desired value of pi is: %.6lf", compute_pi(computation));
    return 0;
}
