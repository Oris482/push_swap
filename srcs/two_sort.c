/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:45:38 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/20 19:53:08 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	two_sort(t_lstinfo *lstinfo, int pos)
{
	t_stack	*cur_node;

	cur_node = set_cur_node(lstinfo, pos);
	if (pos == 0)
	{
		if (cur_node->idx < cur_node->next->idx)
			return (1);
		return (func_sa(lstinfo));
	}
	else if (pos == 1)
	{
		if (cur_node->idx > cur_node->next->idx)
			return (1);
		return (func_sb(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo));
	}
	else
	{
		if (cur_node->idx < cur_node->prev->idx)
			return (func_rrb(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo)
				&& func_pa(lstinfo));
		return (func_rrb(lstinfo) && func_pa(lstinfo) && func_rrb(lstinfo)
			&& func_pa(lstinfo));
	}
}
