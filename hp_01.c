#include "simple_shell.h"

/**
 * str_cmp - compare two strings
 * @first: first string to be compared
 * @second: second string to be compared
 *
 * Return: difference of the two strings
 */
int str_cmp(char *first, char *second)
{
    int i = 0;

    while (first[i] != '\0')
    {
        if (first[i] != second[i])
            break;
        i++;
    }
    return (first[i] - second[i]);
}

/**
 * str_cat - concatenates two strings
 * @destination: string to be concatenated to
 * @source:  string to concatenate
 *
 * Return: address of the new string
 */
char *str_cat(char *dest, char *src)
{
    char *new_str =  NULL;
    int len_dest = _strlen(dest);
    int len_source = _strlen(src);

    new_string = malloc(sizeof(*new_str) * (len_dest + len_source + 1));
    str_cpy(dest, new_str);
    str_cpy(src, new_str + len_dest);
    new_str[len_dest + len_source] = '\0';
    return (new_str);
}

/**
 * str_spn - gets the length of a prefix substring
 * @str_1: string to be searched
 * @str_2: string to be used
 *
 * Return: number of bytes in the initial segment of 5 which are part of accept
 */
int str_spn(char *str_1, char *str_2)
{
    int i = 0;
    int match = 0;

    while (str_1[i] != '\0')
    {
        if (str_chr(str_2, str_1[i]) == NULL)
            break;
        match++;
        i++;
    }
    return (match);
}

/**
 * str_c_spn - computes segment of str_1 which consists of characters not in str_2
 * @str_1: string to be searched
 * @str_2: string to be used
 *
 * Return: index at which a char in str_1 exists in str_2
 */
int str_c_spn(char *str_1, char *str_2)
{
    int len = 0, i;

    for (i = 0; str_1[i] != '\0'; i++)
    {
        if (_strchr(str_2, str_1[i]) != NULL)
            break;
        len++;
    }
    return (len);
}

/**
 * str_chr - locates a char in a string
 * @s: string to be searched
 * @c: char to be checked
 *
 * Return: pointer to the first occurence of c in s
 */
char *str_chr(char *s, char c)
{
    int i = 0;

    for (; s[i] != c && s[i] != '\0'; i++)
        ;
    if (s[i] == c)
        return (s + i);
    else
        return (NULL);
}
