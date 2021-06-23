#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k) {
    int int_size = sizeof(int) << 3;
    int bias = (1 << k) - 1;
    int sign_mask = x >> (int_size - 1);
    return (x + (bias & sign_mask)) >> k;
}

int main() {
    printf("%d, %d\n", divide_power2(5, 2), 5 / 4);
    printf("%d, %d\n", divide_power2(16, 3), 16 / 8);
    printf("%d, %d\n", divide_power2(23, 3), 23 / 8);
    printf("%d, %d\n", divide_power2(-23, 3), -23 / 8);
    printf("%d, %d\n", divide_power2(-14, 2), -14 / 4);
    printf("%d, %d\n", divide_power2(INT_MAX, 2), INT_MAX / 4);
    printf("%d, %d\n", divide_power2(INT_MIN, 2), INT_MIN / 4);
    return 0;
}
