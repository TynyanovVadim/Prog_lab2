#include <stdlib.h>

#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *vector = (IntVector*)malloc(sizeof(IntVector));
    if (!vector) {
        return NULL;
    }

    int *data = (int*) malloc(sizeof(int) * initial_capacity);
    if (!data) {
        free(vector);
        return NULL;
    }

    vector->data = data;
    return vector;
}

IntVector *int_vector_copy(const IntVector *v)
{
    IntVector *copy_vector = (IntVector*) malloc(sizeof(IntVector));
    if (!copy_vector) {
        return NULL;
    } 

    int *copy_data = (int*) malloc(sizeof(int) * v->capacity);
    if (!copy_data) {
        free(copy_vector);
        return NULL;
    }
    for (int i = 0; i < v->size; i++) {
        copy_data[i] = (v->data)[i];
    }
    copy_vector->data = copy_data;
    copy_vector->size = v->size;
    copy_vector->capacity = v->capacity;

    return copy_vector;
}

void int_vector_free(IntVector *v)
{
    free(v->data);
    free(v);
}

int int_vector_get_item(const IntVector *v, size_t index)
{
    int item = (v->data)[index];
    return item;
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
    (v->data)[index] = item;
}

size_t int_vector_get_size(const IntVector *v)
{
    return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
    size_t index = int_vector_get_size(v);
    size_t capacity = int_vector_get_capacity(v);
    if (index == capacity) {
        if (int_vector_reserve(v, capacity + 2)) {
            return -1;
        }
    }
    (v->data)[index] = item;
    (v->size)++;
    return 0;
}

void int_vector_pop_back(IntVector *v)
{
    if (v->size > 0) {
        v->size--;
    }
}

int int_vector_shrink_to_fit(IntVector *v)
{
    int* new_data = realloc(v->data, v->size * sizeof(int));
    if (!new_data) {
        return -1;
    }
    v->data = new_data;
    v->capacity = v->size;
    return 0;
}

int int_vector_resize(IntVector *v, size_t new_size)
{
    if (v->capacity < new_size) {
        if (int_vector_reserve(v, new_size)) {
            return -1;
        }
        for (int i = v->size; i < new_size; i++) {
            (v->data)[i] = 0;
        }
    }
    v->size = new_size;
    return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if (new_capacity > v->capacity) {
        int *new_data = realloc(v->data, new_capacity * sizeof(int));
        if (!new_data) {
            return -1;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    return 0;
}
