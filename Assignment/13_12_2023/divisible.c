#include <stdio.h>

int isDivisibleBy2(int num) {
    return num % 2 == 0;
}

int isDivisibleBy3(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum % 3 == 0;
}

int isDivisibleBy6(int num) {
    return isDivisibleBy2(num) && isDivisibleBy3(num);
}

int main() {
    long long int inputNumber;

   
    printf("Enter a large number: ");
    scanf("%lld", &inputNumber);

    
    if (isDivisibleBy6(inputNumber)) {
        printf("%lld is divisible by 6.\n", inputNumber);
    } else {
        printf("%lld is not divisible by 6.\n", inputNumber);
    }

    return 0;
}
