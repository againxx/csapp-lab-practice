#include <stdio.h>

int signed_high_prod(int x, int y) {
    long result = (long)x * (long)y;
    return result >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned x_sign = x >> 31;
    unsigned y_sign = y >> 31;
    return signed_high_prod(x, y) + x_sign * y + y_sign * x;
}

int main() {
    unsigned x = 0x3e34a678;
    unsigned y = 0xee5cba98;
    unsigned long full_result = (unsigned long)x * (unsigned long)y;
    printf("0x%.16lx\n", full_result);
    printf("0x%.8x\n", unsigned_high_prod(x, y));
    return 0;
}
