#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct information
{
    char *name;
    int score;
    struct information *next;
};

int main()
{
    struct information *head = malloc(sizeof(struct information));
    char *in = NULL;

    char *inname = NULL;
    int inscore = 0;

    int num, end = 0;

    while (end == 0)
    {
        scanf("%s %s %d", in, inname, inscore);

        // add
        if (in == "add")
        {
            if (num == 0)
            {
                struct information info = {inname, inscore, NULL};
                head = &info;
                num = 1;
                printf("got it");
            }
            else
            {
                head = realloc(head, num * sizeof(struct information));
                struct information newinfo = {inname, inscore, NULL};
                head->next = &newinfo;
                num += 1;
            }
        }

        // delete

        // print


        // quit
        if (in == "quit")
        {
            free(head);
            end = 1;
        }
    }
}