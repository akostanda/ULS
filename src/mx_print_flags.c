#include "uls.h"

static void print_dirs_cycle(t_uls *uls, void (*function)(t_file **)) {
    int i;

    for (i = 0; uls->dirs[i]; i++) {
        if (uls->dirs[i + 1] || i > 0) {
            mx_printstr(uls->dirs[i]->path);
            mx_printstr(":\n");
        }
        function(uls->dirs[i]->files);
        if (uls->dirs[i + 1])
            mx_printstr("\n");
    }
}

static void print_dirs_flags(t_uls *uls) {
    if (uls->flags->def_dots && uls->flags->def_file_dots)
        print_dirs_cycle(uls, mx_print_allfile_detail);
    else if (uls->flags->def_file_dots)
        print_dirs_cycle(uls, mx_print_A_file_detail);
    else
        print_dirs_cycle(uls, mx_print_l_file_detail);
}

static void print_dirs_withoutflags(t_uls *uls) {
    if (uls->flags->def_dots && uls->flags->def_file_dots)
        print_dirs_cycle(uls, mx_print_allfile);
    else if (uls->flags->def_file_dots)
        print_dirs_cycle(uls, mx_print_A_file);
    else
        print_dirs_cycle(uls, mx_print_l_file);
}

void mx_print_flags(t_uls *uls) {
    if (uls->files) {
        if (uls->flags->detail)
            mx_print_file_detail(uls->files);
        else
            mx_print_allfile(uls->files);
        if (uls->dirs) {
            mx_printstr("\n");
            if (!uls->dirs[1]) {
                mx_printstr(uls->dirs[0]->path);
                mx_printstr(":\n");
            }
        }
    }
    if (uls->dirs) {
        if (uls->flags->detail)
            print_dirs_flags(uls);
        else
            print_dirs_withoutflags(uls);
    }
}
