/*
** EPITECH PROJECT, 2019
** a
** File description:
** a
*/

#include "../include/my.h"

void my_help(void)
{
    printf("USAGE\n      ./palindrome -n number -p pal");
    printf("indrome [-b base] [-imin i] [-imax i]\n\nDESCRIPTION\n ");
    printf("     -n n      integer to be transformed (>=0)\n      -p pa");
    printf("l    palindromic number to be obtained (incompatible with the -n ");
    printf("option) (>=0)\n                if defined, all fitting values ");
    printf("of n will be output\n      -b base   base in which the");
    printf(" procedure will be executed (1<b<=10) [def: 10]\n      ");
    printf("-imin i   minimum number of iterations, included (>=0) [def: 0]\n");
    printf("      -imax i   maximum number of iterations, included (>=0) [de");
    printf("f: 100]\n");
}

void error_message(void)
{
    printf("invalid argument\n");
    exit(84);
}

void no_solution(void)
{
    printf("no solution\n");
    exit(0);
}

void my_init(palin_t *pa)
{
    pa->fn = 0;
    pa->fp = 0;
    pa->fmi = 0;
    pa->fma = 0;
    pa->fb = 0;
    pa->base = 10;
    pa->min = 0;
    pa->max = 100;
    pa->i = 1;
    pa->err = 0;
}

int main(int ac, char **av)
{
    palin_t pa;

    my_init(&pa);
    get_flag(&pa, ac, av);
    my_palindrome(&pa);
    return (0);
}