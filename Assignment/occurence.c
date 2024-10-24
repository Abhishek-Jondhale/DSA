#include <stdio.h>

int main() {
    int n, key, count = 0;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to find
    printf("Enter the element to find: ");
    scanf("%d", &key);

    // Count occurrences of the element
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            count++;
        }
    }

    // Print the result
    printf("The element %d occurs %d times in the array.\n", key, count);

    return 0;
}
