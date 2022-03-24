/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_pivot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:05:38 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/24 15:05:40 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	split_pos_zero(t_lstinfo *lstinfo,
		int s_pivot, int b_pivot, int qty)
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
		if (error == 0)
			return (0);
	}
	if (!rewind_stack(lstinfo, 0, rewind))
		return (0);
	return (1);
}

static int	split_pos_one(t_lstinfo *lstinfo, int m_pivot, int qty)
{
	while (qty-- > 0)
	{
		if (lstinfo->b_top->idx >= m_pivot)
		{
			if (!func_pa(lstinfo))
				return (0);
		}
		else
		{
			if (!func_rb(lstinfo))
				return (0);
		}
	}
	return (1);
}

static int	split_pos_two(t_lstinfo *lstinfo, int m_pivot, int qty)
{
	while (qty-- > 0)
	{
		if (!func_rrb(lstinfo))
			return (0);
		if (lstinfo->b_top->idx >= m_pivot)
		{
			if (!func_pa(lstinfo))
				return (0);
		}
	}
	return (1);
}

static int	split_by_pivot(t_lstinfo *lstinfo, int start, int end, int pos)
{
	int	qty;
	int	s_pivot;
	int	b_pivot;
	int	m_pivot;

	qty = end - start + 1;
	s_pivot = start + (qty / 3);
	b_pivot = s_pivot + (qty / 3);
	m_pivot = start + (qty / 2);
	if (pos == 0)
		return (split_pos_zero(lstinfo, s_pivot, b_pivot, qty)
			&& split_recursive(lstinfo, b_pivot, end, 0)
			&& split_recursive(lstinfo, s_pivot, b_pivot - 1, 1)
			&& split_recursive(lstinfo, start, s_pivot - 1, 2));
	if (pos == 1)
		return (split_pos_one(lstinfo, m_pivot, qty)
			&& split_recursive(lstinfo, m_pivot, end, 0)
			&& split_recursive(lstinfo, start, m_pivot - 1, 2));
	if (pos == 2)
		return (split_pos_two(lstinfo, m_pivot, qty)
			&& split_recursive(lstinfo, m_pivot, end, 0)
			&& split_recursive(lstinfo, start, m_pivot - 1, 1));
	return (0);
}

int	split_recursive(t_lstinfo *lstinfo, int start, int end, int pos)
{
	int	qty;

	qty = end - start + 1;
	if (check_sorted(lstinfo, pos, qty))
		return (1);
	if (qty <= 5)
		return (manual_sort(lstinfo, pos, qty, end));
	return (split_by_pivot(lstinfo, start, end, pos));
}
