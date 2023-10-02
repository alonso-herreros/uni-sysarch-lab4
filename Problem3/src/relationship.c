#include "relationship.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


rel_t *rel_init(int id, char *real_name, char *common_name)
{
    rel_t *rel = malloc(sizeof(rel_t));
    rel->id = id;
    rel->real_name = strdup(real_name);
    rel->common_name = strdup(common_name);
    return rel;
}
void rel_free(rel_t *rel)
{
    free(rel->real_name);
    free(rel->common_name);
    free(rel);
}

void rel_print(rel_t *rel)
{
    printf("%d: %s (%s)\n", rel->id, rel->real_name, rel->common_name);
}
