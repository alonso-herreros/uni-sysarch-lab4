#include "CLList.h"
#include <stdlib.h>

int list_add(node_t **head_p, int key)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }
    new_node->key = key;

    if (*head_p == NULL) {
        *head_p = new_node;
    }
    node_t *head = *head_p;
    new_node->next = head->next;
    head->next = new_node;

    return 0;
}


void list_free(node_t *head)
{
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
        if (current == head) {
            break;
        }
    }
}
