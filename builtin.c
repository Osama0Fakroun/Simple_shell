#include "shellosama.h"

/**
* _mexit - exit from  the shell
* @info: Structure containing potential arguments. Used to maintains
*constant for function prototype.
* Return: exit with a given exit status confirm
* (0) if info.argv[0] != "exit"
*/
int _myexit(infox_t *infox)
{
int exitcheck;
if (infox->argv[1]) /* If there exit arguement */
{
exitcheck = _erratoi(infox->argv[1]);
if (exitcheck == -1)
{
infox->status = 2;
print_error(infox, "Illegal number: ");
_eputs(infox->argv[1]);
_eputchar('\n');
return (1);
}
infox->err_num = _erratoi(infox->argv[1]);
return (-2);
}
infox->err_num = -1;
return (-2);
}

/**
* _mycd - changes the current directory 
* @info: Structure containing arguments. Used to maintain
* constant functions prototype.
* Return: Always 0.
*/
int _mycd(info_t *infox)
{
char *s, *dirc, buffers[1024];
int chdir_ret;
s = getcwd(buffers, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!infox->argv[1])
{
dirc = _getenv(info, "HOME=");
if (!dirc)
chdir_ret = /* should this be? */
chdir((dirc = _getenv(infox, "PWD=")) ? dirc : "/");
else
chdir_ret = chdir(dirc);
}
else if (_strcmp(infox->argv[1], "-") == 0)
{
if (!_getenv(infox, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(infox, "OLDPWD=")), _putchar('\n');
hdir_ret = /* what should this be? */
chdir((dirc = _getenv(infox, "OLDPWD=")) ? dirc : "/");
}
else
chdir_ret = chdir(infox->argv[1]);
if (chdir_ret == -1)
{
print_error(infox, "I can't cd to ");
_eputs(infox->argv[1]), _eputchar('\n');
}
else
{
_setenv(infox, "OLDPWD", _getenv(infox, "PWD="));
_setenv(infox, "PWD", getcwd(buffers, 1024));
}
return (0);
}

/**
* _myhelp - changes the directory
* @info: Structure containing potential arguments.
* constant prototype.
* Return: Always 0
*/
int _myhelp(info_t *infox)
{
char **arg_arrays;
arg_arrays = infox->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_arrays); /* att_unused */
return (0);
}
