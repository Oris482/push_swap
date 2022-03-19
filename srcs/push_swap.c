/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:01 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/19 22:26:21 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	*three_split(t_lstinfo *lstinfo, int start,
		int end, int pos)
{
	int		qty;
	t_stack	*cur_node;

	qty = end - start + 1;
	if (qty <= 6)
		return (manual_sort());
	cur_node = lstinfo->a_top;
	while (qty-- > 0)
	{
	}
}

static int	check_overlap(t_stack *a_stack)
{
	long long	cur_value;
	t_stack		*comp_stack;

	while (a_stack->next != NULL)
	{
		cur_value = a_stack->value;
		comp_stack = a_stack->next;
		while (comp_stack)
		{
			if (cur_value == comp_stack->value)
				return (1);
			comp_stack = comp_stack->next;
		}
		a_stack = a_stack->next;
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
	while (a_stack && ++(lstinfo->arg_cnt))
	{
		if (a_stack->value > INT_MAX || a_stack->value < INT_MIN)
			return (lst_fclean(lstinfo));
		if (a_stack->next && a_stack->next->value < a_stack->value)
			*is_sorted = 0;
		if (a_stack->next == NULL)
			lstinfo->a_bottom = a_stack;
		a_stack = a_stack->next;
	}
	if (*is_sorted || check_overlap(lstinfo->a_top))
		return (lst_fclean(lstinfo));
	return (lstinfo);
}

int	main(int argc, char *argv[])
{
	t_lstinfo	*lstinfo;
	t_command	*lst_command;
	int			is_sorted;
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	t_command		*tmp_command;
	int			idx;

	lstinfo = (t_lstinfo *)ft_calloc(1, sizeof(t_lstinfo));
	lst_command = (t_command *)ft_calloc(1, sizeof(t_command));
	if (lstinfo == NULL || lst_command == NULL)
		return (print_error());
	lstinfo->lst_command = lst_command;
	if (argc > 1)
	{
		lstinfo = init_lst(lstinfo, argc, argv, &is_sorted);
		if (is_sorted == 1)
			return (0);
		if (lstinfo == NULL)
			return (print_error());
		tmp_a = lstinfo->a_top;
		tmp_b = lstinfo->b_top;
		printf("=========init stack========\n");
		printf("#####Stack A#####\n");
		while (tmp_a)
		{
			printf("%lld ", tmp_a->value);
			tmp_a = tmp_a->next;
		}
		printf("\n#####Stack B#####\n");
		while (tmp_b)
		{
			printf("%lld ", tmp_b->value);
			tmp_b = tmp_b->next;
		}
		func_pb(lstinfo);
		func_pb(lstinfo);
		func_pb(lstinfo);
		func_pb(lstinfo);
		func_pb(lstinfo);
		func_pb(lstinfo);
		sort_acb(lstinfo, 0);
		sort_acb(lstinfo, 1);
		func_pa(lstinfo);
		func_pa(lstinfo);
		func_pa(lstinfo);
		sort_acb(lstinfo, 2);
		func_pa(lstinfo);
		func_pa(lstinfo);
		func_pa(lstinfo);
		tmp_a = lstinfo->a_top;
		tmp_b = lstinfo->b_top;
		printf("\n----------After move-----------\n");
		printf("\n#####Stack A#####\n");
		while (tmp_a)
		{
			printf("%lld ", tmp_a->value);
			tmp_a = tmp_a->next;
		}
		printf("\n#####Stack B#####\n");
		while (tmp_b)
		{
			printf("%lld ", tmp_b->value);
			tmp_b = tmp_b->next;
		}
		printf("\n----------pos check-----------\n");
		//printf("pos 0 check = %d\n", check_sorted(lstinfo, 0, 3));
		//printf("pos 1 check = %d\n", check_sorted(lstinfo, 1, 3));
		//printf("pos 2 check = %d\n", check_sorted(lstinfo, 2, 3));
		printf("\n----------command list-----------\n");
		while (lstinfo->lst_command->prev != NULL)
			lstinfo->lst_command = lstinfo->lst_command->prev;
		tmp_command = lstinfo->lst_command;
		while (tmp_command)
		{
			printf("%s\n", tmp_command->command);
			tmp_command = tmp_command->next;
		}
		lst_fclean(lstinfo);
	}
}
