#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp == 0) {
        // there is no need to determine whether the frac will overflow,
        // the most significant bit will automatically become the exp bit
        frac <<= 1;
    }
    else if (exp != 0xFF) {
        ++exp;
        // overflow to infinity, clear out the frac bits
        if (exp == 0xFF) {
            frac = 0;
        }
    }
    return (sign << 31) | (exp << 23) | frac;
}

int main() {
    for (uint64_t i = 0; i < 2ul << 32; ++i) {
        float orig_result = *(float*)&i;
        orig_result *= 2.0f;
        float_bits custom_float = (float_bits)i;
        float_bits twice_result = float_twice(custom_float);
        if (*(float_bits*)&orig_result != twice_result) {
            printf("input: %x, real: %x, expect: %x\n", custom_float, twice_result, *(float_bits*)&orig_result);
        }
        assert(*(float_bits*)&orig_result == twice_result);
    }
    return 0;
}
