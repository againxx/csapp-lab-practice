#include <stdio.h>

int lower_one_mask1(int n) {
    unsigned all_mask = ~0x0;
    int int_size = sizeof(int) << 3;
    return all_mask >> (int_size - n);
}

int lower_one_mask2(int n) {
    int shifted = 1 << (n - 1);
    return ((shifted - 1) << 1) + 1;
}

int main() {
    printf("0x%x 0x%x\n", lower_one_mask1(6), lower_one_mask2(6));
    printf("0x%x 0x%x\n", lower_one_mask1(17), lower_one_mask2(17));
    printf("0x%x 0x%x\n", lower_one_mask1(32), lower_one_mask2(32));
    return 0;
}
