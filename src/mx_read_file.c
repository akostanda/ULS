#include "uls.h"

static char *correct_file_path(t_file *file, char *path) {
    char *pwd = mx_strjoin(path, "/");
    char *ffp = mx_strjoin(pwd, file->name);

    mx_strdel(&pwd);
    return ffp;
}

t_file *mx_read_file(char *file_path, char *file_name) {
    t_file *file = mx_create_file();
    char *ffp = NULL;

    file->name = mx_strdup(file_name);
    ffp = correct_file_path(file, file_path);
    mx_get_lstat(file, ffp);
    mx_get_passwd(file);
    mx_get_group(file);
    file->blocks = file->stat.st_blocks;
    file->acl = mx_gen_acl_str(file, ffp);
    file->link = mx_read_link(file, ffp);
    if (file->acl[0] == 'c' || file->acl[0] == 'b') {
        file->driver = mx_create_driver();
        mx_read_driver(file, file->driver);
    }
    file->time = mx_parse_ctime(file->stat.st_mtime);
    mx_strdel(&ffp);
    return file;
}
