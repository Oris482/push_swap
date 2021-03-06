/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:01 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/26 17:50:38 by jaesjeon         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overlap(t_lstinfo *lstinfo, int *is_sorted)
{
	int			cnt;
	t_stack		*cur_node;
	t_stack		*comp_node;

	cur_node = lstinfo->a_top;
	while (cur_node)
	{
		comp_node = lstinfo->a_top;
		cnt = 0;
		while (comp_node)
		{
			if (cur_node->value == comp_node->value)
				cnt++;
			comp_node = comp_node->next;
			if (cnt == 2)
			{
				*is_sorted = 0;
				return (1);
			}
		}
		cur_node = cur_node->next;
	}
	return (0);
}

static t_lstinfo	*init_lst(t_lstinfo *lstinfo, int argc, char *argv[],
		int	*is_sorted)
{
	t_stack	*a_stack;

	lstinfo->a_top = parse_num_list(argc, argv);
	if (lstinfo->a_top == NULL)
		return (NULL);
	a_stack = lstinfo->a_top;
	*is_sorted = 1;
	while (a_stack && ++(lstinfo->a_arg_cnt))
	{
		if (a_stack->value > INT_MAX || a_stack->value < INT_MIN)
		{
			*is_sorted = 0;
			return (lst_fclean(lstinfo));
		}
		if (a_stack->next && a_stack->next->value <= a_stack->value)
			*is_sorted = 0;
		if (a_stack->next == NULL)
			lstinfo->a_bottom = a_stack;
		a_stack = a_stack->next;
	}
	if (*is_sorted || check_overlap(lstinfo, is_sorted))
		return (lst_fclean(lstinfo));
	return (lstinfo);
}

int	main(int argc, char *argv[])
{
	t_lstinfo	*lstinfo;
	int			is_sorted;
	int			error_flag;

	lstinfo = (t_lstinfo *)ft_calloc(1, sizeof(t_lstinfo));
	lstinfo->lst_command = (t_command *)ft_calloc(1, sizeof(t_command));
	if (lstinfo == NULL || lstinfo->lst_command == NULL)
		return (print_error());
	if (argc > 1)
	{
		error_flag = 0;
		lstinfo = init_lst(lstinfo, argc, argv, &is_sorted);
		if (is_sorted == 1)
			return (0);
		if (lstinfo == NULL)
			return (print_error());
		arg_indexing(lstinfo);
		if (!split_recursive(lstinfo, 0, lstinfo->a_arg_cnt - 1, 0))
			error_flag = 1;
		if (error_flag == 0)
			print_command(lstinfo);
		lst_fclean(lstinfo);
	}
}
