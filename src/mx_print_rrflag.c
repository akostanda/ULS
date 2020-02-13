#include "uls.h"

static int print_dirs_cycle(t_dir *dir, void (*function)(t_file **, t_flags *,
                            t_out *), t_flags *flags, t_out *ip) {
    int result = 0;

    if (flags->print_empty_lines)
        mx_printstr("\n");
    if (flags->print_pathes) {
        mx_printstr(dir->path);
        mx_printstr(":\n");
    }
    if (dir->permission)
        function(dir->files, flags, ip);
    else {
        mx_print_warning(MX_ERR_ULS, ip->name, MX_ERR_PERMD);
        flags->errtrig = 1;
        result = 1;
    }
    mx_strdel(&ip->name);
    flags->print_pathes = 1;
    flags->print_empty_lines = 1;
    return result;
}

void mx_print_rrflag(char *path, t_flags *flags, char *name, t_out *ip) {
    t_dir *dir = mx_read_dir(flags, path, ip);
    int result = 0;

    ip->name = mx_strdup(name);
    if (flags->detail)
        result = print_dirs_cycle(dir, mx_print_allfile_detail, flags, ip);
    else
        result = print_dirs_cycle
                 (dir, mx_print_file_without_details, flags, ip);
    if (!result)
        mx_print_rrflag_cycle(dir, flags, ip);
    mx_dealloc_dir(&dir);
}
