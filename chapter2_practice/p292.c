#include <stdint.h>
#include <assert.h>
#include <stdio.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp != 0xFF || frac == 0) {
        sign ^= 1;
    }
    return (sign << 31) | (exp << 23) | frac;
}


int main() {
    for (uint64_t i = 0; i < 2ul << 32; ++i) {
        float orig_result = *(float*)&i;
        orig_result = -orig_result;
        float_bits custom_float = (float_bits)i;
        float_bits negate_result = float_negate(custom_float);
        float negate_float = *(float*)&negate_result;
        if (orig_result != negate_float) {
            printf("input: %x, real: %x, expect: %x\n", custom_float, negate_result, *(float_bits*)&orig_result);
        }
        assert(orig_result == negate_float);
    }
    return 0;
}
