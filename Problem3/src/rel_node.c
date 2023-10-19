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


rel_node_t *rel_node_copy(rel_node_t *node)
{
    if (node == NULL) {
        return NULL;
    }
    rel_node_t *copy = rel_node_copy_one(node);
    copy->next = node->next == NULL ? NULL : rel_node_copy(node->next);
    return copy;
}
rel_node_t *rel_node_copy_one(rel_node_t *node)
{
    if (node == NULL) {
        return NULL;
    }
    rel_node_t *copy = malloc(sizeof(rel_node_t));
    copy->id = node->id;
    copy->real_name = strdup(node->real_name);
    copy->common_name = strdup(node->common_name);
    copy->next = NULL;
    return copy;
}


rel_node_t *rel_node_mix(rel_node_t *oddList, rel_node_t *evenList)
{
    if (oddList == NULL) {
        return rel_node_copy(evenList); // evenList may be NULL, but rel_node_copy handles that
    }
    if (evenList == NULL) {
        return rel_node_copy(oddList);
    }
    rel_node_t *new_list = NULL;
    rel_node_t *currentOdd = oddList;
    rel_node_t *currentEven = evenList;

    // end starts at 0. If one list contains items, it will be set to -1. After increment, it will be 0 again.
    // If no list contains items, it will increase from 0 to 1, and the loop will end.
    for (int end=0; end<1; end++) {
        if (currentOdd != NULL) {
            new_list = rel_node_append(new_list, rel_node_copy_one(currentOdd));
            currentOdd = currentOdd->next;
            end = -1; // After increment, end will be 0 again, meaning the loop will continue
        }
        if (currentEven != NULL) {
            new_list = rel_node_append(new_list, rel_node_copy_one(currentEven));
            currentEven = currentEven->next;
            end = -1; // After increment, end will be 0 again, meaning the loop will continue
        }
    }
    return new_list;
}
