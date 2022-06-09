/**
 * save.c -- функция сохранения файла 
 */

#include <stdio.h>
#include "common.h"
#include "text.h"
#include "_text.h"

void save(text txt, char *filename)
{
  FILE *f;

  if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "The text doesn't exist\n");
        return;
    }

    if ((f = fopen(filename, "w")) == NULL) {
        fprintf(stderr, "File %s can't be opened\n", filename);
        return;
    }
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

    /* Стартуем с начальной строки текста */
    node *current = txt->begin;

    while (current)
      {
	fprintf(f, "%s", current->contents);
	current = current->next;
      }

    printf("File saved\n");
    fclose(f);
}
