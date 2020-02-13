#include "uls.h"

void mx_print_file_without_details(t_file **file, t_flags *flags, t_out *ip) {
    ip->count = mx_longest_name(file, &ip->file_amount, flags);
    ip->flags = flags;
    if (flags->f_s)
        mx_aligment_file(file, ip);
    ip->rows = mx_rows_amount(ip->file_amount, ip->count, &ip->columns, &ip);
    mx_print_file_without_details_cycle(file, ip);
    mx_zeroing_out(ip);
}
