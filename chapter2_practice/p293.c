#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp != 0xFF || frac == 0) {
        sign = 0;
    }
    return (sign << 31) | (exp << 23) | frac;
}


int main() {
    for (uint64_t i = 0; i < 2ul << 32; ++i) {
        float orig_result = *(float*)&i;
        orig_result = fabsf(orig_result);
        float_bits custom_float = (float_bits)i;
        float_bits abs_result = float_absval(custom_float);
        if (*(float_bits*)&orig_result != abs_result) {
            printf("input: %x, real: %x, expect: %x\n", custom_float, abs_result, *(float_bits*)&orig_result);
        }
        assert(*(float_bits*)&orig_result == abs_result);
    }
    return 0;
}
