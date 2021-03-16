/*
** EPITECH PROJECT, 2020
** orga
** File description:
** my_ls
*/

#include "include/my.h"

void no_alpha_order(char **name, off_t size, int nbr)
{
    int temp = nbr;
    int x = 0;
    int c = 0;
    int i = 0;

    for (; x <= temp; x++) {
        for (c = 0, nbr = temp; size > 0; nbr--, c++) {
            if (name[c][0] > name[c + 1][0]) {
                my_printf("\n%s, %s\n", name[c], name[c + 1]);
                swap_char(name, c, c + 1);
            }
        }
    }
    for (; i < temp; i++)
        my_printf("%s\n", name[i]);
}

void swap_char(char **name , int  index1 , int  index2)
{
    int c1 = my_strlen(name[index1]);
    int c2 = my_strlen(name[index2]);
    int x = 0;
    char **temp = malloc(sizeof(char) + 2);

    for (; x < c1; x++) {
        temp[0] = malloc(sizeof(char *) + (c1 + 1));
        temp[0][x] = name[index1][x];
    }
    temp[0][x + 1] = '\0';
    for (x = 0; x < c2; x++) {
    name[index1][x] = name[index2][x];
    }
    for (x = 0; x < c2; x++) {
    name[index2][x] = temp[0][x];
    }
    my_printf("\n%s, %s , %d\n", name[index1], name[index2], 15);
    free(temp);
}

void swap_nb(int *nbr, int  index1 , int  index2, char **name)
{
    int c1 = my_strlen(name[index1]);
    int c2 = my_strlen(name[index2]);
    char **tempch = malloc(sizeof(char) + 2);
    int x = 0;
    int temp = nbr[index1];

    nbr[index1] = nbr[index2];
    for (nbr[index2] = temp; x < c1; x++) {
        tempch[0] = malloc(sizeof(char *) + (c1 + 1));
        tempch[0][x] = name[index1][x];
    }
    tempch[0][x + 1] = '\0';
    for (x = 0; x < c2; x++) {
        name[index1][x] = name[index2][x];
    }
    for (x = 0; x < c2; x++) {
        name[index2][x] = tempch[0][x];
    }
    my_printf("\n%s, %s , %d\n", name[index1], name[index2], 15);
    free(tempch);
}

void time_order(int *date, char **name, int nbr)
{
    int temp = nbr;
    int x = 0;
    int c = 0;
    int i = 0;

    for (; x <= temp; x++) {
        for (c = 0, nbr = temp; nbr > 0; nbr--, c++) {
            if (date[c] > date[c + 1]) {
                swap_nb(date, c, c + 1, name);
            }
        }
    }
    for (; i < temp; i++)
        my_printf("%s\n", name[i]);
}