#include "relationship.h"
#include "rel_array.h"
#include <stdio.h>


int main(int argc, char **argv) {
    rel_array_t *rel_array = rel_array_init();
    rel_array_load(rel_array, rel_init(1, "Bruce Wayne", "Batman"));
    rel_array_load(rel_array, rel_init(2, "Clark Kent", "Superman"));
    rel_array_load(rel_array, rel_init(3, "Bruce Banner", "Hulk"));
    rel_array_load(rel_array, rel_init(4, "Peter Parker", "Spiderman"));
    rel_array_load(rel_array, rel_init(5, "Tony Stark", "Ironman"));
    rel_array_load(rel_array, rel_init(6, "Bruce Wayne", "Batman"));
    rel_array_load(rel_array, rel_init(7, "Bruce Banner", "Hulk"));
    rel_array_load(rel_array, rel_init(8, "Bruce Banner", "Hulk"));
    printf("Initial array: \n");
    rel_array_print(rel_array);
    printf("\n");

    rel_array = delete_duplicates(rel_array);
    printf("Final array: \n");
    rel_array_print(rel_array);

    rel_array_free(rel_array);
}
