#include "push_swap.h"

static void    ft_putstrnl(const char *str)
{
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
}

void    print_command(t_lstinfo *lstinfo)
{
    compress_command(lstinfo);
    while (lstinfo->lst_command)
    {
        ft_putstrnl(lstinfo->lst_command->command);
        lstinfo->lst_command = lstinfo->lst_command->next;
    }
}