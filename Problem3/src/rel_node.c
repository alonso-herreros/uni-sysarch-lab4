#include "rel_node.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


rel_node_t *rel_node_create(int id, char *real_name, char *common_name)
{
    rel_node_t *node = malloc(sizeof(rel_node_t));
    node->id = id;
    node->real_name = strdup(real_name);
    node->common_name = strdup(common_name);
    node->next = NULL;
    return node;
}

void rel_node_free(rel_node_t *node)
{
    free(node->real_name);
    free(node->common_name);
    if (node->next != NULL) {
        rel_node_free(node->next);
    }
    free(node);
}

void rel_node_print(rel_node_t *node)
{
    printf("%d: %s (%s)\n", node->id, node->real_name, node->common_name);
}

void rel_node_printa(rel_node_t *node)
{
    rel_node_print(node);
    if (node->next != NULL) {
        rel_node_printa(node->next);
    }
}


rel_node_t *rel_node_append(rel_node_t *head, rel_node_t *node)
{
    if (head == NULL) {
        return node;
    }
    rel_node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    return head;
}
