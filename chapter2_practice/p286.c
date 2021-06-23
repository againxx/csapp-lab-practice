#include <stdio.h>
#include <float.h>

int main() {
    long double x = LDBL_MAX;
    printf("%Le\n", x);
    return 0;
}
