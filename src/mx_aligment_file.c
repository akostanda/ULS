#include "uls.h"

void mx_aligment_file(t_file **file, t_out *ip) {
    for (int i = 0; file[i]; i++) {
        mx_read_out(file[i], ip);
        if (ip->count_link < mx_strlen(ip->nlink))
            ip->count_link = mx_strlen(ip->nlink);
        if (ip->count_uname < mx_strlen(file[i]->username))
            ip->count_uname = mx_strlen(file[i]->username);
        if (file[i]->gr && ip->count_group < mx_strlen(file[i]->gr))
            ip->count_group = mx_strlen(file[i]->gr);
        else if (ip->count_group < mx_strlen(ip->gid))
            ip->count_group = mx_strlen(ip->gid);
        if (ip->count_size < (unsigned int)mx_strlen(ip->size))
            ip->count_size = mx_strlen(ip->size);
        if (file[i]->driver && ip->count_size < file[i]->driver->size)
            ip->count_size = file[i]->driver->size;
        if (ip->count_blocks < mx_strlen(ip->sblocks))
            ip->count_blocks = mx_strlen(ip->sblocks);
        ip->blocks = ip->blocks + file[i]->blocks;
        mx_clear_out(ip);
    }
}
