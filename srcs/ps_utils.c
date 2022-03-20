/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:09 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/20 16:43:37 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
int	record_command(t_command **lst_command, char *command)
{
	t_command	*new_node;
	int			idx;

	idx = 0;
	if ((*(*lst_command)->command) == '\0')
	{
		while (*command)
			((*lst_command)->command)[idx++] = *command++;
		return (1);
	}
	new_node = (t_command *)ft_calloc(1, sizeof(t_command));
	if (new_node == NULL)
		return (0);
	(*lst_command)->next = new_node;
	while (*command)
		(new_node->command)[idx++] = *command++;
	*lst_command = new_node;
	return (1);
}
*/
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
		free(command_tmp);
	}
	free (lstinfo);
	return (NULL);
}

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
