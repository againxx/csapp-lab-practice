#include <stdio.h>
#include <limits.h>

int main() {
    int x = 0x64e73387;
    int y = 0xd31cb264;
    int z = 5;
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;

    printf("%d\n", (dx * dy) * dz == dx * (dy * dz));
    printf("%f\n", 0.0 / 0.0);
    return 0;
}
