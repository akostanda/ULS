#include "uls.h"

t_flags *mx_create_flags() {
    t_flags *flags = (t_flags *)malloc(sizeof(t_flags));

    flags->f_R = 0;
    flags->detail = 0;
    flags->def_dots = 0;
    flags->def_file_dots = 0;
    flags->first_out = 1;
    return flags;
}
