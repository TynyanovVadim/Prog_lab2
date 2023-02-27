#include <stdio.h>

#include "IntVector.h"

void pritn_vector(IntVector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", int_vector_get_item(v, i));
    }
    printf("\n");
    printf("size-%ld, capacity-%ld\n", v->size, v->capacity);
}

int main()
{
    IntVector *vector1 = int_vector_new(0);
    if (!vector1) {
        return -1;
    }

    printf("vector1");
    pritn_vector(vector1);

    int_vector_pop_back(vector1);
    printf("vector1 pop back\n");
    printf("vector1");
    pritn_vector(vector1);

    for (int i = 0; i < 10; i++) {
        int_vector_push_back(vector1, i);
    }
    printf("vector1 add 10 itmes\n");
    pritn_vector(vector1);

    IntVector *vector2 = int_vector_copy(vector1);
    if (!vector2) {
        return -1;
    }
    printf("vector2 is copy vector1\n");
    pritn_vector(vector2);

    printf("vector2 pop and shrink ot fit\n");
    int_vector_pop_back(vector2);
    int_vector_shrink_to_fit(vector2);
    pritn_vector(vector2);

    printf("Set item index = 3 value = 5\n");
    int_vector_set_item(vector2, 3, 5);
    pritn_vector(vector2);

    printf("vector1 resize to 5\n");
    int_vector_resize(vector1, 5);
    pritn_vector(vector1);

    printf("vector2 resize to 15\n");
    int_vector_resize(vector2, 15);
    pritn_vector(vector2);

    int_vector_free(vector1);
    int_vector_free(vector2);

    return 0;
}
