/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:46 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/22 01:39:27 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	four_sort_pos_zero(t_lstinfo *lstinfo, int end)
{
	int	rewind;

	if (lstinfo->a_top->next->next->next->idx == end)
		return (three_sort(lstinfo, 0));
	rewind = 0;
	while (rewind++ < 3)
	{
		if (lstinfo->a_top->idx == end)
			if (!func_pb(lstinfo))
				return (0);
		if (!func_ra(lstinfo))
			return (0);
	}
	if (!func_pa(lstinfo))
		return (0);
	while (--rewind > 0)
		if (!func_rra(lstinfo))
			return (0);
	return (three_sort(lstinfo, 0));
}

static int	four_sort_pos_one(t_lstinfo *lstinfo, int end)
{
	int	rewind;

	if (lstinfo->b_top->idx == end)
		return (func_pa(lstinfo) && three_sort(lstinfo, 1));
	rewind = 0;
	while (rewind++ < 3)
	{
		if (!func_rb(lstinfo))
			return (0);
		if (lstinfo->b_top->idx == end)
		{
			if (!func_pa(lstinfo))
				return (0);
			break ;
		}
	}
	while (rewind-- > 0)
		if (!func_rrb(lstinfo))
			return (0);
	return (three_sort(lstinfo, 1));
}

static int	four_sort_pos_two(t_lstinfo *lstinfo, int end)
{
	int	rewind;

	if (lstinfo->b_bottom->idx == end)
		return (func_rrb(lstinfo) && func_pa(lstinfo)
			&& three_sort(lstinfo, 2));
	rewind = 0;
	while (rewind++ < 3)
	{
		if (!func_rrb(lstinfo))
			return (0);
		if (lstinfo->b_bottom->idx == end)
		{
			if (!func_rrb(lstinfo))
				return (0);
			if (!func_pa(lstinfo))
				return (0);
			break ;
		}
	}
	while (rewind-- > 0)
		if (!func_rb(lstinfo))
			return (0);
	return (three_sort(lstinfo, 2));
}

int	four_sort(t_lstinfo *lstinfo, int pos, int end)
{
	if (pos == 0)
		return (four_sort_pos_zero(lstinfo, end));
	else if (pos == 1)
		return (four_sort_pos_one(lstinfo, end));
	else
		return (four_sort_pos_two(lstinfo, end));
}
