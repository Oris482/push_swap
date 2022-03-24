#include "push_swap.h"
#include <stdio.h>

int	display_stack(t_lstinfo *lstinfo)
{
	t_stack		*tmp_b;
	t_stack		*tmp_a;

	tmp_a = lstinfo->a_top;
	tmp_b = lstinfo->b_top;
	printf("\n#####Stack A#####\n");
	while (tmp_a)
	{
		printf("%d ", tmp_a->idx);
		tmp_a = tmp_a->next;
	}
	printf("\n#####Stack B#####\n");
	while (tmp_b)
	{
		printf("%d ", tmp_b->idx);
		tmp_b = tmp_b->next;
	}
	printf("\n");
	return (1);
}
