#include "uls.h"

void mx_clear_out(t_out *ip) {
    if (ip->gid != NULL) {
        mx_strdel(&ip->gid);
        ip->gid = NULL;
    }
    if (ip->size != NULL) {
        mx_strdel(&ip->size);
        ip->size = NULL; 
    }
    if (ip->nlink != NULL) {
        mx_strdel(&ip->nlink);
        ip->nlink = NULL;
    }
    if (ip->sblocks != NULL) {
        mx_strdel(&ip->sblocks);
        ip->sblocks = NULL;
    }
    if (ip->name != NULL) {
        mx_strdel(&ip->name);
        ip->name = NULL;
    }
}
