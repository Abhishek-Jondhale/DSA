#include <stdio.h>

void printDigitsInLetters(int number) {
    
    char *words[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    
    if (number < 0) {
        printf("Negative ");
        number = -number;
    }

    
    if (number == 0) {
        printf("%s ", words[0]);
        return;
    }

    
    while (number > 0) {
        int digit = number % 10;
        printf("%s ", words[digit]);
        number /= 10;
    }
}

int main() {
    int input;

   
    printf("Enter an integer: ");
    scanf("%d", &input);

   
    printf("Digits in letters: ");
    printDigitsInLetters(input);

    return 0;
}
