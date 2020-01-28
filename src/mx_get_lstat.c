#include "uls.h"

void mx_get_lstat(t_file *file, char *file_path) {
    int err = lstat(file_path, &(file->stat));

    // if (err < 0) {
    //     mx_printstr("%s: %s", file_path, strerror(errno));
    //     exit(1);
    // }
}
