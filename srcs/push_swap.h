/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:40:57 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/16 20:21:39 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# define LLONG_MAX 9223372036854775807LL
# define INT_MAX 2147483647LL
# define INT_MIN -2147483648LL

typedef struct s_stack
{
	long long		value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lstinfo
{
	struct s_stack	*a_top;
	struct s_stack	*a_bottom;
	struct s_stack	*b_top;
	struct s_stack	*b_bottom;
}	t_lstinfo;

#endif
