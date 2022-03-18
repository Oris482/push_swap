/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:01 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/18 22:21:35 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

static t_lstinfo	*init_lst(t_lstinfo *lstinfo, int argc, char *argv[])
{
	t_stack	*a_stack;
	int		is_sorted;

	lstinfo->a_top = parse_num_list(argc, argv);
	a_stack = lstinfo->a_top;
	is_sorted = 1;
	while (a_stack && ++(lstinfo->arg_cnt))
	{
		if (a_stack->value > INT_MAX || a_stack->value < INT_MIN)
		{
			lst_fclean(lstinfo->a_top);
			return (NULL);
		}
		if (a_stack->next && a_stack->next->value < a_stack->value)
			is_sorted = 0;
		if (a_stack->next == NULL)
			lstinfo->a_bottom = a_stack;
		a_stack = a_stack->next;
	}
	if (is_sorted || check_overlap(lstinfo->a_top))
	{
		lst_fclean(lstinfo->a_top);
		return (NULL);
	}
	return (lstinfo);
}

int	main(int argc, char *argv[])
{
	t_lstinfo	*lstinfo;
	t_commands	*lst_command;
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	lstinfo = (t_lstinfo *)ft_calloc(1, sizeof(t_lstinfo));
	lst_command = (t_commands*)ft_calloc(1, sizeof(t_commands));
	if (lstinfo == NULL || lst_command == NULL)
		return (print_error());
	lstinfo->lst_command = lst_command;
	if (argc > 1)
	{
		lstinfo = init_lst(lstinfo, argc, argv);
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
		func_pb(lstinfo, &lst_command);
		func_pb(lstinfo, &lst_command);
		func_pb(lstinfo, &lst_command);
		func_sb(lstinfo, &lst_command);
		func_pb(lstinfo, &lst_command);
		func_sa(lstinfo, &lst_command);
		func_pa(lstinfo, &lst_command);
		func_ra(lstinfo, &lst_command);
		func_rb(lstinfo, &lst_command);
		func_rra(lstinfo, &lst_command);
		func_rrb(lstinfo, &lst_command);
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
		printf("\n----------command list-----------\n");
		while (lstinfo->lst_command)
		{
			printf("%s\n", lstinfo->lst_command->command);
			lstinfo->lst_command = lstinfo->lst_command->next;
		}
		lst_fclean(lstinfo->a_top);
		lst_fclean(lstinfo->b_top);
	}
}
