#include "push_swap.h"

static void del_prev_node(t_lstinfo *lstinfo)
{
    t_command   *tmp;
    t_command   *cur_node;

    cur_node = lstinfo->lst_command;
    tmp = cur_node->prev;
    cur_node->prev = tmp->prev;
    if (tmp->prev)
        tmp->prev->next = cur_node;
    free(tmp);
}

static int  get_code(t_command *cur_node)
{
    int     idx;
    int     ret;
    int     alpha;
    char    *cur_command;

    idx = 0;
    ret = 0;
    cur_command = cur_node->command;
    while (cur_command[idx])
    {
        if (cur_command[idx] == 's' || cur_command[idx] == 'a')
            alpha = 1;
        else if (cur_command[idx] == 'p' || cur_command[idx] == 'b')
            alpha = 2;
        else
            alpha = 3;
        ret = (ret * 10 + alpha);
        idx++;
    }
    return (ret);
}

static int  is_parallel(t_lstinfo *lstinfo, t_command *cur_node)
{
    if ((get_code(cur_node) == 12 && get_code(cur_node->prev) == 11)
        || (get_code(cur_node) == 11 && get_code(cur_node->prev) == 12))
    {
        (cur_node->command)[0] = '\0';
        del_prev_node(lstinfo);
        record_command(lstinfo, "ss");
    }
    else if ((get_code(cur_node) == 32 && get_code(cur_node->prev) == 31)
        || (get_code(cur_node) == 31 && get_code(cur_node->prev) == 32))
    {
        (cur_node->command)[0] = '\0';
        del_prev_node(lstinfo);
        record_command(lstinfo, "rr");
    }
    else if ((get_code(cur_node) == 332 && get_code(cur_node->prev) == 331)
        || (get_code(cur_node) == 331 && get_code(cur_node->prev) == 332))
    {
        (cur_node->command)[0] = '\0';
        del_prev_node(lstinfo);
        record_command(lstinfo, "rrr");
    }
    else
        return (0);
    return (1);
}

static int  is_nothing(t_lstinfo *lstinfo, t_command *cur_node)
{
    if ((get_code(cur_node) == 21 && get_code(cur_node->prev) == 22)
        || (get_code(cur_node) == 22 && get_code(cur_node->prev) == 21))
    {
        lstinfo->lst_command = lstinfo->lst_command->next;
        del_prev_node(lstinfo);
        del_prev_node(lstinfo);
    }
    else if ((get_code(cur_node) == 31 && get_code(cur_node->prev) == 331)
        || (get_code(cur_node) == 331 && get_code(cur_node->prev) == 31))
    {
        lstinfo->lst_command = lstinfo->lst_command->next;
        del_prev_node(lstinfo);
        del_prev_node(lstinfo);
    }
    else if ((get_code(cur_node) == 32 && get_code(cur_node->prev) == 332)
        || (get_code(cur_node) == 332 && get_code(cur_node->prev) == 32))
    {
        lstinfo->lst_command = lstinfo->lst_command->next;
        del_prev_node(lstinfo);
        del_prev_node(lstinfo);
    }
    else
        return (0);
    return (1);
}

void    compress_command(t_lstinfo *lstinfo)
{
    while (lstinfo->lst_command->prev)
    {
        if (is_parallel(lstinfo, lstinfo->lst_command))
        {  
            ;
        }
        if (lstinfo->lst_command->next && is_nothing(lstinfo, lstinfo->lst_command))
        {
            ;
        }
        else
            lstinfo->lst_command = lstinfo->lst_command->prev;
    }
}