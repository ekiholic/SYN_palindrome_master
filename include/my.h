/*
** EPITECH PROJECT, 2019
** q
** File description:
** q
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct palin_s {
    char *num;
    char *num_b;
    long nb;
    long nb_b;
    int fn;
    int fp;
    int fmi;
    int fma;
    int fb;
    int base;
    int min;
    int max;
    int i;
    int err;
    int sol;
} palin_t;

void my_help(void);
void my_init(palin_t *pa);
void error_message(void);
void no_solution(void);

char *my_strcpy(char *src);
int my_str_compare(char *src, char *str);
long get_number(char *str);
int my_strlen(char *str);
int is_num(char *str);
int is_palindrome(char *str);
char *my_revstr(char *str);
char *base_changer(char *str, int base);
long convert_to_ten(char *str, int base);
char *my_int_str(long nb);

void get_flag(palin_t *pa, int ac, char **av);
int get_flag2(palin_t *pa, char **av);
int get_flag3(palin_t *pa, char **av);
int get_flag4(palin_t *pa, char **av);

void my_palindrome(palin_t *sb);
void my_palindrome_p(palin_t *pa);
void my_palindrome_n(palin_t *pa);
void iteration(palin_t *pa);
void iteration_p(palin_t *pa, int pnb);

#endif