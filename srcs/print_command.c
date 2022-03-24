/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:04:19 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/24 15:17:26 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putstrnl(const char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	print_command(t_lstinfo *lstinfo)
{
	t_command	*tmp;

	compress_command(lstinfo);
	while (lstinfo->lst_command)
	{
		ft_putstrnl(lstinfo->lst_command->command);
		tmp = lstinfo->lst_command;
		lstinfo->lst_command = lstinfo->lst_command->next;
		free(tmp);
	}
}
