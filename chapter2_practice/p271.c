#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    int rshift_num = 24 - (bytenum << 3);
    int result = word << rshift_num;
    result >>= 24;
    return result;
}

int main() {
    printf("0x%.8x\n", xbyte(0x12f456ab, 3));
    return 0;
}
