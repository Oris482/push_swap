/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:40:57 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/20 17:38:18 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# define LLONG_MAX 9223372036854775807LL
# define INT_MAX 2147483647LL
# define INT_MIN -2147483648LL

typedef struct s_stack
{
	long long		value;
	int				idx;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lstinfo
{
	struct s_stack		*a_top;
	struct s_stack		*a_bottom;
	struct s_stack		*b_top;
	struct s_stack		*b_bottom;
	size_t				arg_cnt;
	struct s_command	*lst_command;
}	t_lstinfo;

typedef struct s_command
{
	char				command[4];
	struct s_command	*prev;
	struct s_command	*next;
}	t_command;

t_stack		*parse_num_list(int argc, char **argv);
int			print_error(void);
t_lstinfo	*lst_fclean(t_lstinfo *lstinfo);
int			record_command(t_lstinfo *lstinfo, char *command);
int	check_sorted(t_lstinfo *lstinfo, int pos, int qty);
void	arg_indexing(t_lstinfo *lstinfo);

int			func_sa(t_lstinfo *lstinfo);
int			func_sb(t_lstinfo *lstinfo);
int			func_pa(t_lstinfo *lstinfo);
int			func_pb(t_lstinfo *lstinfo);
int			func_ra(t_lstinfo *lstinfo);
int			func_rb(t_lstinfo *lstinfo);
int			func_rra(t_lstinfo *lstinfo);
int			func_rrb(t_lstinfo *lstinfo);

int	sort_abc(t_lstinfo *lstinfo, int pos);
int	sort_acb(t_lstinfo *lstinfo, int pos);
int	sort_bac(t_lstinfo *lstinfo, int pos);
int	sort_bca(t_lstinfo *lstinfo, int pos);
int	sort_cab(t_lstinfo *lstinfo, int pos);
int	sort_cba(t_lstinfo *lstinfo, int pos);

#endif
