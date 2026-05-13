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
    struct information *head = NULL;
    struct information *p = head;

    char *in = malloc(10);

    int num = 0;
    int end = 0;

    while (end == 0)
    {
        scanf("%s", in); // 포인터 변수는 &붙일 필요 없음.

        // add
        if (strcmp(in, "add") == 0)
        {

            if (num == 0)
            {
                struct information *pinfo = malloc(sizeof(struct information));
                struct information info = {.next = NULL};
                info.name = malloc(100);
                scanf("%s %d", info.name, &(info.score));
                *pinfo = info;
                head = pinfo;
                p = head;
                num = 1;
            }
            else
            {
                num += 1;
                struct information *pinfo = malloc(sizeof(struct information));

                struct information newinfo = {.next = NULL};
                newinfo.name = malloc(100);
                scanf("%s %d", newinfo.name, &(newinfo.score));

                *pinfo = newinfo;
                p->next = pinfo;
                p = p->next;
            }
        }

        // delete
        if (strcmp(in, "delete") == 0)
        {
            struct information *d = head;

            char *dename = malloc(100);
            scanf("%s", dename);

            struct information *bd = head;
            int hr = 0;

            if (head->next == NULL)
            {
                head = NULL;
                free(dename);
                num -= 1;
            } else if (strcmp(head->name, dename) == 0)
            {
                struct information *rhead = head;
                head = head->next;
                free(rhead);
                num -= 1;
            }
            else
            {
                for (struct information *c = head; strcmp(c->name, dename) != 0; c = c->next)
                {
                    d = d->next;
                    hr += 1;
                }

                for (int i = 0; i < hr - 1; i++)
                {
                    bd = bd->next;
                }

                bd->next = d->next;
                free(d->name);
                free(d);
                num -= 1;
            }

            if (num == 1 + hr)
                p = bd;
        }

        // print
        if (strcmp(in, "print") == 0)
        {
            for (struct information *c = head; c != NULL; c = c->next)
            {
                printf("%s %d\n", c->name, c->score);
            }
        }

        // quit
        if (strcmp(in, "quit") == 0)
        {
            struct information *c = head; 
            while(c != NULL) 
            {
                struct information *nextc;
                nextc = c->next;
                free(c->name);
                free(c);
                c = nextc;
            }

            end = 1;
        }
    }
}