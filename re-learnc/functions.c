#include <stdio.h>

void callName(char name[]) {
    printf("Fck you %s!\n", name);
}

float toCelsius(float fahrenheit) {
    return (5.0f / 9.0f) * (fahrenheit - 32.0f);
}

int main() {
    callName("Julian");
    printf("100 ° F is equal to %.0f ° C\n", toCelsius(100));

    return 0;
}