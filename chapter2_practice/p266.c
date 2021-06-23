#include <stdio.h>

int leftmost_one(unsigned x) {
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return (x >> 1) + 1;
}

int main() {
    printf("0x%x\n", leftmost_one(0xFF00));
    printf("0x%x\n", leftmost_one(0x6600));
    return 0;
}
