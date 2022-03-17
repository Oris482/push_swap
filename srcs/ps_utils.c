/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:37:09 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/17 17:47:21 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_fclean(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (NULL);
}

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
