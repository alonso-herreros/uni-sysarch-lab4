#include "Comic.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

comic_t *create_comic(int number, char *collection)
{
    comic_t *c = malloc(sizeof(comic_t));
    c->number = number;
    c->collection = strdup(collection);
    c->next = NULL;
    return c;
}

void free_comic(comic_t *c)
{
    free(c->collection);
    if (c->next != NULL) {
       free_comic(c->next);
    }
    free(c);
}

comic_t *copy_comic(comic_t *c)
{
    comic_t *copy = malloc(sizeof(comic_t));
    copy->number = c->number;
    copy->collection = strdup(c->collection);
    copy->next = NULL;
    return copy;
}


int comics_equal(comic_t *a, comic_t *b)
{
    return (a->number == b->number && strcmp(a->collection, b->collection) == 0) ? 1 : 0;
}


void print_comic(comic_t *c)
{
    printf("Comic #%d from %s\n", c->number, c->collection);
}


comic_t *append_comic(comic_t *head, comic_t *new_comic)
{
    if (head == NULL) {
        return new_comic;
    }
    comic_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_comic;
    return head;
}

comic_t *append_comic_copy(comic_t *head, comic_t *new_comic)
{
    return append_comic(head, copy_comic(new_comic));
}


int find_comic(comic_t *list, comic_t *comic)
{
    comic_t *current = list;
    for (int i=0; current != NULL; i++) {
        if (comics_equal(current, comic)) {
            return i;
        }
        current = current->next;
    }
    return -1;
}


comic_t *subtract_lists(comic_t *listA, comic_t *listB)
{
    comic_t *currentA = listA;
    comic_t *result = NULL;

    while (currentA != NULL) {
        if (find_comic(listB, currentA) == -1) {
            result = append_comic_copy(result, currentA);
        }
        currentA = currentA->next;
    }
    return result;
}

