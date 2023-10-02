#include "relationship.h"
#include "rel_array.h"
#include "rel_node.h"
#include <stdio.h>


// Sections 3.2-3.4
int main(int argc, char **argv) {
    rel_node_t *rel_llist;
    rel_llist = rel_node_create(1, "Bruce Wayne", "Batman");
    rel_node_append(rel_llist, rel_node_create(2, "Clark Kent", "Superman"));
    rel_node_append(rel_llist, rel_node_create(3, "Bruce Banner", "Hulk"));
    rel_node_append(rel_llist, rel_node_create(4, "Peter Parker", "Spiderman"));
    rel_node_append(rel_llist, rel_node_create(5, "Tony Stark", "Ironman"));

    printf("Initial linked list at %p: \n", rel_llist);
    rel_node_printa(rel_llist);

    rel_node_t *rel_llist_copy = rel_node_copy(rel_llist);
    printf("\nCopy of linked list at %p: \n", rel_llist_copy);
    rel_node_printa(rel_llist_copy);

    rel_node_free(rel_llist);
    rel_node_free(rel_llist_copy);

    return 0;
}


// Section 3.1
// int main(int argc, char **argv) {
//     rel_array_t *rel_array = rel_array_init();
//     rel_array_load(rel_array, rel_init(1, "Bruce Wayne", "Batman"));
//     rel_array_load(rel_array, rel_init(2, "Clark Kent", "Superman"));
//     rel_array_load(rel_array, rel_init(3, "Bruce Banner", "Hulk"));
//     rel_array_load(rel_array, rel_init(4, "Peter Parker", "Spiderman"));
//     rel_array_load(rel_array, rel_init(5, "Tony Stark", "Ironman"));
//     rel_array_load(rel_array, rel_init(6, "Bruce Wayne", "Batman"));
//     rel_array_load(rel_array, rel_init(7, "Bruce Banner", "Hulk"));
//     rel_array_load(rel_array, rel_init(8, "Bruce Banner", "Hulk"));
//     printf("Initial array: \n");
//     rel_array_print(rel_array);
//     printf("\n");

//     rel_array = delete_duplicates(rel_array);
//     printf("Final array: \n");
//     rel_array_print(rel_array);

//     rel_array_free(rel_array);
//     return 0;
// }
