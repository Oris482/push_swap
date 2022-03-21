/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:01 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/21 20:30:26 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	split_by_pivot(t_lstinfo *lstinfo, int s_pivot,
		int b_pivot, int qty)
{
	int	rewind;
	int	error;

	rewind = 0;
	while (qty-- > 0)
	{
		if (lstinfo->a_top->idx >= b_pivot)
		{
			rewind++;
			error = func_ra(lstinfo);
		}
		else if (lstinfo->a_top->idx >= s_pivot)
			error = func_pb(lstinfo);
		else
		{
			if (!func_pb(lstinfo))
				return (0);
			error = func_rb(lstinfo);
		}
		if (error == -1)
			return (0);
	}
	if (!rewind_stack(lstinfo, 0, rewind))
		return (0);
	return (1);
}

static int	three_split(t_lstinfo *lstinfo, int start, int end, int pos)
{
	int	qty;
	int	cnt;

	qty = end - start + 1;
	cnt = qty;
	if (check_sorted(lstinfo, pos, qty))
		return (1);
	if (qty <= 5)
		return (manual_sort(lstinfo, pos, qty, end) && display_stack(lstinfo));
	if (pos == 1)
		return (move_to_a(lstinfo, pos, qty)
			&& three_split(lstinfo, start, end, 0));
	if (pos == 2)
		return (move_to_a(lstinfo, pos, qty)
			&& three_split(lstinfo, start, end, 0));
	if (!split_by_pivot(lstinfo, start + (qty / 3), start + (qty / 3 * 2), qty))
		return (0);
	display_stack(lstinfo);
	if (!three_split(lstinfo, start + ((qty / 3) * 2), end, 0))
		return (0);
	if (!three_split(lstinfo, start + (qty / 3), start + (qty / 3 * 2) - 1, 1))
		return (0);
	return (three_split(lstinfo, start, start + (qty / 3) - 1, 2));
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
//	t_command		*tmp_command;

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
		arg_indexing(lstinfo);
		tmp_a = lstinfo->a_top;
		tmp_b = lstinfo->b_top;
		printf("=========init stack========\n");
		printf("#####Stack A#####\n");
		while (tmp_a)
		{
			printf("%d ", tmp_a->idx);
			tmp_a = tmp_a->next;
		}
		printf("\n#####Stack B#####\n");
		while (tmp_b)
		{
			printf("%d ",  tmp_b->idx);
			tmp_b = tmp_b->next;
		}
		if (!three_split(lstinfo, 0, lstinfo->arg_cnt - 1, 0))
			return (print_error());
		tmp_a = lstinfo->a_top;
		tmp_b = lstinfo->b_top;
		printf("\n----------After move-----------\n");
		printf("\n#####Stack A#####\n");
		while (tmp_a)
		{
			printf("%d ", tmp_a->idx);
			tmp_a = tmp_a->next;
		}
		printf("\n#####Stack B#####\n");
		while (tmp_b)
		{
			printf("%d ", tmp_b->idx);
			tmp_b = tmp_b->next;
		}
		printf("\n----------pos check-----------\n");
		//printf("pos 0 check = %d\n", check_sorted(lstinfo, 0, 3));
		//printf("pos 1 check = %d\n", check_sorted(lstinfo, 1, 3));
		//printf("pos 2 check = %d\n", check_sorted(lstinfo, 2, 3));
		/*
		printf("\n----------command list-----------\n");
		while (lstinfo->lst_command->prev != NULL)
			lstinfo->lst_command = lstinfo->lst_command->prev;
		tmp_command = lstinfo->lst_command;
		while (tmp_command)
		{
			printf("%s\n", tmp_command->command);
			tmp_command = tmp_command->next;
		}
		*/
		lst_fclean(lstinfo);
	}
}
