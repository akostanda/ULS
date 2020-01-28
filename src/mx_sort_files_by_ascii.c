#include "uls.h"

void mx_sortfiles_by_ascii(t_file **files, unsigned int lenght) {
    t_file *file = NULL;

    for (unsigned int y = 0; y < lenght - 1; y++) {
        for (unsigned int x = 0; x < lenght - y - 1; x++) {
            if (files[x] != NULL) {
                if (mx_strcmp(files[x]->name, files[x + 1]->name) > 0) {
                    file = files[x];
                    files[x] = files[x + 1];
                    files[x + 1] = file;
                }
            }
        }
    }
}
