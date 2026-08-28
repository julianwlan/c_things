#include <stdio.h>

void initFile(char *filename) {
    FILE *fptr = fopen(filename, "w");
    if (fptr != NULL) {
        fprintf(fptr, "0\n");
        fclose(fptr);
    }
}

void updateCounter(char *filename) {
    int counter;
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        return;
    }

    if (fscanf(fptr, "%d", &counter) != 1) {
        fclose(fptr);
        return;
    }

    fclose(fptr);

    fptr = fopen(filename, "a");
    if (fptr != NULL) {
        fprintf(fptr, "%d\n", counter + 1);
        fclose(fptr);
    }
}

int main () {
    initFile("execution.log");
    updateCounter("execution.log");
    return 0;
}