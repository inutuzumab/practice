#include <stdio.h>
#define SIZE 10

int main(void) {
		int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		for (int i = 0; i < SIZE; i++) {
            // In C, we splice the values
            printf("Value: %d.\n", array[i]);
		}
}