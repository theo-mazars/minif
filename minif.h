/*
** EPITECH PROJECT, 2019
** GITHUB_minif_2018
** File description:
** minif
*/

#ifndef MINIF_H_
#define MINIF_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef size_t (*ptr)(va_list);

size_t minif(char *, ...);
#endif /* MINIF_H_ */
