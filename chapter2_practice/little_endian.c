#include <stdio.h>

int is_little_endian() {
    int i = 1;
    unsigned char* c = (unsigned char*)&i;
    return *c == 1;
}

int main() {
    if (is_little_endian()) {
        printf("Little endian machine\n");
    } else {
        printf("Big endian machine\n");
    }
    return 0;
}
