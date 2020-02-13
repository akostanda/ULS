#include "uls.h"

static void name_counter(char *name, int *count, int *lenth) {
    (*lenth) = mx_strlen_unicode(name);
     if ((*count) < (*lenth))
        (*count) = (*lenth);
}

int mx_longest_name(t_file **file, int *file_amount, t_flags *flags) {
    int count = 0;
    int lenth = 0;

    for (int i = 0; file[i]; i++) {
        name_counter(file[i]->name, &count, &lenth);
       (*file_amount)++;
    }
    if (flags->f_cc && isatty(1) == 0)
        return count;
    else if (flags->f_gg)
        count = count + 1;
    else
        count = count + (8 - count % 8);
    return count;
}
