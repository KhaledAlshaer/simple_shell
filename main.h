#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DEF_BUF_SIZE 128
extern char **environ;


int _putchar(char c);
int _puts(char *str);
int _strlen(char *str);
char *_concat_with_char(char *str1, char mid_char, char *str2);

int _strcmp(char *str1, char *str2);
char *_strdup(char *str);
char **_split(char *buffer, char *delim);
ssize_t _realloc(char **buf, int new_len);


void _exec(char **args);
void _path_then_exec(char **args);
void _perror(char *err_msg, char *free_me);
void _env(void);

void _is_interactive(void);


size_t _getline(char **buf, int *n, FILE *stream);


#endif
