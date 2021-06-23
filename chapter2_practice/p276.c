#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void* calloc(size_t nmemb, size_t size) {
    size_t allocated_size = nmemb * size;
    if (!nmemb || !size || allocated_size / size != nmemb) {
        return NULL;
    }

    void* result = malloc(allocated_size);
    memset(result, 0, allocated_size);
    return result;
}

int main() {
    size_t n = 20;
    int* arr = (int*)calloc(n, sizeof(int));

    if (arr) {
        for (size_t i = 0; i < n; ++i) {
            printf("%i\n", arr[i]);
        }
    }

    free(arr);
    return 0;
}
