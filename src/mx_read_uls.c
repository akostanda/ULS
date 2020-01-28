#include "uls.h"

static void read_ever(t_uls *uls, int argc, char **argv) {
    int res = 0;
    int d = 0;
    int f = 0;
    char *file_path = NULL;

    for (int i = 1; i < argc; i++) {
        res = mx_check_is_folder(argv[i]);
        if (res == 1) {
            uls->dirs[d] = mx_read_dir(uls, argv[i]);
            d++;
        }
        if (res == 0) {
            if (argv[i][0] == '/')
                uls->files[f] = mx_read_file("/", argv[i]);
            else
                uls->files[f] = mx_read_file("./", argv[i]);
            f++;
        }
    }
}

static void count_ever(t_uls *uls, int argc, char **argv) {
    int res = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || mx_strcmp("-\0", argv[i]) == 0) {
            res = mx_check_is_folder(argv[i]);
            if (res == 1)
                uls->dirs_count++;
            if (res == 0)
                uls->files_count++;
            if (res == -1) {
                mx_print_warning(ERROR_ULS, argv[i], ERROR_NSFOD);
                uls->flags->first_out = 0;
            }
        }
    }
}

void mx_read_uls(t_uls *uls, int argc, char **argv) {
    mx_read_flags(uls, argc, argv);
    count_ever(uls, argc, argv);
    if (uls->files_count == 0
        && uls->dirs_count == 0
        && uls->flags->first_out) {
        uls->dirs = mx_create_dirs_array(1);
        uls->dirs[0] = mx_read_dir(uls, ".");
        return ;
    }
    uls->files = mx_create_files_array(uls->files_count);
    uls->dirs = mx_create_dirs_array(uls->dirs_count);
    read_ever(uls, argc, argv);
    if (uls->files)
        mx_sortfiles_by_ascii(uls->files, uls->files_count);
    if (uls->dirs)
        mx_sortdirs_by_ascii(uls->dirs, uls->dirs_count);
}
