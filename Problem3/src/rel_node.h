#ifndef REL_NODE_H
#define REL_NODE_H

#include "relationship.h"

typedef struct node {
    int id;
    char *real_name;
    char *common_name;
    struct node *next;
} rel_node_t;


rel_node_t *rel_node_create(int id, char *real_name, char *common_name);
void rel_node_free(rel_node_t *node);
void rel_node_print(rel_node_t *node);
void rel_node_printa(rel_node_t *node);

rel_node_t * rel_node_append(rel_node_t *head, rel_node_t *node);


#endif