#include <stdio.h>

int isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0, remainder;

    
    while (num > 0) {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    
    if (originalNum == reversedNum) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    int inputNumber;

    
    printf("Enter a number: ");
    scanf("%d", &inputNumber);

    
    if (isPalindrome(inputNumber)) {
        printf("%d is a palindrome.\n", inputNumber);
    } else {
        printf("%d is not a palindrome.\n", inputNumber);
    }

    return 0;
}
