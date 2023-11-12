#include "shellosama.h"

/**
* _myhistory - displays history list, proceceded
*with line numbers, starting at 0.
* @infox: Structure containing arguments.
*        constant function prototype.
*  Return: Always 0
*/
int _myhistory(info_t *infox)
{
print_list(infox->history);
return (0);
}

/**
* unset_alias - set alias to string
* @infox: parameter struct.
* @strg:  string alias.
* Return: Always 0 on success,else  1 on error
*/
int unset_alias(info_t *infox, char *strg)
{
char *p, c;
int rets;
p = _strchr(strg, '=');
if (!p)
return (1);
c = *p;
*p = 0;
rets = delete_node_at_index(&(infox->alias),
get_node_index(infox->alias, node_starts_with(infox->alias, strg, -1)));
*p = c;
return (rets);
}

/**
* set_alias - sets  the  alias to string
* @info: parameter struct.
* @strg: string alias.
* Return: Always 0 on success, 1 on error
*/
int set_alias(info_t *infox, char *strg)
{
char *p;
p = _strchr(strg, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(infox, strg));
unset_alias(infox, strs);
return (add_node_end(&(infox->alias), strs, 0) == NULL);
}

/**
* print_alias - prints an "  alias string " .
* @node: alias node
* Return: Always 0 at success, other wise 1 error
*/
int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;
if (node)
{
p = _strchr(node->strg, '=');
for (a = node->strg; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
* _myalias - mimics the alias builtin (man alias)
* @infox: Structure containing potential arguments.
* constant function prototype.
*  Return: Always 0
*/
int _myalias(info_t *infox)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;
if (infox->argc == 1)
{
node = infox->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; infox->argv[i]; i++)
{
p = _strchr(infox->argv[i], '=');
if (p)
set_alias(infox, infox->argv[i]);
else
print_alias(node_starts_with(infox->alias, infox->argv[i], '='));
}
return (0);
}
