#include <stdio.h>
#include "common.h"
#include "_text.h"
#include "text.h"

void mklb(text txt, int line)
{
    int k = 1;

    if (txt == NULL || txt->length == 0)
    {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }
    node *current = txt->begin;

    txt->cursor->position = 0;

    if (line > 0)
    {
        int l = txt->length;
        if (line > l)
            line = l;

        while(current)
        {
            if (k == line)
            {
                txt->cursor->line = current;
                break;
            }
            current = current->next;
            k ++;
        }
    }
    else
    {
        txt->cursor->line = current;
    }
}
