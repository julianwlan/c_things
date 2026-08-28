#include <stdio.h>
#include <string.h> 

typedef struct {
    char name[25];
    char password[12];
    int id;
} User; 

int main() {
    User user1 = {"Julian", "1234", 12};
    printf("%s\n", user1.name);

}