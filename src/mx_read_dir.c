#include "uls.h"

t_dir *mx_read_dir(t_uls *uls, char *path) {
    t_dir *dir = mx_create_dir();
    t_direntry *direntry = NULL;
    DIR *dr = NULL;

    dir->path = mx_strdup(path);
    dir->lenght = mx_count_in_dir(path);
    dir->files = mx_read_files_array(&dr, &direntry, path, dir->lenght);
    mx_sortfiles_by_ascii(dir->files, dir->lenght);

    //SORT BY FLAGS FUNC
    //mx_sort_by_ascii(dir->files, dir->lenght);

    return dir;
}
