/*
** EPITECH PROJECT, 2019
** q
** File description:
** q
*/

#include "../include/my.h"

void iteration(palin_t *pa)
{
    char *num = my_strcpy(pa->num_b);
    char *rnum = my_revstr(num);
    long nb;
    long a = convert_to_ten(num, pa->base);
    long b = convert_to_ten(rnum, pa->base);

    for (int i = 1; i <= pa->max; i++) {
        a = convert_to_ten(num, pa->base);
        b = convert_to_ten(rnum, pa->base);
        nb = a + b;
        num = base_changer(my_int_str(nb), pa->base);
        rnum = my_revstr(num);
        if (is_palindrome(num) == 0 && i >= pa->min) {
            if (nb >= 2147483647 || nb < 0)
                no_solution();
            printf("%ld leads to %ld in %d", pa->nb, nb, i);
            printf(" iteration(s) in base %d\n", pa->base);
            pa->sol = 1;
            return;
        }
    }
}

void iteration_p(palin_t *pa, int pnb)
{
    char *num = base_changer(my_int_str(pnb), pa->base);
    char *rnum = my_revstr(num);
    int nb;
    long a = convert_to_ten(num, pa->base);
    long b = convert_to_ten(rnum, pa->base);

    for (int i = 1; i <= pa->max; i++) {
        a = convert_to_ten(num, pa->base);
        b = convert_to_ten(rnum, pa->base);
        if ((nb = a + b) < 0)
            return;
        num = base_changer(my_int_str(nb), pa->base);
        rnum = my_revstr(num);
        if (nb == pa->nb && i >= pa->min) {
            printf("%d leads to %ld in %d", pnb, pa->nb, i);
            printf(" iteration(s) in base %d\n", pa->base);
            pa->sol = 1;
            return;
        }
    }
}

void my_palindrome_n(palin_t *pa)
{
    pa->nb = get_number(pa->num);
    pa->num_b = base_changer(pa->num, pa->base);
    pa->nb_b = get_number(pa->num_b);
    if (is_palindrome(pa->num_b) == 0 && pa->min == 0) {
        printf("%ld leads to ", pa->nb);
        printf("%ld in 0 iteration(s) in base %d\n", pa->nb, pa->base);
        exit(EXIT_SUCCESS);
    }
    iteration(pa);
    if (pa->sol == 0)
        printf("no solution\n");
}

void my_palindrome_p(palin_t *pa)
{
    pa->nb = get_number(pa->num);
    pa->num_b = base_changer(pa->num, pa->base);
    pa->nb_b = get_number(pa->num_b);
    if (pa->nb == 0) {
        printf("no solution\n");
        exit(0);
    }
    for (int i = 1; i <= pa->nb; i++) {
        iteration_p(pa, i);
    }
    if (pa->min == 0) {
        pa->sol = 1;
        printf("%ld leads to %ld in 0", pa->nb, pa->nb);
        printf(" iteration(s) in base %d\n", pa->base);
    }
    if (pa->sol == 0)
        printf("no solution\n");
}

void my_palindrome(palin_t *pa)
{
    if (pa->max < pa->min)
        error_message();
    if (pa->base > 10 || pa->base <= 1)
        error_message();
    if (pa->fn == 1) {
        my_palindrome_n(pa);
    } else if (pa->fp == 1) {
        if (is_palindrome(base_changer(pa->num, pa->base)) == 0)
            my_palindrome_p(pa);
        else
            error_message();
    }
}