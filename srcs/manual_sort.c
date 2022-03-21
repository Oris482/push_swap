/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:39:46 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/21 17:46:38 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	manual_sort(t_lstinfo *lstinfo, int pos, int qty, int end)
{
	if (qty == 1)
	{
		if (pos == 0)
			return (1);
		else if (pos == 1)
			return (func_pa(lstinfo));
		else
			return (func_rrb(lstinfo) && func_pa(lstinfo));
	}
	else if (qty == 2)
		return (two_sort(lstinfo, pos));
	else if (qty == 3)
		return (three_sort(lstinfo, pos));
	else if (qty == 4)
		return (four_sort(lstinfo, pos, end));
	else if (qty == 5)
		return (five_sort(lstinfo, pos, end));
	return (0);
}
