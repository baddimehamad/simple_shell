#ifndef MAIN_H
#define MAIN_H
/**
 * unistd - functions
 * access, chdir, close, execve, getpid, isatty, kill,
 * open, read, signal, wait, waitpid, wait3, wait4, write
 */
#include <unistd.h>
#include <stdlib.h>   /* exit, _exit, free, malloc */
#include <stdio.h>    /* fflush, perror */
#include <dirent.h>   /* closedir, opendir, readdir */
#include <sys/stat.h> /* stat, lstat, fstat */
#include <sys/wait.h> /* wait */
#include <string.h>   /* strtok */
#define BUFFER_SIZE 1024
#define MAX_TOKENS 100
extern char **environ;
/**
 * struct CommandNode - singly linked list
 * @command: string - (malloc'ed string)
 * @next: points to the next node
 * Description: singly linked list node
 */
typedef struct CommandNode
{
	char command[100];
	struct CommandNode *next;
} CommandNode;
/**
 * struct CommandHistory - singly linked list
 * @head: CommandNode head
 * @tail: CommandNode tail
 * Description: singly linked list node structure
 */
typedef struct CommandHistory
{
	CommandNode *head;
	CommandNode *tail;
} CommandHistory;

/**
 * struct ENV - simple envirenment variable details
 * Struct.
 * @index: envirenment variable index
 * @key: envirenment variable key
 * @value: envirenment variable value
 * Description: simple envirenment variable details structure
 */

typedef struct ENV
{
	int index;
	char *key;
	char *value;
} ENV;
CommandHistory *create_history();
char *join_strings(const char **strings, int count);
char **splitString(const char *str, char delimiter, int *numTokens);
void print_history(const CommandHistory *history);
void clear_history(CommandHistory *history);
void add_to_history(CommandHistory *history, const char *command);
int _strlen(const char *f);
void handle_exec(int ac, char **av, CommandHistory *history);
int _putchar(char c);
int clear_screen(void);
int switch_builtin_command(char *cmds[64]);
char *getLastDirectory(const char *path);
char *_strrealloc(char *ptr, size_t size);
char *_strcpy(char *dest, const char *src);
char *_getenv0(const char *name);
ENV *_getenv(char *key);
int _putstr(char *c);
int _setenv(const char *key, const char *value);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strchr(const char *str, int character);
char *_strdup(const char *str);
char *find_command_path(char *buffer);
int change_directory(char *path);
int print_environment();
void run(char *buffer, CommandHistory *history);

#endif /*MAIN_H*/
