#include "checker.h"

void			rra(struct s_stack *a, struct s_stack *b)
{
	printf("calling %s\n", __func__);
}

void			rrb(struct s_stack *a, struct s_stack *b)
{
	printf("calling %s\n", __func__);
}

void			rrr(struct s_stack *a, struct s_stack *b)
{
	rra(a, b);
	rrb(a, b);
	printf("calling %s\n", __func__);
}
