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

/*helper functions*/
void print_to_stdout(char *string, int length);
char **split_string(char *string, char *deli);
void remove_trailing_newline(char *string);
int string_length(char *string);
void copy_ztring(char *destin, char *source);

/*helper functions 2*/
int compare_strings(char *string1, char *string2);
char *concatenate_strings(char *string1, char *string2);
int span_string(char *string, char *characs);
int complement_span_string(char *string, char *characs);
char *find_character_in_string(char *string, char *charac);

/* Helper functions 3*/
char *get_next_token(char *string, char *deli, char **save_pointer);
int convert_to_integer(char *string);
void *reallocate_memory(void *pointer, unsigned int old_size,
		unsigned int new_size);
void ctrl_c_handler(int signal);
void remove_comment_from_line(char *line);

/* Utility functions */
int identify_command_type(char *comn);
void execute_command(char **comn_args, int comn_type);
char *search_path_for_command(char *comn_name);
void (*get_command_function(char *comn_name))(char **arguments);
char *get_environment_variable(char *variable_name);

/* Built-in command functions */
void show_environment_variables(char **arguments);
void quit_shell(char **arguments);

/* Main functions */
extern void run_shell_non_interactively(void);
extern void initialize_shell(char **current_comn, int comn_type);

#endif

