#include <stdio.h>

int fits_bits(int x, int n) {
    int significant_bits = x >> (n - 1);
    // remain significant bits should be all zeros or ones
    return !significant_bits | !(significant_bits + 1);
}

int main() {
    printf("%d\n", fits_bits(-5, 3));
    return 0;
}
