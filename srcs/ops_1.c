#include "checker.h"

void			sa(struct s_stack *a, struct s_stack *b)
{
	int *tmp;

	if (a->size >= 2)
	{
		tmp = a->top->content;
		a->top->content = a->top->next->content;
		a->top->next->content = tmp;
	}
	printf("calling %s\n", __func__);
}

void			sb(struct s_stack *a, struct s_stack *b)
{
	int *tmp;

	if (b->size >= 2)
	{
		tmp = b->top->content;
		b->top->content = b->top->next->content;
		b->top->next->content = tmp;
	}
	printf("calling %s\n", __func__);
}

void			ss(struct s_stack *a, struct s_stack *b)
{
	sa(a, b);
	sb(a, b);
	printf("calling %s\n", __func__);
}

void			pa(struct s_stack *a, struct s_stack *b)
{
	if (b->size)
		push(a, pop(b));
	printf("calling %s\n", __func__);
}

void			pb(struct s_stack *a, struct s_stack *b)
{
	if (a->size)
		push(b, pop(a));
	printf("calling %s\n", __func__);
}