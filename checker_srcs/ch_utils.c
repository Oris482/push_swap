/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:09 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/24 17:04:27 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*set_cur_node(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (lstinfo->a_top);
	else if (pos == 1)
		return (lstinfo->b_top);
	else
		return (lstinfo->b_bottom);
}

t_lstinfo	*lst_fclean(t_lstinfo *lstinfo)
{
	t_stack		*stack_tmp;

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
	free (lstinfo);
	return (NULL);
}

int	check_sorted(t_lstinfo *lstinfo)
{
	int		is_sorted;
	t_stack	*a_stack;

	is_sorted = 1;
	a_stack = lstinfo->a_top;
	while (a_stack)
	{
		if (a_stack->next && a_stack->next->value <= a_stack->value)
		{
			is_sorted = 0;
			break ;
		}
		a_stack = a_stack->next;
	}
	return (is_sorted);
}

int	print_result(int c)
{
	if (c == 'e')
		write(2, "Error\n", 6);
	else if (c == 'o')
		write (1, "OK\n", 3);
	else if (c == 'x')
		write (1, "KO\n", 3);
	return (0);
}
