#include "uls.h"

static void flags_init_01(t_flags *flags) {
    flags->f_cc = 0;
    flags->f_gg = 0;
    flags->f_rr = 0;
    flags->f_ss = 0;
    flags->f_tt = 0;
    flags->f_c = 0;
    flags->f_f = 0;
    flags->f_h = 0;
    flags->f_g = 0;
    flags->f_m = 0;
    flags->f_o = 0;
    flags->f_q = 0;
    flags->f_r = 0;
    flags->f_t = 0;
    flags->f_u = 0;
    flags->f_s = 0;
    flags->f_1 = 0;
    flags->detail = 0;
    flags->def_dots = 0;
}

static void flags_init_02(t_flags *flags) {
    flags->def_file_dots = 0;
    flags->print_empty_lines = 0;
    flags->print_pathes = 0;
    flags->r_fd_only = 0;
    flags->errtrig = 0;
}

t_flags *mx_create_flags() {
    t_flags *flags = (t_flags *)malloc(sizeof(t_flags));

    flags_init_01(flags);
    flags_init_02(flags);
    return flags;
}
