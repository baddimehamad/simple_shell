#ifndef _HOLBERTON_
#define _HOLBERTON_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;
/**
 * struct data
 * @val_arg: value
 * @the_input: value
 * @args: tvalue
 * @the_status: value
 * @nums: value
 * @the_env: value
 * @pere_id: value
 */
typedef struct data
{
	char **val_arg;
	char *the_input;
	char **args;
	int the_status;
	int nums;
	char **the_env;
	char *pere_id;
} data_shell;

/**
 * structur split_list_structure
 * @separator:  & or ;
 * @next: n
 */
typedef struct split_list_structure
{
	char separator;
	struct split_list_structure *next;
} sep_list;

/**
 * struct splite_line_list_struct 
 * @line: cmd
 * @next: n
 */
typedef struct splite_line_list_struct
{
	char *line;
	struct splite_line_list_struct *next;
} line_list;

/**
 * struct reverse_variable_list 
 * @len_var: value
 * @val: value
 * @len_val: value
 * @next: n
 */
typedef struct reverse_variable_list
{
	int len_var;
	char *val;
	int len_val;
	struct reverse_variable_list *next;
} r_var;

/**
 * struct struct_built_in 
 * @name: value
 * @f: data
 */
typedef struct struct_built_in
{
	char *name;
	int (*f)(data_shell *data_direc);
} builtin_t;


sep_list *separator_add(sep_list **the_head, char sep);
void empty_separator_list(sep_list **the_head);
line_list *add_line_end(line_list **the_head, char *line);
void empty_list(line_list **the_head);


r_var *add_var(r_var **the_head, int lvar, char *var, int lval);
void empty_var_list(r_var **the_head);

void _copy_memory(void *newptr, const void *ptr, unsigned int size);
void *the_re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **the_re_alloc_double(char **ptr, unsigned int old_size, unsigned int new_size);
char *duplicate_string(const char *s);
char *concat_string(char *dest, const char *src);
char *string_copy(char *dest, char *src);
int compare_strings(char *s1, char *s2);
char *char_in_string(char *s, char c);
int len_p_substring(char *s, char *accept);
int lenght_string(const char *s);
int compare_characters(char str[], const char *delim);
char *split_by_delimiter(char str[], const char *delim);
int is_number(const char *s);
void string_reverse(char *s);
int char_doubles(char *the_input, int i);
int find_errurs_s(char *the_input, int i, char last);
int the_char_1(char *the_input, int *i);
void echo_erreur_s(data_shell *data_direc, char *the_input, int i, int bool);
int check_erreur_s(data_shell *data_direc, char *the_input);
char *no_comment_fun(char *in);
void the_loop_shell(data_shell *data_direc);
char *the_read_line(int *i_eof);
void the_envirement_c(r_var **h, char *in, data_shell *data);
int the_v_cks(r_var **h, char *in, char *st, data_shell *data);
char *the_text_replaced(r_var **the_head, char *the_input, char *new_input, int nlen);
char *the_rep_var(char *the_input, data_shell *data_direc);
char *change_char_sw(char *the_input, int bool);
void add_separator_cmd(sep_list **head_s, line_list **head_l, char *the_input);
void the_go_next(sep_list **list_s, line_list **list_l, data_shell *data_direc);
int the_split_commands(data_shell *data_direc, char *the_input);
char **the_split_line(char *the_input);
int if_char_current(char *path, int *i);
char *_the_cmd_location(char *cmd, char **the_env);
int if_exec(data_shell *data_direc);
int erreur_command_check(char *dir, data_shell *data_direc);
int execute_commande(data_shell *data_direc);
void get_line_fun(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line_function_stream(char **lineptr, size_t *n, FILE *stream);
int execute_command(data_shell *data_direc);
void parent_directory(data_shell *data_direc);
void enter_to(data_shell *data_direc);
void return_to_old_dir(data_shell *data_direc);
void go_home(data_shell *data_direc);
char *information_copy(char *name, char *value);
void change_envirement(char *name, char *value, data_shell *data_direc);
int the_change_envirement(data_shell *data_direc);
int remove_envirement(data_shell *data_direc);
char *the_envirement_type(const char *name, char **the_env);
int the__envirement_(data_shell *data_direc);
int change_directory(data_shell *data_direc);
int (*the_builtin_functions(char *cmd))(data_shell *data_direc);
int out_of_shell(data_shell *data_direc);
int length_get(int n);
char *convert_int_to_string(int n);
int string_to_int(char *s);
char *string_cat_cd(data_shell *, char *, char *, char *);
char *cd_erreur(data_shell *data_direc);
char *erreur_null(data_shell *data_direc);
char *error_exit_shell(data_shell *data_direc);
char *error_get_alias(char **args);
char *erreur_envirement(data_shell *data_direc);
char *error_syntax(char **args);
int print_help_function(data_shell *data_direc);
char *error_permission(char **args);
char *erreur_link_126(data_shell *data_direc);
void handler_fun(int sig);
int the_erreur_function(data_shell *data_direc, int eval);
void help_built_fun(void);
void help_built_a(void);
void help_built_cd(void);
void help_built(void);
void help_built_set(void);
void help_built_unset(void);
void help_built_global(void);
void help_built_exit(void);


#endif
