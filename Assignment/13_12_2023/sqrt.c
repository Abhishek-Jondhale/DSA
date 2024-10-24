#include <stdio.h>
#include <math.h>

int isPerfectSquare(int num) {
    int root = sqrt(num);
    return (root * root == num);
}

int main() {
    int inputNumber;

  
    printf("Enter a number: ");
    scanf("%d", &inputNumber);

    
    if (isPerfectSquare(inputNumber)) {
        printf("%d is a perfect square.\n", inputNumber);
    } else {
        printf("%d is not a perfect square.\n", inputNumber);
    }

    return 0;
}
