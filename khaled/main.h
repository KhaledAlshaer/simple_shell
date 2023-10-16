#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>



int _putchar(char c);
int _puts(char *str);
int _strlen(char *str);
char *_concat_with_char(char *str1, char mid_char, char *str2);

int _strcmp(const char *str1, const char *str2);
char *_strdup(char *str);
char **_split(char *buffer, char *delim);
int is_delim(char c, const char *delim);
char *_strtok(char *str, char *delim);


extern char **environ;

void _exec(char **args);
void _path_then_exec(char **args);
void _perror(char *err_msg, char *free_me);
void _env(void);

void _is_interactive(void);




#endif
