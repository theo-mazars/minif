/*
** EPITECH PROJECT, 2019
** GITHUB_minif_2018
** File description:
** minif main functions file
*/

#include "minif.h"

size_t my_putchar_list(va_list va)
{
    char c = va_arg(va, int);
    return (write(1, &c, 1));
}

size_t my_putstr_list(va_list va)
{
    char *str = va_arg(va, char *);
    size_t i = 0;

    if (str == NULL)
        return (write(1, "(nul)", 5));
    while (str[++i]);
    return (write(1, str, i));
}

size_t my_putnbr_list(va_list va)
{
    char c = 0;
    size_t i = 0;
    int d = 1;
    int nb = va_arg(va, int);

    if (nb == -2147483648)
        return (write(1, "-2147483648", 11));
    if (nb < 0) {
        i += write(1, "-", 1);
        nb *= -1;
    }
    while ((nb / d) >= 10)
        d *= 10;
    for (; d > 0; i++, d /= 10) {
        c = (nb / d) % 10 + '0';
        write(1, &c, 1);
    }
    return (i);
}

size_t my_putunbr_list(va_list va)
{
    unsigned int nb = va_arg(va, unsigned int);
    char c = 0;
    unsigned int d = 1;
    size_t i = 0;

    while ((nb / d) >= 10)
        d *= 10;
    while (d > 0) {
        c = (nb / d) % 10 + '0';
        write(1, &c, 1);
        d /= 10;
        i++;
    }
    return (i);
}

size_t minif(char *str, ...)
{
    va_list list;
    size_t j = 0;
    size_t nb = 0;
    char l[] = {'c', 'd', 'i', 's', 'u', 0};
    ptr functions[] = {&my_putchar_list, &my_putnbr_list, &my_putnbr_list,
        &my_putstr_list, &my_putunbr_list};

    va_start(list, str);
    for (size_t i = 0; str[i]; i++)
        if (str[i] == '%') {
            i++;
            for (; str[i] == ' '; i++);
            for (j = 0; l[j] && str[i] != l[j]; j++);
            nb += (!l[j]) ? (size_t) write(1, &str[i], 1) : functions[j](list);
        } else
            nb += write(1, &str[i], 1);
    va_end(list);
    return (nb);
}