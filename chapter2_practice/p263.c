#include <stdio.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    int int_size = sizeof(int) << 3;
    int mask = (1 << (int_size - k)) - 1;
    return xsra & mask;
}

unsigned sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int int_size = sizeof(int) << 3;
    int mask = ~((1 << (int_size - k - 1)) - 1);
    int add_one = 1 << (int_size - k - 1);
    return (xsrl ^ mask) + add_one;
}

int main() {
    printf("%.8x\n", srl(0x80400001, 4));
    printf("%.8x\n", sra(0x80400001, 7));
    printf("%.8x\n", sra(0x70400001, 7));
    return 0;
}
