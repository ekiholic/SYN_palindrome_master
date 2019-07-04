/*
** EPITECH PROJECT, 2019
** a
** File description:
** a
*/

#include <stdlib.h>

int my_factrec_synthesis(int nb)
{
    int res = 1;

    if (nb < 0 || nb > 12)
        return (0);
    if (nb == 0 || nb == 1)
        return (1);
    res = nb * my_factrec_synthesis(nb - 1);
    return (res);
}

int my_squareroot_synthesis(int nb)
{
    int res;

    if (nb < 0)
        return (-1);
    if (nb == 0 || nb == 1)
        return (nb);
    for (int i = 0; i <= nb; i++) {
        res = i * i;
        if (res == nb)
            return (i);
    }
    return (-1);
}