
/*Write a function that decides whether a number is a prime or not. A prime number is a
number that is divisible only by 1 and itself. The function prototype is int
is_prime(int n). The function returns true if n is prime and returns false otherwise.
Write another function that displays all prime numbers less than or equal to a number.
The function prototype is void display_primes(int n). The function displays
all prime numbers less than or equal to n. Note that the display_primes function
calls the helper function is_prime.*/

#include <stdio.h>
#include <stdbool.h>

int is_prime(int n) {

    int i;
    bool tf;

    for (i = 2; i <= (n / 2); i++) {
        
        if (n % i == 0) {
            tf = false;
        }
        else if (n == 0 || n == 1) {
            tf = false;
        }
        else {
        tf = true;
        }
        break;
    }
    
    return tf;
}

int display_primes(int n) {

    int base = 0, flag, i;

     while (base < n) {
      flag = 0;

      if (base <= 1) {
         base++;
         continue;
      }

      for (i = 2; i <= base / 2; ++i) {

         if (base % i == 0) {
            flag = 1;
            break;
         }
      }

      if (flag == 0)
         printf("%d ", base);

      base++;
   }

   return 0;

}

int main() {

    int number;
    printf("Enter an integer: ");
    scanf("%d", &number); 

    if (is_prime(number) == 1) {
        printf("The result is: true %d is a prime number", number);
    }
    else {
        printf("The result is: false %d is not a prime number", number);
    }

    printf("\nThe prime numbers between 0 and %d are: ", number);
    display_primes(number);

}