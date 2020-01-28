#include "uls.h"

unsigned int mx_count_in_dir(char *path) {
    t_direntry *direntry = NULL;
    DIR *dr = NULL;
    unsigned int lenght = 0;

    dr = opendir(path);
    while ((direntry = readdir(dr)) != NULL) {
        lenght++;
    }
    closedir(dr);
    return lenght;
}
