/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

	/*ИЗМЕНЕНИЯ*/
	int h = 0;
	h = h + 31;
	show(h);

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

        if (strcmp(cmd, "showdigitsonly") == 0) {
            showdigitsonly(txt);
            continue;
        }
        
        /* Сохраняем содержимое файла, заданного параметром */
        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }
        
        /* Перемещение */
        if (strcmp(cmd, "m") == 0)
	  {
	    char *line, *pose;
	      if ((line = strtok(NULL, " \n")) == NULL
               	|| (pose = strtok(NULL, " \n")) == NULL)
	      {
                fprintf(stderr, "Usage: m line position\n");
	      }
	      else
		{
		 m(txt, atoi(line), atoi(pose));
         show(txt);
		}
	      continue;
	      }

        if (strcmp(cmd, "mklb") == 0) {
                    if ((arg = strtok(NULL, " \n")) == NULL) {
                        fprintf(stderr, "Usage: mklb line\n");
                    } else {
                        mklb(txt, atoi(arg));
                        show(txt);
                    }
                    continue;
                }

        if (strcmp(cmd, "pn") == 0)
        {
            if ((arg = strtok(NULL, "\n")) == NULL)
                {
                    fprintf(stderr, "Not enough arguments\n");
                }
            else
                {
                    paste_n(txt, arg);
                    show(txt);
                }
            continue;
         }

        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
