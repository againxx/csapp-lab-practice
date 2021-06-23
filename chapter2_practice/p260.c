#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned char* x_bytes = (unsigned char*)&x;
    x_bytes[i] = b;
    return x;
}

int main() {
    unsigned a = replace_byte(0x12345678, 2, 0xAB);
    unsigned b = replace_byte(0x12345678, 0, 0xAB);
    printf("%x\n", a);
    printf("%x\n", b);
    return 0;
}
