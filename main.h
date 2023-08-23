#ifndef MAIN_H
#define MAIN_H
/**
 * all functions
 */
#include <unistd.h>
#include <stdlib.h>   
#include <stdio.h>   
#include <dirent.h>   
#include <sys/stat.h> 
#include <sys/wait.h> 
#include <string.h>   
#define BUFFER_SIZE 1024
#define MAX_TOKENS 100
extern char **environ;

typedef struct the_node
{
	char command[100];
	struct the_node *next;
} the_node;

typedef struct historique_c
{
	the_node *head;
	the_node *tail;
} historique_c;

typedef struct ENV
{
	int index;
	char *key;
	char *value;
} ENV;
historique_c *the_history_create();
char *concat_string(const char **strings, int count);
void clear_h(historique_c *history);
int clear_console(void);
int commands_builtin(char *cmds[64]);
char *get_the_last_directory(const char *path);
char *string_reallocation(char *ptr, size_t size);
char *string_copy(char *dest, const char *src);
char **split_text(const char *str, char delimiter, int *numTokens);
void print_h(const historique_c *history);
void history_add(historique_c *history, const char *command);
int lenght_string(const char *f);
void execution(int ac, char **av, historique_c *history);
int string_p(char c);
char *env_0(const char *name);
ENV *get_envirement(char *key);
char *string_to_chars(const char *str, int character);
char *string_dump(const char *str);
char *link_find(char *buffer);
int change_folder(char *path);
int string_put(char *c);
int envirement_set(const char *key, const char *value);
int compare_strings(const char *str1, const char *str2, size_t n);

int get_env();
void the_exec_run(char *buffer, historique_c *history);

#endif
