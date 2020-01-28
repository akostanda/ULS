#include "uls.h"

static int longest_name(t_file **file, int *file_amount, int *openfile_amt) {
    int count = 0;
    int lenth = 0;

    for (int i = 0; file[i]; i++) {
       if (file[i]->name[0] != '.' || (file[i]->name[0] == '.'
            && file[i]->name[1] != '.' && mx_strlen(file[i]->name) != 1)) {
            lenth = strlen(file[i]->name);
            if (count < lenth)
                count = lenth;
            (*openfile_amt)++;
       }
       (*file_amount)++;
    }
    count = count + (8 - count % 8);
    return count;
}

void mx_print_A_file(t_file **file) {
    t_out *ip = mx_create_outnode();
    int count = longest_name(file, &ip->file_amount, &ip->openfile_amt);
    int index = ip->file_amount - ip->openfile_amt;

    ip->rows = mx_rows_amount(ip->openfile_amt, count, &ip->columns);
    mx_print_file_cycle(file, ip, index, count);
    mx_dealloc_out(ip);
}
