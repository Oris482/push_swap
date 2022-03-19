/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:27:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/19 22:06:22 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_acb(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
	{
		if (func_ra(lstinfo) && func_sa(lstinfo))
			return (func_rra(lstinfo));
		else
			return (0);
	}
	else if (pos == 1)
	{
		if (func_sb(lstinfo) && func_rb(lstinfo)
			&& func_sb(lstinfo))
			return (func_rrb(lstinfo));
		else
			return (0);
	}
	else
	{
		if (func_rrb(lstinfo) && func_rrb(lstinfo)
			&& func_rrb(lstinfo))
			return (sort_acb(lstinfo, 1));
		else
			return (0);
	}
}

int	sort_bac(t_lstinfo *lstinfo, int c)
{
	if (c == 'a')
		return (func_sa(lstinfo));
	else
		return (func_sb(lstinfo));
}

int	sort_bca(t_lstinfo *lstinfo, int c)
{
	if (c == 'a')
		return (func_rra(lstinfo));
	else
		return (func_rrb(lstinfo));
}

int	sort_cab(t_lstinfo *lstinfo, int c)
{
	if (c == 'a')
		return (func_ra(lstinfo));
	else
		return (func_rb(lstinfo));
}

int	sort_cba(t_lstinfo *lstinfo, int c)
{
	if (c == 'a')
	{
		if (!func_sa(lstinfo))
			return (0);
		return (func_rra(lstinfo));
	}
	else
	{
		if (!func_sb(lstinfo))
			return (0);
		return (func_rrb(lstinfo));
	}
}
