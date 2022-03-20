/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_indexing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:33:40 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/20 17:38:02 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_indexing(t_lstinfo *lstinfo)
{
	t_stack	*head;
	t_stack	*cur_node;

	cur_node = lstinfo->a_top;
	while (cur_node)
	{
		head = lstinfo->a_top;
		while (head)
		{
			if (cur_node->value > head->value)
				(cur_node->idx)++;
			head = head->next;
		}
		cur_node = cur_node->next;
	}
}
