#include <stdint.h>
#include <assert.h>
#include <stdio.h>

typedef unsigned float_bits;

int float_f2i(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int E = exp - 127;
    int result = 0;
    // denormalized always converse to zero
    // amplify the fraction part
    if (E >=0 && E <= 127) {
        int shift_amount = E - 23;
        if (shift_amount >= 0)
            result = (frac | 0x800000) << shift_amount;
        else
            result = (frac | 0x800000) >> -shift_amount;
        if (result == 0)
            result = 0x80000000;
    }
    else if (E == 128) // NaN or Infinity
        result = 0x80000000;
    if (sign)
        return ~result + 1;
    return result;
}

int main() {
    for (uint64_t i = 0; i < 2ul << 32; ++i) {
        float orig_float = *(float*)&i;
        float_bits custom_float = (float_bits)i;
        float_bits int_result = float_f2i(custom_float);
        if ((int)orig_float != int_result) {
            printf("input: %x, real: %x, expect: %x\n", custom_float, int_result, (int)orig_float);
            printf("actual float value: %f, %f\n", *(float*)&i, orig_float);
        }
        assert((int)orig_float == int_result);
    }
    return 0;
}
