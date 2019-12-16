void exc_ops(struct s_pushswap *p_s, int iter, int top_group, int bot_group)
{
	t_stack *source;
	int nodes;

	source = (iter % 2) ? p_s->a : p_s->b;
	nodes = source->size + 1;
	while (--nodes > 0)
	{
		if (index == top_group)
		{
			if (iter % 2)
				pb;
			else
				pa;
		}
		else if (index == bot_group)
		{
			if (iter % 2)
			{
				pb;
				rb;
			}
			else
			{
				pa;
				ra;
			}
		}
		else
		{
			if (iter % 2)
				ra;
			else
				rb;
		}
	}
}

void general_radix(struct s_pushswap *p_s)
{
	int flips;
	int top_group;
	int bot_group;
	int j;
	int i;

	flips = log_ceil(p_s->a->size,p_s->gsize);
	j = -1;

	while (++j < flips)
	{
		i = (p_s->gsize + 1) / 2 + 1;
		top_group = (j % 2) ? p_s->gsize / 2 : (p_s->gsize - 1) / 2;
		bot_group = (j % 2) ? top_group - 1 : top_group + 1;
		while (--i > 0)
		{
			exc_ops(p_s, j, top_group, bot_group);
			top_group = (j % 2) : top_group + 1 ? top_group - 1;
			bot_group = (j % 2) : bot_group - 1 ? bot_group + 1;
		}
	}

}