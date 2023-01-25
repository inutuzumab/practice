#include <stdio.h>
#define ARRAY_SIZE 6

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6};
    
    printf("Before reversing:\n");
    print_array(array, ARRAY_SIZE);
    
    for (int i = 0; i < ARRAY_SIZE/2; i++) {
        int temp = array[i];
        array[i] = array[ARRAY_SIZE - 1 - i];
        array[ARRAY_SIZE - 1 - i] = temp;
    }
    
    printf("After reversing:\n");
    print_array(array, ARRAY_SIZE);
}