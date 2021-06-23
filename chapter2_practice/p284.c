#include <stdio.h>
#include <assert.h>

unsigned f2u(float x) {
    return *(unsigned *)&x;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    // Wrong answer
    /* return sx == sy ? (sx == 0 ? ux <= uy : ux >= uy) : sx > sy; */
    return sx + sy >= 1 ? (ux >= uy || (ux == -ux && uy == -uy)) : ux <= uy;
}


int main() {
    assert(float_le(+0.0f, -0.0f));
    assert(float_le(-0.0f, +0.0f));
    assert(float_le(0.0f, 3.0f));
    assert(float_le(-4.12f, -0.0f));
    assert(float_le(-4.0f, 4.0f));
    assert(!float_le(4.0f, -4.0f));
    assert(!float_le(3.0f, 2.0f));

    return 0;
}
