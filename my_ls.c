/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** main my_ls
*/

#include "include/my.h"

int opend(char *namefile, char **argv, int nb)
{
    DIR *dir;
    struct dirent *sd;
    int c = 1;

    dir = opendir(namefile);
    if (dir == NULL) {
        write(2, "Error", 6);
        return (84);
    }
    if (nb == 1) {
        my_ls(sd, dir);
        closedir(dir);
        return (0);
    }
    find_flag(argv, namefile, sd, dir);
    closedir(dir);
    return (0);
}

void find_flag(char **argv, char *namefile, struct dirent *sd, DIR *dir)
{
    int c = 1;

    if (argv[c][0] == '-') {
        if (argv[c][1] == 'l')
            my_ls_l(sd, dir, namefile);
        if (argv[c][1] == 'R')
            my_ls_rr(sd, dir, namefile);
        if (argv[c][1] == 'd')
            my_printf("%s\n", namefile);
        if (argv[c][1] == 'r')
            my_printf("r\n");
        if (argv[c][1] == 't')
            my_printf("t\n");
        if (argv[c][1] == 'a')
            my_ls_a(sd, dir);
        if (argv[c][1] == 's')
            my_ls_s(sd, dir, namefile);
    }
}

int error_letter(char **argv)
{
    char l = argv[1][1];

    if (argv[1][0] == '-') {
        if (argv[1][1] != 'l' && argv[1][1] != 'R'
            && argv[1][1] != 'd' && argv[1][1] != 'r' && argv[1][1] != 't'
            && argv[1][1] != 'a' && argv[1][1] != 's') {
            write(2, "invalid option\n", 16);
            return (1);
        }
    }
    return (0);
}

int argc_c(int argc, char **argv, int c)
{
    if (c == argc) {
        opend(".", argv, c);
        return (0);
    } else {
        opend(argv[c], argv, c);
        return (0);
    }
}

int main(int argc, char **argv)
{
    int c = 1;

    if (argc == 1) {
        opend(".", argv, c);
        return (0);
    } else {
        if (argv[c][0] == '-');
        c++;
    }
    if (error_letter(argv) == 1)
        return (84);
    if (c == argc && argv[1][0] != '-') {
        opend(argv[1], argv, 1);
        return (0);
    }
    argc_c(argc, argv, c);
    return (0);
}
