/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:01 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/25 17:03:42 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

static int	check_overlap(t_lstinfo *lstinfo)
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
				return (1);
		}
		cur_node = cur_node->next;
	}
	return (0);
}

static t_lstinfo	*init_lst(t_lstinfo *lstinfo, int argc, char *argv[])
{
	t_stack	*a_stack;

	lstinfo->a_top = parse_num_list(argc, argv);
	if (lstinfo->a_top == NULL)
		return (NULL);
	a_stack = lstinfo->a_top;
	while (a_stack && ++(lstinfo->a_arg_cnt))
	{
		if (a_stack->value > INT_MAX || a_stack->value < INT_MIN)
			return (lst_fclean(lstinfo));
		if (a_stack->next == NULL)
			lstinfo->a_bottom = a_stack;
		a_stack = a_stack->next;
	}
	if (check_overlap(lstinfo))
		return (lst_fclean(lstinfo));
	return (lstinfo);
}

int	main(int argc, char *argv[])
{
	t_lstinfo	*lstinfo;

	lstinfo = (t_lstinfo *)ft_calloc(1, sizeof(t_lstinfo));
	if (lstinfo == NULL)
		return (print_result('e'));
	if (argc > 1)
	{
		lstinfo = init_lst(lstinfo, argc, argv);
		if (lstinfo == NULL)
			return (print_result('e'));
		do_command(lstinfo);
		if (check_sorted(lstinfo))
			return (print_result('o') || lst_fclean(lstinfo));
		else
			return (print_result('x') || lst_fclean(lstinfo));
	}
}
