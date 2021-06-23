#include <stdio.h>

int div16(int x) {
    int mask = x >> 31;
    return x + (15 & mask) >> 4;
}

int main() {
    printf("%d\n", div16(15));
    printf("%d\n", div16(17));
    printf("%d\n", div16(-15));
    printf("%d\n", div16(-17));
    return 0;
}
