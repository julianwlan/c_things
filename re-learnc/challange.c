#include <stdio.h>

int add(int x, int y);

int main() {
    int result = add(5, 3);
    printf("%d\n", result);

    return 0;
}

int add(int x, int y) {
    return x + y;
}