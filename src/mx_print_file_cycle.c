#include "uls.h"

static int tab_amount(char *str, int size) {
    int lenth = mx_strlen(str);
    int tab_count = 0;

    tab_count = size / 8 - lenth / 8;
    return tab_count;
}

void mx_print_file_cycle(t_file **file, t_out *ip, int index, int count) {
    int tab = 0;
    int c_index = index;
    int newct = 0;

    for (ip->i = 0; ip->i < ip->rows; ip->i++) {
        for (ip->j = 0; file[c_index + ip->i]; ip->j++, c_index++) {
            if (ip->j % ip->rows == 0 && file[c_index + ip->i]) {
                newct++;
                tab = tab_amount(file[c_index + ip->i]->name, count);
                mx_printstr(file[c_index + ip->i]->name);
                if (file[c_index + ip->i + ip->rows] && newct != ip->columns) {
                    for (ip->k = 0; ip->k < tab; ip->k++)
                        mx_printstr("\t");
                }
            }
        }
        newct = 0;
        c_index = index;
        mx_printstr("\n");
    }
}
