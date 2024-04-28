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
 
int main(void) {

    struct elephant *bluey;

    bluey = elephant_ctor("Bluey", "Yellow");
    elephant_dump(bluey);
    elephant_dtor(bluey);

}