/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:02:46 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/21 19:14:42 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	five_sort_pos_zero(t_lstinfo *lstinfo, int end)
{
	int	rewind;

	if (lstinfo->a_top->next->next->next->idx == (end - 1)
		&& lstinfo->a_top->next->next->next->next->idx == end)
		return (three_sort(lstinfo, 0));
	rewind = 0;
	while (rewind++ < 3)
	{
		if (lstinfo->a_top->idx == end || lstinfo->a_top->idx == (end - 1))
			if (!func_pb(lstinfo))
				return (0);
		if (!func_ra(lstinfo))
			return (0);
	}
	if (!two_sort(lstinfo, 1))
		return (0);
	while (--rewind > 0)
		if (!func_rra(lstinfo))
			return (0);
	return (three_sort(lstinfo, 0));
}

static int	five_sort_pos_one(t_lstinfo *lstinfo, int end)
{
	int	rewind;
	int	cnt;

	rewind = 0;
	cnt = 0;
	while (cnt < 2 || rewind < 3)
	{
		if (lstinfo->b_top->idx == end || lstinfo->b_top->idx == (end - 1))
		{
			if (!func_pa(lstinfo))
				return (0);
			cnt++;
		}
		else
		{
			if (!func_rb(lstinfo))
				return (0);
			rewind++;
		}
	}
	while (--rewind > 0)
		if (!func_rrb(lstinfo))
			return (0);
	return (two_sort(lstinfo, 0) && three_sort(lstinfo, 1));
}

static int	five_sort_pos_two(t_lstinfo *lstinfo, int end)
{
	int	rewind;

	rewind = 0;
	while (rewind++ < 5)
	{
		if (func_rrb(lstinfo))
			return (0);
		if (lstinfo->b_top->idx == end || lstinfo->b_top->idx == (end - 1))
			if (!func_pa(lstinfo))
				return (0);
	}
	return (two_sort(lstinfo, 0) && three_sort(lstinfo, 1));
}

int	five_sort(t_lstinfo *lstinfo, int pos, int end)
{
	if (pos == 0)
		return (five_sort_pos_zero(lstinfo, end));
	else if (pos == 1)
		return (five_sort_pos_one(lstinfo, end));
	else
		return (five_sort_pos_two(lstinfo, end));
}
