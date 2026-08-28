#include <stdio.h>

#define LENGTH 5

char plus100(char c) {
    return (char)(c + 100);
}

void displayArray(int array[LENGTH]) {
    for(int i = 0; i < LENGTH; i++) {
        // printf("%d\n", array[i]);
        printf("%d\n", *(array + i));
    }
}

void compareMemAdd(int array[LENGTH]) {
    printf("%p\n", array);
    printf("%p\n", &array[0]);
}

int main() {
    int myAge = 16;
    int* agePtr = &myAge;
    char myChar = 'j';
    int myArray[LENGTH];
    int* myP = &myArray;

    printf("%p\n", myP++);


    // for(int i = 0; i < LENGTH; i++) {
    //     myArray[i] = i + 1;
    // }

    // displayArray(myArray);
    // compareMemAdd(myArray);

    // printf("The array: %d\n", *(myArray + 2));

    // printf("Pointer in printf: \t %p\nPointer from variable:\t %p\nMy char: \t %c\nMy char + 100: \t %c\n",
    //     &myAge, agePtr, myChar, plus100(myChar)
    // );

    // printf("%zu\n", sizeof(myArray));

    return 0;
}

