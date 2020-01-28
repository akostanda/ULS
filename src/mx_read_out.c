#include "uls.h"

void mx_read_out(t_file *file, t_out *ip) {
    ip->nlink = mx_itoa(file->stat.st_nlink);
    ip->size = mx_itoa(file->stat.st_size);
    ip->gid = mx_itoa(file->gid);
}
