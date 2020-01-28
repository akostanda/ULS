#include "uls.h"

static void aligment_file(t_file **file, t_out *ip) {
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
        ip->blocks = ip->blocks + file[i]->blocks;
        mx_clear_out(ip);
    }
}

void mx_print_allfile_detail(t_file **file) {
    t_out *ip = mx_create_outnode();
    time_t this_time = time(NULL);

    aligment_file(file, ip);
    mx_print_blocks(ip->blocks);
    for (int i = 0; file[i]; i++) {
        mx_printstr(file[i]->acl);
        mx_read_out(file[i], ip);
        mx_left_aligment(ip->nlink, ip->count_link);
        mx_right_alt(file[i]->username, ip->count_uname);
        mx_right_alt(file[i]->gr ? file[i]->gr : ip->gid, ip->count_group);
        if (file[i]->driver)
            mx_left_aligment(file[i]->driver->driver, ip->count_size);
        else
            mx_left_aligment(ip->size, ip->count_size);
        mx_print_time(file[i], this_time);
        mx_clear_out(ip);
    }
    mx_dealloc_out(ip);
}
