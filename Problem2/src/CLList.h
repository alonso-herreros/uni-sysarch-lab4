#ifndef CLLIST_H
#define CLLIST_H

typedef struct node { 
    int key; 
    struct node *next; 
} node_t;

int list_add(node_t **head_p, int key);

void list_free(node_t *head);

#endif