#include "uls.h"

static void print_dirs_cycle(t_dir **dirs, void (*function)(t_file **)) {
    int i;

    for (i = 0; dirs[i]; i++) {
        if (dirs[i + 1] || i > 0) {
            mx_printstr(dirs[i]->path);
            mx_printstr(":\n");
        }
        function(dirs[i]->files);
        if (dirs[i + 1])
            mx_printstr("\n");
    }
}

static void print_dirs_flags(t_dir **dirs, t_flags *flags) {
    if (flags->def_dots && flags->def_file_dots)
        print_dirs_cycle(dirs, mx_print_allfile_detail);
    else if (flags->def_file_dots)
        print_dirs_cycle(dirs, mx_print_A_file_detail);
    else
        print_dirs_cycle(dirs, mx_print_l_file_detail);
}

static void print_dirs_withoutflags(t_dir **dirs, t_flags *flags) {
    if (flags->def_dots && flags->def_file_dots)
        print_dirs_cycle(dirs, mx_print_allfile);
    else if (flags->def_file_dots)
        print_dirs_cycle(dirs, mx_print_A_file);
    else
        print_dirs_cycle(dirs, mx_print_l_file);
}

void mx_print_Rflag_files(t_dir **dirs, t_flags *flags) {
    
  
            if (flags->detail)
                print_dirs_flags(dirs, flags);
            else
                print_dirs_withoutflags(dirs, flags);
    for (int i = 0; dirs[i]; i++ ) {
        for (int j = 0; dirs[i]->files[j]; j++)
        if (dirs[i]->files->acl)
    }
}
