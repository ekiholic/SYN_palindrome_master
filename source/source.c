/*
** EPITECH PROJECT, 2019
** q
** File description:
** q
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *my_strcpy(char *src)
{
    char *buff = malloc(sizeof(char) * 20);
    int i = 0;

    while (src[i] != '\0') {
        buff[i] = src[i];
        i += 1;
    }
    buff[i] = '\0';
    return (buff);
}

int my_str_compare(char *src, char *str)
{
    int i = 0;
    int a = my_strlen(src);
    int b = my_strlen(str);

    if (a != b)
        return (1);
    while (str[i] != '\0' && src[i] != '\0') {
        if (str[i] != src[i])
            return (1);
        i += 1;
    }
    return (0);
}

long get_number(char *str)
{
    int i = 0;
    long nb = 0;
    int minus = 1;
    int c = 0;

    if (str[0] < '0' && str[0] > '9') {
        return (-1);}
    while (str[i] != '\0') {
        if (str[i] == 45 && c == 0) {
            minus = minus * -1;
        }
        if (str[i] >= 48 && str[i] <= 57) {
            nb = (nb * 10) + (str[i] - 48);
            c = 1;
        } else if (nb >= 0 && c == 1) {
            return (nb * minus);
        }
        i = i + 1;
    }
    return (nb * minus);
}

int is_num(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        i++;
    }
    return (0);
}