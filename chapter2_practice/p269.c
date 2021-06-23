#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
    int int_size = sizeof(int) << 3;
    int keep_mask = 1 << (int_size - n - 1);
    keep_mask = ~(keep_mask - 1) << 1;
    unsigned rotated_part = x & keep_mask;
    rotated_part >>= int_size - n;
    return x << n | rotated_part;
}

int main() {
    printf("0x%x\n", rotate_left(0x12345678, 4));
    printf("0x%x\n", rotate_left(0x12345678, 20));
    printf("0x%x\n", rotate_left(0x12345678, 0));
    return 0;
}
