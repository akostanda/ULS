#include "uls.h"

void mx_print_allfile_detail(t_file **file, t_flags *flags, t_out *ip) {
    time_t this_time = time(NULL);

    ip->flags = flags;
    mx_aligment_file(file, ip);
    mx_print_blocks(ip->blocks);
    for (int i = 0; file[i]; i++) {
        mx_read_out(file[i], ip);
        if (flags->f_s) {
            mx_left_s_aligment(ip->sblocks, ip->count_blocks);
            mx_printchar(' ');
        }
        mx_printstr(file[i]->acl);
        mx_left_aligment(ip->nlink, ip->count_link);
        mx_print_time_name_color(file[i], this_time, flags, ip);
        mx_clear_out(ip);
    }
    mx_zeroing_out(ip);
}
