#include "shellosama.h"

/**
**_strncpy - copies a string
*@des: the destination string to be copied to
*@srcs: the source string
*@n: the amount of characters to be copied
*Return: the concatenated string
*/
char *_strncpy(char *des, char *srcs, int n)
{
int i, j;
char *s = des;
i = 0;
while (srcs[i] != '\0' && i < n - 1)
{
des[i] = srcs[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
des[j] = '\0';
j++;
}
}
return (s);
}

/**
**_strncat - concatenates two strings
*@des: the first string
*@srcs: the second string
*@n: the amount of bytes to be maximally used
*Return: the concatenated string
*/
char *_strncat(char *des, char *srcs, int n)
{
int i, j;
char *s = des;

i = 0;
j = 0;
while (des[i] != '\0')
i++;
while (srcs[j] != '\0' && j < n)
{
des[i] = srcs[j];
i++;
j++;
}
if (j < n)
des[i] = '\0';
return (s);
}

/**
**_strchr - locates a character at a string
*@s: string to be parsed
*@z: character to look for
*Return: (s) a pointer to the memory area s
*/
char *_strchr(char *s, char z)
{
do {
if (*s == z)
return (s);
} while (*s++ != '\0');
return (NULL);
}
