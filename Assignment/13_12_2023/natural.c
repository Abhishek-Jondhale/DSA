#include <stdio.h>

int main() {
    int n, sum = 0;

    
    printf("Enter a positive integer (n): ");
    scanf("%d", &n);

    
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    
    sum = (n * (n + 1)) / 2;

    
    printf("Sum of the first %d natural numbers: %d\n", n, sum);

    return 0;
}
