#include <stdio.h>


long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; 
    } else {
        return n * factorial(n - 1); 
    }
}

int main() {
    int num;

   
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

   
    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; 
    }

   
    printf("Factorial of %d: %lld\n", num, factorial(num));

    return 0;
}
