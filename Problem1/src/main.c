#include <stddef.h>
#include <stdio.h>
#include "Comic.h"


void init_comics(comic_t **all_p, comic_t **DCcomics_p)
{
    comic_t *current_comic = NULL;
    comic_t *all = NULL;
    comic_t *DCcomics = NULL;

    DCcomics = append_comic_copy(DCcomics, current_comic = create_comic(1, "Superman"));
    all = append_comic_copy(all, current_comic);
    free_comic(current_comic);
    append_comic_copy(DCcomics, current_comic = create_comic(2, "Superman"));
    append_comic_copy(all, current_comic);
    free_comic(current_comic);
    append_comic_copy(DCcomics, current_comic = create_comic(3, "Superman"));
    append_comic_copy(all, current_comic);
    free_comic(current_comic);

    append_comic_copy(DCcomics, current_comic = create_comic(1, "Batman"));
    append_comic_copy(all, current_comic);
    free_comic(current_comic);
    append_comic_copy(DCcomics, current_comic = create_comic(2, "Batman"));
    append_comic_copy(all, current_comic);
    free_comic(current_comic);

    append_comic(all, create_comic(1, "Spiderman"));
    append_comic(all, create_comic(2, "Spiderman"));
    append_comic(all, create_comic(3, "Spiderman"));

    *all_p = all;
    *DCcomics_p = DCcomics;
}


void print_comics(comic_t *list)
{
    comic_t *current = list;
    while (current != NULL) {
        print_comic(current);
        current = current->next;
    }
}


int main(int argc, char **argv)
{
    comic_t *all = NULL;
    comic_t *DCcomics = NULL;
    init_comics(&all, &DCcomics);

    comic_t *result = subtract_lists(all, DCcomics);
    print_comics(result);

    free_comic(all);
    free_comic(DCcomics);
    return 1;
}
