#include "uls.h"

t_out *mx_create_outnode() {
    t_out *node = (t_out *)malloc(sizeof(t_out));

    if (node) {
        node->i = 0;
        node->j = 0;
        node->k = 0;
        node->count_link = 0;
        node->count_uname = 0;
        node->count_group = 0;
        node->count_size = 0;
        node->file_amount = 0;
        node->openfile_amt = 0;
        node->columns = 0;
        node->rows = 0;
        node->blocks = 0;
        node->nlink = NULL;
        node->size = NULL;
        node->gid = NULL;
    }
    return node;
}
