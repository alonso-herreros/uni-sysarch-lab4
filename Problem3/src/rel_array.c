#include "rel_array.h"
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 10


rel_array_t *rel_array_init()
{
    rel_array_t *rel_array = malloc(sizeof(rel_array_t));
    rel_array->size = 0;
    rel_array->capacity = INIT_SIZE;
    rel_array->array = malloc(sizeof(rel_t) * rel_array->capacity);
    return rel_array;
}
void rel_array_free(rel_array_t *rel_array)
{
    for (int i = 0; i < rel_array->size; i++) {
        rel_free(rel_array->array[i]);
    }
    free(rel_array->array);
    free(rel_array);
}

void rel_array_print(rel_array_t *array)
{
    for (int i = 0; i < array->size; i++) {
        rel_print(array->array[i]);
    }
}


rel_array_t *rel_array_load(rel_array_t *array, rel_t *rel)
{
    array->size += 1;
    if (array->size > array->capacity) {
        array->capacity += INIT_SIZE;
        array->array = realloc(array->array, sizeof(rel_t) * array->capacity);
    }
    array->array[array->size - 1] = rel;
    return array;
}


int rel_array_find(rel_array_t *array, char *name, int start)
{
    for (int i = start; i < array->size; i++) {
        if (strcmp(array->array[i]->common_name, name) == 0) {
            return i;
        }
    }
    return -1;
}


rel_array_t *delete_duplicates(rel_array_t *arr)
{
    rel_array_t *out = rel_array_init();

    for (int i = 0; i < arr->size; i++) {
        rel_t *rel = arr->array[i];
        if (rel_array_find(arr, rel->common_name, i+1) < 0) {
            rel_array_load(out, rel);
        } else {
            rel_free(rel);
        }
    }

    free(arr->array);
    free(arr);

    return arr = out;
}
