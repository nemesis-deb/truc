/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-eloi.tisserand
** File description:
** my_hunter
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        i = i + 1;
    }
    return i;
}
