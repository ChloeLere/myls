/*
** EPITECH PROJECT, 2020
** my_ls_t
** File description:
** my_ls option
*/

#include "include/my.h"

void my_ls(struct dirent *sd, DIR *dir)
{
    char *name;

    while ((sd = readdir(dir)) != NULL) {
        name = sd->d_name;
        if (name[0] != '.')
            my_printf("%s\n", sd->d_name);
    }
}

void my_ls_l(struct dirent *sd, DIR *dir, char *namefile)
{
    struct stat buff;
    char *name;
    int t = 0;
    struct passwd *pwd;
    struct group *grp;

    find_nbr_total(namefile);
    while ((sd = readdir(dir)) != NULL) {
        name = sd->d_name;
        stat(name, &buff);
        if (name[0] != '.') {
            display(pwd, grp, buff, name);
        }
    }
}

void my_ls_r(struct dirent *sd, DIR *dir)
{
    char *name;
    struct stat buff;
    int c = 0;
    stat(".", &buff);
    char **tname = malloc(sizeof(char) * (buff.st_size + 1));

    while ((sd = readdir(dir)) != NULL) {
        name = sd->d_name;
        if (name[0] != '.') {
            tname[c] = malloc(sizeof(char *) * my_strlen(sd->d_name) + 1);
            tname[c] = name;
            c++;
        }
    }
    no_alpha_order(tname, buff.st_size, c);
    free(tname);
}

void my_ls_t(struct dirent *sd, DIR *dir, char *namefile)
{
    char *name;
    struct stat buff;
    int c = 0;
    stat(namefile, &buff);
    char **tname = malloc(sizeof(char) * (buff.st_size + 1));
    int *date;

    while ((sd = readdir(dir)) != NULL) {
        name = sd->d_name;
        if (name[0] != '.') {
            stat(name, &buff);
            tname[c] = malloc(sizeof(char *) * my_strlen(sd->d_name) + 1);
            tname[c] = name;
            my_printf("%d\n", buff.st_mtime);
            date[c] = buff.st_mtime;
            c++;
        }
    }
    time_order(date, tname, c);
    free(tname);
}
