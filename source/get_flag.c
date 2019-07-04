/*
** EPITECH PROJECT, 2019
** f
** File description:
** f
*/

#include "../include/my.h"

int get_flag4(palin_t *pa, char **av)
{
    if (my_str_compare("-imax", av[pa->i]) == 0) {
        if (is_num(av[pa->i + 1]) == 0 && pa->fma == 0) {
            pa->max = get_number(av[pa->i + 1]);
            pa->i++;
            pa->fma = 1;
            return (0);
        } else
            return (1);
    }
    return (1);
}

int get_flag3(palin_t *pa, char **av)
{
    if (my_str_compare("-b", av[pa->i]) == 0) {
        if (is_num(av[pa->i + 1]) == 0 && pa->fb == 0) {
            pa->base = get_number(av[pa->i + 1]);
            pa->fb = 1;
            pa->i++;
            return (0);
        } else
            return (1);
    }
    if (my_str_compare("-imin", av[pa->i]) == 0) {
        if (is_num(av[pa->i + 1]) == 0 && pa->fmi == 0) {
            pa->min = get_number(av[pa->i + 1]);
            pa->fmi = 1;
            pa->i++;
            return (0);
        } else
            return (1);
    }
    return (get_flag4(pa, av));
}

int get_flag2(palin_t *pa, char **av)
{
    if (my_str_compare("-n", av[pa->i]) == 0) {
        if (is_num(av[pa->i + 1]) == 0) {
            pa->num = my_strcpy(av[pa->i + 1]);
            pa->fn = 1;
            pa->i++;
            return (0);
        } else
            return (1);}
    if (my_str_compare("-p", av[pa->i]) == 0) {
        if (is_num(av[pa->i + 1]) == 0) {
            pa->num = my_strcpy(av[pa->i + 1]);
            pa->fp = 1;
            pa->i++;
            return (0);
        } else
            return (1);
    }
    return (get_flag3(pa, av));
}

void get_flag(palin_t *pa, int ac, char **av)
{
    if (ac == 1 || ac > 9)
        exit(84);
    if (ac == 2) {
        if (my_str_compare("-h", av[1]) == 0) {
            my_help();
            exit(EXIT_SUCCESS);
        } else {
            exit(84);
        }
    }
    if ((ac % 2) != 1)
        error_message();
    while (pa->i < ac - 1) {
        if ((pa->err = get_flag2(pa, av)) == 1)
            error_message();
        pa->i++;
    }
    if (pa->fn == 1 && pa->fp == 1)
        exit(84);
}