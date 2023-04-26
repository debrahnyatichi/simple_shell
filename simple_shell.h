#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*constants */
#define EXTERNAL_CMD 1
#define INTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

#define minimum(x, y) (((x) < (y)) ? (x) : (y))

/**
* struct cmd_map - a struct that maps a command name to a function
* @comn: name of the command
* @fun: the function executed by the command
*/

typedef struct cmd_map
{
char *comn;
void (*fun)(char **arguments);
} cmd_map;

extern char **environ_variables;
extern char *input_line;
extern char **input_cmds;
extern char *shell_name;
extern int status;

/*helper_functions*/
void print_to_stdout(char *str, int stream);
char **split_string(char *input, char *delim);
void _rm_newline(char *str);
int str_len(char *string);
void str_cpy(char *src, char *dest);

/*helper_functions_01*/
int str_cmp(char *first, char *second);
char *str_cat(char *dest, char *src);
int str_spn(char *str_1, char *str_2);
int str_c_spn(char *str_1, char *str_2);
char *str_chr(char *s, char c);

/* Utility functions */
int identify_command_type(char *comn);
void execute_command(char **comn_args, int comn_type);
char *search_path_for_command(char *comn_name);
void (*get_command_function(char *comn_name))(char **arguments);
char *get_environment_variable(char *variable_name);

/*builtin functions*/
void show_environment_variables(char **arguments);
void quit_shell(char **arguments);

/* Main functions */
extern void run_shell_non_interactively(void);
extern void initialize_shell(char **current_comn, int comn_type);

#endif

