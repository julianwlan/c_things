#include <stdio.h>

int factorial(int x) {
    if(x == 1) {
        return x;
    } else {
        return x * factorial(x - 1);
    }
}

int main() {
    printf("%d\n", factorial(5));
    
    return 0;

}