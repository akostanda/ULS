#include "uls.h"

static void tab_print(int tab, t_out *ip) {
    for (ip->k = 0; ip->k < tab; ip->k++)
        mx_printstr("\t");
}

static void space_print(int space, t_out *ip) {
    for (ip->k = 0; ip->k < space; ip->k++)
        mx_printstr(" ");
}

void mx_print_file_cond(char *name, char *acl, t_out *ip, int newct) {
    int tab = 0;
    int space = 0;

    if (ip->flags->f_gg && isatty(1) != 0) {
        space = mx_space_amount(name, ip->count);
        mx_print_gg(name, acl);
        if (ip->j + ip->i + ip->rows < ip->file_amount && ip->flags->f_1 != 1)
            space_print(space, ip);
    }
    else {
        tab = mx_tab_amount(name, ip->count);
        mx_printstr(name);
        if (ip->j + ip->i + ip->rows < ip->file_amount
            && newct != ip->columns && ip->flags->f_1 != 1) {
            tab_print(tab, ip);
        }
    }
}

void mx_print_file_without_details_cycle(t_file **file, t_out *ip) {
    int newct = 0;

    if (ip->flags->f_m) {
        mx_print_m_cycle(file, ip);
    }
    else {
        for (ip->i = 0; ip->i < ip->rows; ip->i++) {
            for (ip->j = 0; file[ip->j + ip->i]; ip->j++) {
                if (ip->j % ip->rows == 0 && file[ip->j + ip->i]) {
                    newct++;
                    mx_print_file_cond(file[ip->j + ip->i]->name, 
                                        file[ip->j + ip->i]->acl, ip, newct);
                }
            }
        newct = 0;
        mx_printstr("\n");
        }
    }
}
