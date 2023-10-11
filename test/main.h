#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void _perror(char *err_msg, char *free_me);
int _strlen(char *str);
char *_concat_with_slash(char *str1, char *str2);
int _strcmp(char *str1, char *str2);


void child(char *buffer);
void _env(void);

#endif
