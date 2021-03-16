/*
** EPITECH PROJECT, 2020
** my_ls_t
** File description:
** my_ls option
*/

#include "include/my.h"

void my_ls_a(struct dirent *sd, DIR *dir)
{
    while ((sd = readdir(dir)) != NULL)
        my_printf("%s\n", sd->d_name);
}

void my_ls_s(struct dirent *sd, DIR *dir, char *namefile)
{
    struct stat buff;
    char *name;
    int t = 0;
    find_nbr_total(namefile);

    while ((sd = readdir(dir)) != NULL) {
        name = sd->d_name;
        stat(name, &buff);
        if (name[0] != '.') {
            my_printf(" %d %s", buff.st_blocks / 2, sd->d_name);
        }
    }
    my_printf("\n");
}
