/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:52:24 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/05 17:13:34 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char		*rr(t_stack **a, t_stack **b)
{
	if (a && *a)
		ra(a, 0);
	if (b && *b)
		ra(b, 0);
	return ("rr\n");
}

char		*rrb(t_stack **a, t_stack **b)
{
	if(b && *b)
		rra(b, 0);
	a = NULL;
	return ("rrb\n");
}

char		*rrr(t_stack **a, t_stack **b)
{
	if (a && *a)
		rra(a, 0);
	if (b && *b)
		rra(b, 0);
	return ("rrr\n");
}

char		*rb(t_stack **a, t_stack **b)
{
	if (b && *b)
		ra(b, 0);
	a = NULL;
	return ("rb\n");
}

char		*rra(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	t_stack *iter;

	b = NULL;
	if (a && *a && (*a)->next)
	{
		iter = *a;
		while (iter->next)
		{
			tmp = iter;
			iter = iter->next;
		}
		tmp->next = NULL;
		iter->next = *a;
		*a = iter;
	}
	return ("rra\n");
}
