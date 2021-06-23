#include <stdio.h>

int odd_ones(unsigned x) {
    unsigned shifted_half = x >> 16;
    x = x ^ shifted_half; // only remains lower 16 bits
    shifted_half = x >> 8;
    x = x ^ shifted_half; // only remains lower 8 bits
    shifted_half = x >> 4;
    x = x ^ shifted_half; // only remains lower 4 bits
    shifted_half = x >> 2;
    x = x ^ shifted_half; // only remains lower 2 bits
    shifted_half = x >> 1;
    x = x ^ shifted_half; // only remains lower 1 bits
    return x & 1;
}

int main() {
    printf("%d\n", odd_ones(0x0f4b1f09));
    return 0;
}
