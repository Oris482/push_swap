/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:27:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/19 18:45:51 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_acb(t_lstinfo *lstinfo, int c, t_command **lst_command)
{
	if (c == 'a')
	{
		if (!func_rra(lstinfo, lst_command))
			return (0);
		return (func_sa(lstinfo, lst_command));
	}
	else
	{
		if (!func_rrb(lstinfo, lst_command))
			return (0);
		return (func_sb(lstinfo, lst_command));
	}
}

int	sort_bac(t_lstinfo *lstinfo, int c, t_command **lst_command)
{
	if (c == 'a')
		return (func_sa(lstinfo, lst_command));
	else
		return (func_sb(lstinfo, lst_command));
}

int	sort_bca(t_lstinfo *lstinfo, int c, t_command **lst_command)
{
	if (c == 'a')
		return (func_rra(lstinfo, lst_command));
	else
		return (func_rrb(lstinfo, lst_command));
}

int	sort_cab(t_lstinfo *lstinfo, int c, t_command **lst_command)
{
	if (c == 'a')
		return (func_ra(lstinfo, lst_command));
	else
		return (func_rb(lstinfo, lst_command));
}

int	sort_cba(t_lstinfo *lstinfo, int c, t_command **lst_command)
{
	if (c == 'a')
	{
		if (!func_sa(lstinfo, lst_command))
			return (0);
		return (func_rra(lstinfo, lst_command));
	}
	else
	{
		if (!func_sb(lstinfo, lst_command))
			return (0);
		return (func_rrb(lstinfo, lst_command));
	}
}
