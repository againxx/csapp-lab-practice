#include <limits.h>
#include <stdio.h>

int saturating_add(int x, int y) {
    int right_shift_num = (sizeof(int) << 8) - 1;
    int x_sign = x >> right_shift_num & 0x1;
    int y_sign = y >> right_shift_num & 0x1;
    int sum_sign = (x + y) >> right_shift_num & 0x1;
    int is_negative_overflow = x_sign & y_sign & !sum_sign;
    int is_positive_overflow = !x_sign & !y_sign & sum_sign;
    int is_normal = !(is_negative_overflow | is_positive_overflow);
    int normal_mask = ~is_normal + 1;
    int positive_mask = ~is_positive_overflow + 1;
    int negative_mask = ~is_negative_overflow + 1;
    return ((x + y) & normal_mask) + (INT_MIN & negative_mask) + (INT_MAX & positive_mask);
}

int main() {
    printf("INT_MAX: %d\n", INT_MAX);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("%d\n", saturating_add(10, 20));
    printf("%d\n", saturating_add(-1, 2));
    printf("%d\n", saturating_add(-5, -3));
    printf("%d\n", saturating_add(INT_MAX - 1, 3));
    printf("%d\n", saturating_add(INT_MIN + 1, -2));
    return 0;
}
