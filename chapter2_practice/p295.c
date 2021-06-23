#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = 0;
    if (exp != 0xFF && exp != 0) {
        --exp;
        // from normalized to denormalized
        if (exp == 0) {
            bias = 1 << 22;
        }
    }
    if (exp == 0) {
        unsigned lsb = frac & 0x1;
        frac >>= 1;
        unsigned cur_lsb = frac & 0x1;
        if (lsb && cur_lsb) {
            frac += 1; // round to even
        }
    }
    return (sign << 31) | (exp << 23) | (frac + bias);
}

int main() {
    for (uint64_t i = 0; i < 2ul << 32; ++i) {
        float orig_result = *(float*)&i;
        orig_result *= 0.5f;
        float_bits custom_float = (float_bits)i;
        float_bits half_result = float_half(custom_float);
        if (*(float_bits*)&orig_result != half_result) {
            printf("input: %x, real: %x, expect: %x\n", custom_float, half_result, *(float_bits*)&orig_result);
            printf("actual float value: %f, %f\n", *(float*)&i, orig_result);
        }
        assert(*(float_bits*)&orig_result == half_result);
    }
    return 0;
}
