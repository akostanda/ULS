#include "uls.h"

unsigned int mx_get_minor(t_file *file) {
    unsigned int major = MINOR(file->stat.st_rdev);

    return major;
}
