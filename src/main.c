#include <stdio.h>

#include "IntVector.h"

void pritn_vector(IntVector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", int_vector_get_item(v, i));
    }
    printf("\n");
}

int main()
{
    IntVector *vector1 = int_vector_new(5);
    if (!vector1) {
        return -1;
    }
    for (int i = 10; i > 0; i--) {
        int_vector_push_back(vector1, i);
    }

    pritn_vector(vector1);
    printf("size-%ld, capacity-%ld\n", vector1->size, vector1->capacity);

    IntVector *vector2 = int_vector_copy(vector1);
    if (!vector2) {
        return -1;
    }

    pritn_vector(vector2);
    printf("size-%ld, capacity-%ld\n", vector2->size, vector2->capacity);

    int_vector_shrink_to_fit(vector1);

    return 0;
}
