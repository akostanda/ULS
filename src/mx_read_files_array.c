#include "uls.h"

static void read_cycle(t_file **files, t_direntry **direntry, char *path,
                       t_out *ip) {
    if (ip->flags->def_file_dots && ip->flags->def_dots) {
        files[ip->i] = mx_read_file(path, (*direntry)->d_name, ip->flags);
        ip->i++;
    }
    else if (ip->flags->def_file_dots
            && mx_aa_file_condition((*direntry)->d_name)) {
        files[ip->i] = mx_read_file(path, (*direntry)->d_name, ip->flags);
        ip->i++;
    }
    else if ((*direntry)->d_name[0] != '.') {
        files[ip->i] = mx_read_file(path, (*direntry)->d_name, ip->flags);
        ip->i++;
    }
}

t_file **mx_read_files_array(DIR **dr, t_direntry **direntry, char *path,
                             t_out *ip) {
    t_file **files = mx_create_files_array(ip->lenght);
    ip->i = 0;

    if (!files)
        return NULL;
    (*dr) = opendir((const char *)path);
    if (!(*dr)) {
        mx_dealloc_files(&files);
        return NULL;
    }
    while (((*direntry) = readdir((*dr))) != NULL) {
        read_cycle(files, direntry, path, ip);
    }
    ip->i = 0;
    closedir((*dr));
    return files;
}
