#include "checker.h"

void			ra(struct s_stack *a, struct s_stack *b)
{
	printf("calling %s\n", __func__);
}

void			rb(struct s_stack *a, struct s_stack *b)
{
	printf("calling %s\n", __func__);
}

void			rr(struct s_stack *a, struct s_stack *b)
{
	ra(a, b);
	rb(a, b);
	printf("calling %s\n", __func__);
}
