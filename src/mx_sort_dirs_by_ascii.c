#include "uls.h"

void mx_sortdirs_by_ascii(t_dir **dirs, unsigned int lenght) {
    t_dir *dir = NULL;

    for (unsigned int y = 0; y < lenght - 1; y++) {
        for (unsigned int x = 0; x < lenght - y - 1; x++) {
            if (dirs[x] != NULL) {
                if (mx_strcmp(dirs[x]->path, dirs[x + 1]->path) > 0) {
                    dir = dirs[x];
                    dirs[x] = dirs[x + 1];
                    dirs[x + 1] = dir;
                }
            }
        }
    }
}
