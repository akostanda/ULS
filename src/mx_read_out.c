#include "uls.h"

void mx_read_out(t_file *file, t_out *ip) {
    ip->nlink = mx_itoa(file->stat.st_nlink);
    if (ip->flags->f_h)
        ip->size = mx_gen_sizconstr(file->stat.st_size);
    else
        ip->size = mx_itoa(file->stat.st_size);
    ip->gid = mx_itoa(file->gid);
    ip->sblocks = mx_itoa(file->blocks);
}
