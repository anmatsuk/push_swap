/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:50:40 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/02 17:53:31 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char		*pb(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (a && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
	return ("pb\n");
}

char		*pa(t_stack **a, t_stack **b)
{
	pb(b, a);
	return ("pa\n");
}

char		*sa(t_stack *a)
{
	long long int tmp;

	if (a && a->next)
	{
		tmp = a->value;
		a->value = (a->next)->value;
		(a->next)->value = tmp;
	}
	return ("sa\n");
}

char		*sb(t_stack *b)
{
	sa(b);
	return ("sb\n");
}

char		*ss(t_stack *a, t_stack *b)
{
	sa(a);
	sa(b);
	return ("ss\n");
}
