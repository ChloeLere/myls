/*
** EPITECH PROJECT, 2020
** bsprintf
** File description:
** static library
*/

#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int argc_c(int argc, char **argv, int c);
int my_printf(char *s, ...);
int edit_add(char *str, va_list argv, int add);
int space_or_plus(char str, va_list argv, int add);
void display_all_char (char *str);
int add_zero_or_space_int(char *str, va_list argv, int add);
void check_string(char *type, va_list argv);
void check_int(char *type, va_list argv);
void check_char(char *type, va_list argv);
int check_other(char *type, va_list argv);
void convert(va_list argv, int base);
void convert_hexa_lower(va_list argv);
void convert_hexa_upper(va_list argv);
void my_putchar(char c);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr_pr(int nb);
void my_put_nbr_oct(int nb);
void my_put_nbr_uns(unsigned int nb);
void my_put_nbr_long(long nb);
double my_put_float(double nbr);
void my_put_short(short nb);
void display_p(char *str, va_list argv);
int add_zero_or_space(char *str, va_list argv, int add);
void space_char(va_list argv, int nbr);
void zero_or_space_int(char str, va_list argv, int nb_z);
int my_getnbr_with_i (char const *str, int i);
int my_nbrlen(int str);
void convert_hexa_lower_int(int nbr, va_list argv);
void convert_hexa_lower_long(unsigned long nbr, va_list argv);
void disp_t(struct stat buff);
void display(struct passwd *pwd, struct group *grp,
struct stat buff, char *name);
void find_nbr_total(char *namefile);
int opend(char *namefile, char **argv, int nb);
void find_flag(char **argv, char *namefile, struct dirent *sd, DIR *dir);
void no_alpha_order(char **name, off_t size, int nbr);
void swap_char(char **name , int  index1 , int  index2);
void my_ls(struct dirent *sd, DIR *dir);
void my_ls_l(struct dirent *sd, DIR *dir, char *namefile);
void my_ls_rr(struct dirent *sd, DIR *dir, char *name);
int transition(char **tab, int c);
int my_ls_rr2(char *name);
void my_ls_r(struct dirent *sd, DIR *dir) ;
void my_ls_t(struct dirent *sd, DIR *dir, char *namefile);
void time_order(int *date, char **name, int nbr);
void swap_nb(int *nbr, int  index1 , int  index2, char **name);
void my_ls_a(struct dirent *sd, DIR *dir);
void my_ls_s(struct dirent *sd, DIR *dir, char *namefile);
void find_chmod_owner(char *name, struct stat buff);
void find_chmod_group(mode_t m);
void find_chmod_other(mode_t m);
void find_type(mode_t m);

typedef struct element element_t;

typedef struct element
{
    char flag;
    element_t *next;
}element_t;

typedef struct list
{
    element_t *first;
}list_t;
