/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:09 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/26 17:44:12 by jaesjeon         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rewind_stack(t_lstinfo *lstinfo, int pos, int times)
{
	if (pos == 0 && times == lstinfo->a_arg_cnt)
		return (1);
	else if ((pos == 1 || pos == 2) && times == lstinfo->b_arg_cnt)
		return (1);
	while (times-- > 0)
	{
		if (pos == 0)
		{
			if (!func_rra(lstinfo))
				return (0);
		}
		else if (pos == 1)
		{
			if (!func_rrb(lstinfo))
				return (0);
		}
		else if (pos == 2)
		{
			if (!func_rb(lstinfo))
				return (0);
		}
	}
	return (1);
}

t_stack	*set_cur_node(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (lstinfo->a_top);
	else if (pos == 1)
		return (lstinfo->b_top);
	else
		return (lstinfo->b_bottom);
}

int	record_command(t_lstinfo *lstinfo, char *command)
{
	t_command	*cur_node;
	t_command	*new_node;
	int			idx;

	cur_node = lstinfo->lst_command;
	idx = 0;
	if ((cur_node->command)[0] == '\0')
	{
		while (*command)
			(cur_node->command)[idx++] = *command++;
		return (1);
	}
	new_node = (t_command *)ft_calloc(1, sizeof(t_command));
	if (new_node == NULL)
		return (0);
	cur_node->next = new_node;
	new_node->prev = cur_node;
	while (*command)
		(new_node->command)[idx++] = *command++;
	lstinfo->lst_command = new_node;
	return (1);
}

t_lstinfo	*lst_fclean(t_lstinfo *lstinfo)
{
	t_stack		*stack_tmp;
	t_command	*command_tmp;

	while (lstinfo->a_top)
	{
		stack_tmp = lstinfo->a_top;
		lstinfo->a_top = stack_tmp->next;
		free(stack_tmp);
	}
	while (lstinfo->b_top)
	{
		stack_tmp = lstinfo->b_top;
		lstinfo->b_top = stack_tmp->next;
		free(stack_tmp);
	}
	while (lstinfo->lst_command)
	{
		command_tmp = lstinfo->lst_command;
		lstinfo->lst_command = command_tmp->prev;
		free (command_tmp);
	}
	free (lstinfo);
	return (NULL);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
