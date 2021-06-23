#include <stdio.h>
#include <math.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer pointer, size_t length) {
    printf("0x");
    for (size_t i = 0; i < length; ++i) {
        printf(" %.2x", pointer[i]);
    }
    printf("\n");
}

void show_short(short s) {
    show_bytes((byte_pointer)&s, sizeof(short));
}

void show_long(long l) {
    show_bytes((byte_pointer)&l, sizeof(long));
}

void show_double(double d) {
    show_bytes((byte_pointer)&d, sizeof(double));
}

int main(void) {
    int i = 1;
    float f = 12.34;
    show_bytes((byte_pointer)&i, sizeof(int));
    show_bytes((byte_pointer)&f, sizeof(float));
    show_short(-1);
    show_long(-3);
    show_double(sqrtf(2));
    return 0;
}
