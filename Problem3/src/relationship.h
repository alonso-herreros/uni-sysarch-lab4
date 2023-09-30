#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

typedef struct relationship{ 
    int id;
    char *real_name;
    char *common_name;
} rel_t;

rel_t *rel_init(int id, char *real_name, char *common_name);
void rel_free(rel_t *rel);
void rel_print(rel_t *rel);

#endif