#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int calc(int x, int y, int (*op)(int, int)) {
    return op(x, y);
}

int main() {
    printf("%d\n", calc(5, 3, subtract));
}