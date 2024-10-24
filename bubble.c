#include <stdio.h>  
 
void bubble_sort(int arr[], int n) {  
  int i, j;  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {  
      if (arr[j] > arr[j + 1]) {  
        int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
      }  
    }  
  }  
}  
int main() {  
 int n;
   
    // Step 1: Ask the user to input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
   
    // Step 2: Dynamically allocate memory for the array
    int arr[45];
    // int *arr = (int*)malloc(n * sizeof(int));
   
    // Step 3 and 4: Prompt the user to enter the elements
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
  bubble_sort(arr, n);  
  printf("Sorted array: ");  
  for (int i = 0; i < n; i++) {  
    printf("%d ", arr[i]);  
  }  
  return 0;  
}  

