#include <stdio.h>
#include <string.h>
#include "common.h"
#include "text.h"
#include "_text.h"

void paste_n(text txt, const char *inputtext)
{
    assert(inputtext != NULL);

    node *str;

    if ((str = (node *) malloc(sizeof(node))) == NULL) {
        printf("Not enough memory\n");
        exit(EXIT_FAILURE);
    }

    if (strlen(inputtext) > MAXLINE) {
        printf("Line overbuff\n");
        free(str);
        return;
    }

    strncpy(str->contents, inputtext, MAXLINE);
    str->contents[MAXLINE] = '\0';

    str->previous = txt->cursor->line;
    node * new = txt->cursor->line->next;
    txt->cursor->line->next = str;
    if (txt->cursor->line != txt->end)
    {
        str->next = new;
        new->previous = str;
    }
    else
    {
        txt->end = str;
    }
    txt->length++;
}
