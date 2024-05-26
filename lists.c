#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elephant
{
    char *name;
    char *color;
};

struct elephant *elephant_ctor(char *name, char *color) {
    struct elephant *tmp;

    tmp = malloc(sizeof (struct elephant));
    tmp->name = strdup(name);
    tmp->color = strdup(color);

    return tmp;
}

void elephant_dtor(struct elephant *e) 
{
   free(e->name);
   free(e->color);
   free(e);
}

void elephant_dump(struct elephant *e)
{
    printf("%s %s\n", e->name, e->color);
}
 

struct llist_element {
    void *data;
    struct llist_element *next;
};

struct llist_element  *llist_elem_ctor(void *data)
{
    struct llist_element *tmp;

    tmp = malloc(sizeof(struct llist_element));
    tmp->next = NULL;
    tmp->data = data;

    return tmp;
}

struct llist {
    struct llist_element *head;
    struct llist_element *tail;
};

struct llist* llist_ctor(void) {
    struct llist *tmp;
    tmp = malloc(sizeof(struct llist));
    tmp->head = NULL;
    tmp->tail = NULL;

    return tmp;
}

void llist_dtor(struct llist *l) 
{
    struct llist_element *ptr;

    ptr = l->head;

    while(ptr) {
        struct llist_element *next = ptr->next;

        free(ptr);

        ptr = next;

    }
    free(l);
} 

void llist_add(struct llist *l, void *data)
{
    struct llist_element *e;

    e = llist_elem_ctor(data);

    if (l->head == NULL) {
        l->head = e;
        l->tail = e;
    } else {
        l->tail->next = e;
        l->tail = e;
    }
}

int main(void) {

    struct elephant *bluey, *sonny, *wooly;
    struct llist *elePHPants;

    bluey = elephant_ctor("Bluey", "Blue");
    sonny = elephant_ctor("Sunny", "Yellow");
    wooly = elephant_ctor("Wooly", "Brownly");

    elePHPants = llist_ctor();

    llist_add(elePHPants,  bluey);
    llist_add(elePHPants,  sonny);
    llist_add(elePHPants,  wooly);

    llist_dtor(elePHPants);
    // elephant_dtor(bluey);
    // elephant_dtor(sonny);
    // elephant_dtor(wooly);
    elephant_dump(bluey);

}

// valgrind --show-reachable=yes ./list 