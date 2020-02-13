#include "uls.h"

static void print_dirs_cycle(t_uls *uls, void (*function)(t_file **,
t_flags *, t_out *), t_out *ip) {
    unsigned int i;

    for (i = 0; i < uls->dirs_count; i++) {
        if (uls->flags->print_empty_lines)
            mx_printstr("\n");
        if (uls->flags->print_pathes) {
            mx_printstr(uls->dirs[i]->path);
            mx_printstr(":\n");
        }
        if (uls->dirs[i]->permission)
            function(uls->dirs[i]->files, uls->flags, ip);
        else {
            mx_print_warning(MX_ERR_ULS, uls->dirs[i]->path, MX_ERR_PERMD);
            uls->flags->errtrig = 1;
        }
        uls->flags->print_pathes = 1;
        uls->flags->print_empty_lines = 1;
    }
}

static void print_file_flags(t_uls *uls, t_out *ip) {
    uls->flags->print_empty_lines = 1;
    uls->flags->print_pathes = 1;
    if (uls->flags->detail)
        mx_print_file_detail(uls->files, uls->flags, ip);
    else
        mx_print_file_without_details(uls->files, uls->flags, ip);
}


void mx_print_flags(t_uls *uls, t_out *ip) {
    ip->flags = uls->flags;
    if (uls->files)
        print_file_flags(uls, ip);
    if (uls->dirs) {
        if (uls->dirs_count > 1)
            uls->flags->print_pathes = 1;
        if (uls->flags->f_rr) {
            for (unsigned int i = 0; i < uls->dirs_count; i++)
                mx_print_rrflag(uls->dirs[i]->path, uls->flags,
                                uls->dirs[i]->path, ip);
        }
        else if (uls->flags->detail)
            print_dirs_cycle(uls, mx_print_allfile_detail, ip);
        else
            print_dirs_cycle(uls, mx_print_file_without_details, ip);
    }
    mx_zeroing_out(ip);
}
