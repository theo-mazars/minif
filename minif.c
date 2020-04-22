/*
** EPITECH PROJECT, 2019
** GITHUB_minif_2018
** File description:
** minif main functions file
*/

#include "minif.h"

static size_t print_list_char(va_list va)
{
    const int c = va_arg(va, int);

    return (write(1, &c, 1));
}

static size_t print_list_str(va_list va)
{
    const char * const str = va_arg(va, char *);
    size_t i = 0;

    if (str == NULL)
        return (write(1, "(nul)", 5));
    while (str[++i]);
    return (write(1, str, i));
}

static size_t print_list_number(va_list va)
{
    char c;
    int d = 1;
    size_t i = 0;
    int nb = va_arg(va, int);

    if (nb == -2147483648)
        return (write(1, "-2147483648", 11));
    if (nb < 0) {
        i += write(1, "-", 1);
        nb *= -1;
    }
    while ((nb / d) >= 10)
        d *= 10;
    while (d > 0) {
        c = (nb / d) % 10 + '0';
        i += write(1, &c, 1);
        d /= 10;
    }
    return (i);
}

static size_t print_list_unumber(va_list va)
{
    char c;
    size_t i = 0;
    unsigned int d = 1;
    const unsigned int nb = va_arg(va, unsigned int);

    while ((nb / d) >= 10)
        d *= 10;
    while (d > 0) {
        c = (nb / d) % 10 + '0';
        i += write(1, &c, 1);
        d /= 10;
    }
    return (i);
}

size_t minif(const char * const str, ...)
{
    va_list list;
    size_t j = 0;
    size_t len = 0;
    char l[] = {'c', 'd', 'i', 's', 'u', 0};
    ptr func[] = {&print_list_char, &print_list_number, &print_list_number,
        &print_list_str, &print_list_unumber};

    va_start(list, str);
    for (size_t i = 0; str[i]; i++)
        if (str[i] == '%') {
            while (str[++i] == ' ');
            for (j = 0; l[j] && str[i] != l[j]; j++);
            len += (!l[j]) ? (size_t) write(1, &str[i], 1) : func[j](list);
        } else
            len += write(1, str + i, 1);
    va_end(list);
    return (len);
}
