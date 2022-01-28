
//Problem 1 from HW2 written in C

#include <stdio.h>;

double compute_pi(int n) {

    double total = 0;
    int four = 4;
    double infSum; 
    for(int i = 1; i < n; ++i) {
        if(i % 2 != 0) {
           infSum = four * (1 - (1/n) + (1/n));
        }
    
        return infSum;
    }

}

int main() {

    printf("The desired value of pi is %f", compute_pi(4));
    return 0;
}
