#ifndef COMIC_H
#define COMIC_H

typedef struct comic { 
    int number; 
    char *collection; 
    struct comic *next; 
} comic_t;

comic_t *create_comic(int number, char *collection);
void free_comic(comic_t *c);

comic_t *copy_comic(comic_t *c);

void print_comic(comic_t *c);

comic_t *append_comic(comic_t *head, comic_t *new_comic);
comic_t *append_comic_copy(comic_t *head, comic_t *new_comic);

comic_t *subtract_lists(comic_t *listA, comic_t *listB);


#endif