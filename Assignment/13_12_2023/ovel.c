#include <stdio.h>
#include <string.h>

int countVowels(const char *str) {
    int count = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        // Convert each character to lowercase to handle both uppercase and lowercase vowels
        char ch = tolower(str[i]);

        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    return count;
}

int main() {
    char inputString[100];

 
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }


    int vowelCount = countVowels(inputString);

   
    printf("Number of vowels in the string: %d\n", vowelCount);

    return 0;
}
