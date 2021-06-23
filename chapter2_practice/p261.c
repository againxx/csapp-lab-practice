#include <stdio.h>

int main() {
    int x1 = 0xffffffff;
    int x2 = 0x00000100;
    int x3 = 0x000010ff;
    int x4 = 0x00f2a134;
    int shift_val = (sizeof(x4) - 1) << 3;

    printf("%d\n", !(x1 ^ -1));
    printf("%d\n", !(x2 | 0));
    printf("%d\n", !(x3 & 0xff ^ 0xff));
    printf("%d\n", !(x4 >> shift_val));
    return 0;
}
