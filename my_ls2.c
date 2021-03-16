/*
** EPITECH PROJECT, 2020
** my_ls2
** File description:
** other function for my_ls
*/

#include "include/my.h"

void disp_t(struct stat buff)
{
    int x = 3;
    char *t = ctime(&(buff.st_mtime));

    for (; x <= 15; x++)
        my_printf("%c", t[x]);
}

void display(struct passwd *pwd, struct group *grp, struct stat buff,
char *name)
{
    pwd = getpwuid(buff.st_uid);
    grp = getgrgid(buff.st_gid);
    find_type(buff.st_mode);
    find_chmod_owner(name, buff);
    find_chmod_group(buff.st_mode);
    find_chmod_other(buff.st_mode);
    my_printf(". %d %s", buff.st_nlink, pwd->pw_name);
    my_printf(" %s %d", grp->gr_name,  buff.st_size);
    disp_t(buff);
    my_printf(" %s\n", name);
}

void find_nbr_total(char *namefile)
{
    int total = 0;
    DIR *dirc;
    struct dirent *sdc;
    char *name;
    struct stat s;

    dirc = opendir(namefile);
    while ((sdc = readdir(dirc)) != NULL) {
        name = sdc->d_name;
        stat(name, &s);
        if (name[0] != '.')
            total += s.st_blocks / 2;
    }
    my_printf("total %d\n", total);
    closedir(dirc);
}
