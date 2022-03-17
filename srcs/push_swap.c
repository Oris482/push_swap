/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:01 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/17 20:38:25 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_lstinfo	*init_lst(t_lstinfo *lstinfo, int argc, char *argv[])
{
	t_stack	*a_stack;
	int		is_sorted;

	lstinfo->a_top = parse_num_list(argc, argv);
	a_stack = lstinfo->a_top;
	is_sorted = 1;
	while (a_stack->next != NULL)
	{
		if (a_stack->value > INT_MAX || a_stack->value < INT_MIN)
		{
			lst_fclean(lstinfo->a_top);
			return (NULL);
		}
		if (a_stack->prev && a_stack->prev->value > a_stack->value)
			is_sorted = 0;
		a_stack = a_stack->next;
	}
	if (is_sorted)
	{
		lst_fclean(lstinfo->a_top);
		return (NULL);
	}
	lstinfo->a_bottom = a_stack;
	return (lstinfo);
}

int	main(int argc, char *argv[])
{
	t_lstinfo	*lstinfo;
	t_stack		*tmp;

	lstinfo = (t_lstinfo *)ft_calloc(1, sizeof(t_lstinfo));
	if (lstinfo == NULL)
		return (print_error());
	if (argc > 1)
	{
		lstinfo = init_lst(lstinfo, argc, argv);
		if (lstinfo == NULL)
			return (print_error());
		tmp = lstinfo->a_bottom;
		while (tmp)
		{
			printf("%lld ", tmp->value);
			tmp = tmp->prev;
		}
		lst_fclean(lstinfo->a_top);
	}
}
