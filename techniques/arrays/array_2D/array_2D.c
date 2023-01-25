#include <stdio.h>
#define ROW 10
#define COL 10

int main(void) {
    int array[ROW][COL] = {0};
    for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                    printf("The current row is %d, and the current column is %d.\n ", i, j);
                    printf("Here, the value is: %d. \n ", array[i][j]);
            }
    }
}