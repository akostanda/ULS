#include "uls.h"

static int check_1st_flag(t_flags *flags, char flag) {
    if (flag == 'R')
        flags->f_rr = 1;
    else if (flag == 'A')
        flags->def_file_dots = 1;
    else if (flag == 'G')
        flags->f_gg = 1;
    else if (flag == 'C') {
        flags->f_cc = 1;
        flags->detail = 0;
        flags->f_1 = 0;
        flags->f_g = 0;
        flags->f_o = 0;
    }
    else if (flag == 'S') {
        flags->f_ss = 1;
        flags->f_t = 0;
    }
    else
        return 1;
    return 0;
}

int mx_check_upper_flag(t_flags *flags, char flag) {
    int fcheck = check_1st_flag(flags, flag);

    if (flag == 'T')
        flags->f_tt = 1;
    else if (flag == 'U') {
        flags->f_uu = 1;
        flags->f_u = 0;
        flags->f_c = 0;
    }
    else if (flag == '1') {
        flags->f_1 = 1;
        flags->detail = 0;
        flags->f_cc = 0;
        flags->f_m = 0;
        flags->f_g = 0;
        flags->f_o = 0;
    }
    else
        return fcheck;
    return 0;
}
