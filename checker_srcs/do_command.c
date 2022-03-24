/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:23:03 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/24 19:37:07 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

static int	get_code(char *command)
{
	int		idx;
	int		ret;
	int		alpha;

	idx = 0;
	ret = 0;
	while (command[idx] && ft_isalpha(command[idx]))
	{
		if (command[idx] == 'a')
			alpha = 1;
		else if (command[idx] == 'b')
			alpha = 2;
		else if (command[idx] == 's')
			alpha = 5;
		else if (command[idx] == 'p')
			alpha = 6;
		else if (command[idx] == 'r')
			alpha = 7;
		ret = (ret * 10 + alpha);
		idx++;
	}
	return (ret);
}

static void	swap_push(t_lstinfo *lstinfo, int command_code)
{
	if ((command_code == 51 || command_code == 55) && lstinfo->a_arg_cnt >= 2)
		func_sa(lstinfo);
	if ((command_code == 52 || command_code == 55) && lstinfo->b_arg_cnt >= 2)
		func_sb(lstinfo);
	else if (command_code == 61 && lstinfo->b_arg_cnt >= 1)
		func_pa(lstinfo);
	else if (command_code == 62 && lstinfo->a_arg_cnt >= 1)
		func_pb(lstinfo);
}

static void	rotate(t_lstinfo *lstinfo, int command_code)
{
	if (command_code == 771 || command_code == 777)
		func_rra(lstinfo);
	if (command_code == 772 || command_code == 777)
		func_rrb(lstinfo);
	else
	{
		if (command_code == 71 || command_code == 77)
			func_ra(lstinfo);
		if (command_code == 72 || command_code == 77)
			func_rb(lstinfo);
	}
}

void	do_command(t_lstinfo *lstinfo)
{
	char	*command;
	int		command_code;

	command = "";
	while (command)
	{
		command = get_next_line(0);
		if (command)
		{
			command_code = get_code(command);
			if (command_code < 70)
				swap_push(lstinfo, command_code);
			else
				rotate(lstinfo, command_code);
		}
		free(command);
	}
}
