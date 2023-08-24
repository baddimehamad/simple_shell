#include "main.h"

/**
 * handler_fun 
 * @handler: pointer
 */
void handler_fun(int handler)
{
	(void)handler;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
