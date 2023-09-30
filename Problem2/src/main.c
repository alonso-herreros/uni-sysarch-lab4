#include "CLList.h"
#include <stdlib.h>
#include <stdio.h>


void list_print(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d\n", current->key);
        current = current->next;
        if (current == head) {
            break;
        }
    }
}


int main(int argc, char **argv) {
    node_t *list = NULL;
    
    list_add(&list, 0);
    list_add(&list, 1);
    list_add(&list, 2);
    list_add(&list, 3);

    list_print(list);

    list_free(list);
}
