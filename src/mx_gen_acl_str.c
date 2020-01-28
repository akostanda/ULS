#include "uls.h"

static void set_file_type(t_file *file, char *acl) {
    acl[0] = ISDIR(file->stat.st_mode) ? 'd' : '-';
    acl[0] = ISCHR(file->stat.st_mode) ? 'c' : acl[0];
    acl[0] = ISBLK(file->stat.st_mode) ? 'b' : acl[0];
    acl[0] = ISFIFO(file->stat.st_mode) ? 'p' : acl[0];
    acl[0] = ISLNK(file->stat.st_mode) ? 'l' : acl[0];
    acl[0] = ISSOCK(file->stat.st_mode) ? 's' : acl[0];
}

static void set_user_acl(t_file *file, char *acl) {
    acl[1] = (file->stat.st_mode & IRUSR) ? 'r' : '-';
    acl[2] = (file->stat.st_mode & IWUSR) ? 'w' : '-';
    acl[3] = (file->stat.st_mode & IXUSR) ? 'x' : '-';
    acl[3] = (file->stat.st_mode & ISUID) ? 's' : acl[3];
}

static void set_group_acl(t_file *file, char *acl) {
    acl[4] = (file->stat.st_mode & IRGRP) ? 'r' : '-';
    acl[5] = (file->stat.st_mode & IWGRP) ? 'w' : '-';
    acl[6] = (file->stat.st_mode & IXGRP) ? 'x' : '-';
    acl[6] = (file->stat.st_mode & ISGID) ? 's' : acl[6];
}

static void set_other_acl(t_file *file, char *acl) {
    acl[7] = (file->stat.st_mode & IROTH) ? 'r' : '-';
    acl[8] = (file->stat.st_mode & IWOTH) ? 'w' : '-';
    acl[9] = (file->stat.st_mode & IXOTH) ? 'x' : '-';
    acl[9] = (file->stat.st_mode & ISVTX) ? 't' : acl[9];
}

static void set_ads_ch(char *path, char *acl) {
    acl_t my_acl = acl_get_file(path, ACL_TYPE_EXTENDED);
    ssize_t len = 0;
    char *text_acl = acl_to_text(my_acl, &len);
    ssize_t buflen = listxattr(path, NULL, 0, XATTR_NOFOLLOW);

    acl[10] = ' ';
    if (text_acl)
        acl[10] = '+';
    if (buflen > 0)
        acl[10] = '@';
    acl_free(my_acl);
    if (text_acl)
        mx_strdel(&text_acl);
}

char *mx_gen_acl_str(t_file *file, char *path) {
    char *acl = mx_strnew(11);

    set_file_type(file, acl);
    set_user_acl(file, acl);
    set_group_acl(file, acl);
    set_other_acl(file, acl);
    set_ads_ch(path, acl);

    return acl;
}
