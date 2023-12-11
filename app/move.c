/**
 * m.c -- Команда перемещения в заданную позицию 
 */

#include <stdio.h>
#include "common.h"
#include "_text.h"
#include "text.h"

void m(text txt, int line, int pos)
{
    int k = 1;

    if (txt == NULL || txt->length == 0)
    {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }
    node *current = txt->begin;
    if (pos >= 0)
    {
        txt->cursor->position = pos;
    }
    else
    {
        txt->cursor->position = 0;
    }

    if (line > 0)
    {
        int l = txt->length;
        if (line > l)
            line = l;

        while(current)
        {
            if (k == line - 3)
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
