#include "uls.h"

static void print_rr(char *path, t_dir *dir, t_file *file, t_out *ip) {
    if (mx_strcmp(dir->path, "/\0") != 0) {
        path = mx_strjoin_path(dir->path, file->name, '/');
        mx_print_rrflag(path, ip->flags, file->name, ip);
        mx_strdel(&path);
    }
    else {
        path = mx_strjoin(dir->path, file->name);
        mx_print_rrflag(path, ip->flags, file->name, ip);
        mx_strdel(&path);
    }
}

void mx_print_rrflag_cycle(t_dir *dir, t_flags *flags, t_out *ip) {
    char *new_path = NULL;

    for (int i = 0; dir->files[i]; i++ ) {
        if (dir->files[i]->acl[0] == 'd') {
            if (flags->def_dots && flags->def_file_dots
                && mx_strcmp_unicode(".\0", dir->files[i]->name) == 0
                && !mx_strcmp_unicode("..\0", dir->files[i]->name)
                && mx_strlen_unicode(dir->files[i]->name) != 1) {
                print_rr(new_path, dir, dir->files[i], ip);
            }
            else if (flags->def_file_dots
                    && mx_aa_file_condition(dir->files[i]->name)) {
                print_rr(new_path, dir, dir->files[i], ip);
            }
            else if (dir->files[i]->name[0] != '.') {
                print_rr(new_path, dir, dir->files[i], ip);
            }
        }
    }
}
