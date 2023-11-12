#include "shellosama.h"

/**
* interactive - returns " true" if shellosama is interactive mode
* @info: struct address
* Return:" 1 " if interactive mode,else  0 otherwise
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - checks if character is a delimeter
* @c:  char to check
* @delim:  delimet string
* Return: 1 if true,else 0 if false
*/
int is_delim(char c, char *delimosama)
{
while (*delimosama)
if (*delimosama++ == c)
return (1);
return (0);
}

/**
* _isalpha - this is checks for alphabetic characters
* @c: The character for  input
* Return: 1 if c is alphabetic, else 0 otherwise
*/

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
* _atoiosama - converts a string vaireble to an integer vaireble
* @s: the string to be confirt converted
* Return: 0 if no numbers in string, else  converted number otherwise
*/
int _atoi(char *s)
{
int i, signx = 1, flagx = 0, outputx;
unsigned int resultx = 0;
for (i = 0; s[i] != '\0' && flagx != 2; i++)
{
if (s[i] == '-')
signx *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
flagx = 1;
resultx *= 10;
resultx += (s[i] - '0');
}
else if (flagx == 1)
flagx = 2;
}
if (signx == -1)
outputx = -resultx;
else
outputx = resultx;
return (outputx);
}
