#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "text.h"

static void show_digits_only(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showdigitsonly(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
  process_forward(txt, show_digits_only, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_digits_only(int index, char *contents, int cursor, void *data)
{

    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    
    int maxlen = strlen(contents) - 1;
    int len = maxlen > cursor ? maxlen : cursor;

    for (int i = 0; i<= len; i++)
      {
        if (i == cursor)
            printf ("|");

        if (i <= maxlen && isdigit(contents[i]))
            {
                printf("%c", contents[i]);
            }
        else if (i < len)
                      printf(" ");
            else if (i == len && i != cursor)
                printf(" ");
      }
    
    printf("\n");
}
