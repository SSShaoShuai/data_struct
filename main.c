#include <stdio.h>


void swap(int *x, int *y) {
    int c;
    c = *x;
    *x = *y;
    *y = c;
    return;
}

int main() {
    printf("Hello, World!\n");
    int x = 1, y = 4;
    swap(&x, &y);
    int c;
    printf("交换后，x 的值： %d\n", c);
    printf("交换后，y 的值： %d\n", y);
    return 0;
}

