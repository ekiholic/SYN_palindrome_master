/*
** EPITECH PROJECT, 2019
** s
** File description:
** s
*/

#include "../include/my.h"

int is_palindrome(char *str)
{
    char *rev = my_revstr(str);

    if (my_str_compare(rev, str) == 1)
        return (1);
    return (0);
}

char* my_revstr(char *src)
{
    int i = 0;
    int j = my_strlen(src);
    char *dest = malloc(sizeof(char) * 40);

    j = j - 1;
    while (j >= 0) {
        dest[i] = src[j];
        i += 1;
        j -= 1;
    }
    dest[i] = '\0';
    return (dest);
}

char *base_changer(char *str, int base)
{
    int i = 0;
    char *buff = malloc(sizeof(char) * 40);
    int nb = get_number(str);

    while (nb != 0) {
        buff[i] = (nb % base) + 48;
        nb = (nb - (nb % base)) / base;
        i++;
    }
    buff[i] = '\0';
    buff = my_revstr(buff);
    return (buff);
}

long convert_to_ten(char *str, int base)
{
    int i = 0;
    long nb = 0;

    while (str[i + 1] != '\0') {
        nb = (nb + (str[i] - 48)) * base;
        i++;
    }
    nb = nb + str[i] - 48;
    return (nb);
}

char *my_int_str(long nb)
{
    long x = 1;
    char *buff = malloc(sizeof(char) * 20);
    int i = 0;

    while ((x * 10) <= nb) {
        x = x * 10;
    }
    while (x != 0) {
        buff[i] = 48 + (nb / x);
        nb = nb % x;
        x = x / 10;
        i++;
    }
    buff[i] = '\0';
    return (buff);
}