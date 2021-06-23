#include <stdio.h>

int int_shifts_are_arithmetic() {
    int i = -1;
    return i >> 1 == -1;
}

int main() {
    int right_shift = int_shifts_are_arithmetic();
    printf("%d", right_shift);
    return 0;
}
