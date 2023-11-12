#include "shellosama.h"

/**
* _erratoi - converts a string to integer
* @s: the string  be converted
* Return: 0 if no numbers in string, converted number otherwise
*       -1 on error
*/
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;
if (*s == '+')
s++;  /* TODO: why does this make main return 255?*/
for (i = 0;  s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}
/**
* print_error - prints an error message
* @infox: the parameter & return info struct
* @estrs: string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
*        -1 on error
*/
void print_error(info_t *infox, char *estrs)
{
_eputs(infox->fname);
_eputs(": ");
print_d(infox->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(infox->argv[0]);
_eputs(": ");
_eputs(estrs);
}

/**
* print_d - function prints a decimal (integer) number (base 10)
* @inputs: the input
* @fd: the filedescriptor to write
* Return: number of characters printed
*/
int print_d(int inputs, int fd)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;
if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (inputs < 0)
{
_abs_ = -inputs;
__putchar('-');
count++;
}
else
_abs_ = inputs;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;
return (count);
}
/**
* convert_number - converter function, a clone of itoa
* @num: number
* @bas: base
* @flag: argument flags
*
* Return: string
*/
char *convert_number(long int num, int bas, int flag)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flag & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';

array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do	{
*--ptr = array[n % base];
n /= bas;
} while (n != 0);
if (sign)
*--ptr = sign;
return (ptr);
}

/**
* remove_comments -  replaces first instance of '#' with '\0'
* @bufs: address of  string to modify
*
* Return: Always 0;
*/
void remove_comments(char *bufs)
{
int i;
for (i = 0; bufs[i] != '\0'; i++)
if (bufs[i] == '#' && (!i || bufs[i - 1] == ' '))
{
bufs[i] = '\0';
break;
}
}
