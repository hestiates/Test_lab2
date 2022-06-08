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

  /* Проверка на запись файла*/
  if ((f = fopen(filename, "w")) == NULL)
    {
      printf("The file %s cannot be opened\n", filename);
      return;
    }

  /* Проверяем, имеется ли текст */
  if (txt == NULL || txt->length == 0)
    {
      fprintf(stderr, "There are already no any lines in the text!\n");
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
