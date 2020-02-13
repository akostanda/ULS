#include "uls.h"

void mx_zeroing_out(t_out *ip) {
    ip->count_link = 0;
    ip->count_uname = 0;
    ip->count_group = 0;
    ip->count_size = 0;
    ip->count_blocks = 0;
    ip->blocks = 0;
    ip->screen_size = 0;
    ip->lenght = 0;
    ip->count = 0;
    ip->i = 0;
    ip->j = 0;
    ip->rows = 0;
    ip->file_amount = 0;
}
