#include "shellosama.h"

/**
* _myenv - prints the current environment
* @infox: Structure containing potential arguments.
*          constant function prototype.
* Return: Always 0
*/
int _myenv(info_t *infox)
{
print_list_str(infox->env);
return (0);
}

/**
* _getenv - gets the value of an environ variable
* @infox: Structure containing potential arguments. Used to maintain
* @names: env var names
* Return:  value
*/
char *_getenv(info_t *infox, const char *names)
{
list_t *node = infox->env;
char *p;
while (node)
{
p = starts_with(node->strg, names);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}

/**
* _mysetenv - Initialize a new environment variable,
*             or modify an existing one
* @infox: Structure containing potential arguments.
*        constant function .
*  Return: Always 0
*/
int _mysetenv(info_t *infox)
{
if (infox->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(infox, infox->argv[1], infox->argv[2]))
return (0);
return (1);
}
/**
* _myunsetenv - Remove an environment variable
* @infox: Structure containing potential arguments.
*        constant function prototype.
* Return: Always 0
*/
int _myunsetenv(info_t *infox)
{
int i;
if (infox->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= infox->argc; i++)
_unsetenv(infox, infox->argv[i]);
return (0);
}

/**
* populate_env_list - populates env linked list
* @infox: Structure containing potential arguments.
*          constant function prototype.
* Return: Always 0
*/
int populate_env_list(info_t *infox)
{
list_t *node = NULL;
size_t i;
for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
infox->env = node;
return (0);
}
