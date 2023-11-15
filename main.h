#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


int custom_shell_ctrld(char **args);
int custom_shell_cd(char **args);
int custom_shell_help(char **args);
extern char **environ;
int custom_shell_exit(char **argv);
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);
char *custom_getline(void);
char *custom_read_input(void);
int custom_find_newline(char *buffer, int size);
char *custom_copy_line(char *buffer, int len, char *line);
void custom_shift_buffer(char *buffer, int size, int pos);

char *get_path(char **env);
int value_path(char **arg, char **env);
char *_getline_command(void);
char *read_line(void);
void print_environment(char **env);
char **tokenize_input(char *lptr);
void _exit_command(char **args, char *lineptr, int _exit);
int custom_fork(char **argc, char **argv, char **env,
char *lineptr, int np, int c);
int _set_environment_variable(char **args);
int _unset_environment_variable(char **args);
void handle_setenv_command(char **args);
void handle_unsetenv_command(char **args);


#endif /* MAIN_H */
