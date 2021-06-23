#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k) {
    int int_size = sizeof(int) << 3;
    int bias = (1 << k) - 1;
    int sign_mask = x >> (int_size - 1);
    return (x + (bias & sign_mask)) >> k;
}

int mul3div4(int x) {
    int mul3 = (x << 1) + x;
    return divide_power2(mul3, 2);
}

int main() {
    printf("%d\n", mul3div4(3));
    printf("%d\n", mul3div4(-3));
    printf("%d, %d\n", mul3div4(INT_MIN), INT_MIN * 3 / 4);
    return 0;
}
