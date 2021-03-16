/*
** EPITECH PROJECT, 2020
** find_mode
** File description:
** use mode
*/

#include "include/my.h"

void find_chmod_owner(char *name, struct stat buff)
{
    stat(name, &buff);
    if (buff.st_mode & S_IRUSR)
        my_printf("r");
    else
        my_printf("-");
    if (buff.st_mode & S_IWUSR)
        my_printf("w");
    else
        my_printf("-");
    if (buff.st_mode & S_IXUSR)
        my_printf("x");
    else
        my_printf("-");
}

void find_chmod_group(mode_t m)
{
    if (S_IRGRP & m)
        my_printf("r");
    else
        my_printf("-");
    if (S_IWGRP & m)
        my_printf("w");
    else
        my_printf("-");
    if (S_IXGRP & m)
        my_printf("x");
    else
        my_printf("-");
}

void find_chmod_other(mode_t m)
{
    if (S_IROTH & m)
        my_printf("r");
    else
        my_printf("-");
    if (S_IWOTH & m)
        my_printf("w");
    else
        my_printf("-");
    if (S_IXOTH & m)
        my_printf("x");
    else
        my_printf("-");
}

void find_type(mode_t m)
{
    if (S_ISREG (m))
        my_printf ("-");
    if (S_ISBLK (m))
        my_printf("b");
    if (S_ISCHR (m))
        my_printf("c");
    if (S_ISDIR (m))
        my_printf("d");
    if (S_ISLNK (m))
        my_printf("l");
    if (S_ISFIFO (m))
        my_printf("p");
    if (S_ISSOCK (m))
        my_printf("s");
}
