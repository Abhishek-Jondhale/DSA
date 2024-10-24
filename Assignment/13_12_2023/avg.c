#include <stdio.h>

int main() {
   
    int elements[] = {5, 8, 12, 3, 7};
    int size = sizeof(elements) / sizeof(elements[0]);

    
    int sum = 0;
    float average;

 
    for (int i = 0; i < size; ++i) {
        sum += elements[i];
    }

   
    if (size > 0) {
        average = (float)sum / size;
        printf("Average of elements: %.2f\n", average);
    } else {
        printf("Array is empty, cannot calculate average.\n");
    }

    return 0;
}
