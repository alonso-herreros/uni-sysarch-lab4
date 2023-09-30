#ifndef REL_ARRAY_H
#define REL_ARRAY_H

#include "relationship.h"

typedef struct relationship_array{ 
    rel_t **array;
    int size;
    int capacity;
} rel_array_t;

rel_array_t *rel_array_init();
void rel_array_free(rel_array_t *rel_array);
void rel_array_print(rel_array_t *array);

rel_array_t *rel_array_load(rel_array_t *array, rel_t *rel);
int rel_array_find(rel_array_t *array, char *name, int start);
rel_array_t *delete_duplicates(rel_array_t *array);

#endif