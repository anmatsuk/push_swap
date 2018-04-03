/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:52:24 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/02 17:54:24 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char		*rr(t_stack **a, t_stack **b)
{
	ra(a);
	ra(b);
	return ("rr\n");
}

char		*rrb(t_stack **b)
{
	rra(b);
	return ("rrb\n");
}

char		*rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rra(b);
	return ("rrr\n");
}

char		*rb(t_stack **b)
{
	ra(b);
	return ("rb\n");
}

char		*rra(t_stack **a)
{
	t_stack *tmp;
	t_stack *iter;

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
