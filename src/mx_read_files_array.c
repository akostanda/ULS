#include "uls.h"

t_file **mx_read_files_array(DIR **dr, t_direntry **direntry,
char *path, unsigned int lenght) {
    t_file **files = mx_create_files_array(lenght);
    int i = 0;

    (*dr) = opendir((const char *)path);
    while (((*direntry) = readdir((*dr))) != NULL) {
        files[i] = mx_read_file(path, (*direntry)->d_name);
        i++;
    }
    closedir((*dr));
    return files;
}
