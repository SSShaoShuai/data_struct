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
    printf("������x ��ֵ�� %d\n", c);
    printf("������y ��ֵ�� %d\n", y);
    return 0;
}

