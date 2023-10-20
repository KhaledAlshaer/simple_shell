#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DEF_BUF_SIZE 128
extern char **environ;

int _putchar(char c);
int _puts(char *str);
int _strlen(char *str);
char *_concat_with_char(char *str1, char mid_char, char *str2);
int _atoi(char *num);

int _strcmp(char *str1, char *str2);
char *_strdup(char *str);
char **_split(char *buffer, char *delim);
void *_realloc(void *ptr, int old_size, int new_size);
int _strlen_2d(char **str);

void _exec(char **args);
void _path_then_exec(char **args);
void _perror(char *command, char *free_me);
void _env(void);

int _is_interactive(void);
void _free_args(char **args);
char **_perr_free2d_exit1(char *err_msg, char **free_me);
void _eof_handle(char *biuf, int len);


int interactive(void);
int non_interactive(char *argv);


ssize_t _getline(char **buf, int *n, FILE *stream);


#endif
