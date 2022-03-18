/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:09 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/18 22:21:37 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	record_command(t_commands **lst_command, char *command)
{
	t_commands	*new_node;
	int			idx;

	idx = 0;
	if ((*(*lst_command)->command) == '\0')
	{
		while (*command)
			((*lst_command)->command)[idx++] = *command++;
		return (1);
	}
	new_node = (t_commands *)ft_calloc(1, sizeof(t_commands));
	if (new_node == NULL)
		return (0);
	(*lst_command)->next = new_node;
	while (*command)
		(new_node->command)[idx++] = *command++;
	*lst_command = new_node;
	return (1);
}

t_stack	*lst_fclean(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (NULL);
}

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
