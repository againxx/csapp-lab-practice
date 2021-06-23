#include <stdio.h>
#include <limits.h>

int threefourths(int x) {
    int int_size = sizeof(int) << 3;
    int sign_bit = x >> (int_size - 1);
    int low_bit = x & 0x3;
    int bias = !(sign_bit + !low_bit);
    int fourth = (x >> 2) + bias;
    return x - fourth;
}

int main() {
    printf("%d\n", threefourths(3));
    printf("%d\n", threefourths(-3));
    printf("%d\n", threefourths(8));
    printf("%d, %d\n", threefourths(INT_MAX), INT_MAX);
    printf("%d, %d\n", threefourths(INT_MIN), INT_MIN);
    return 0;
}
