/*
** EPITECH PROJECT, 2020
** my_ls_R
** File description:
** my_ls -R
*/

#include "include/my.h"

void my_ls_rr(struct dirent *sd, DIR *dir, char *name)
{
    struct stat buff;
    int c = 0;
    char *n;
    stat(sd->d_name, &buff);
    char **tab = malloc(sizeof(char *) * (buff.st_size + 1));
    my_printf("%s:\n", name);

    while ((sd = readdir(dir)) != NULL) {
        stat(sd->d_name, &buff);
        n = sd->d_name;
        if (n[0] != '.')
            my_printf("%s ", sd->d_name);
        if (n[0] != '.' && S_ISDIR (buff.st_mode)) {
            tab[c] = malloc(sizeof(char) * (buff.st_size));
            tab[c] = n;
            c++;
        }
    }
    my_printf("\n");
    transition(tab, c);
    free(tab);
}

int transition(char **tab, int c)
{
    int x = 0;

    if (c == 0)
        return (0);
    for (; x < c; x++)
        my_ls_rr2(tab[x]);
    return (0);
}

int my_ls_rr2(char *name)
{
    DIR *dir;
    struct dirent *sd;
    struct stat buff;
    stat(name, &buff);
    char **tab = malloc(sizeof(char *) * (buff.st_size + 1));
    int c = 0;

    dir = opendir(name);
    if (dir == NULL)
        return (84);
    my_printf("\n");
    my_ls_rr(sd, dir, name);
    transition(tab, c);
    closedir(dir);
    free(tab);
    return (0);
}
