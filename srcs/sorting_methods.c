/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:59:38 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/03 15:23:56 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			is_sorted(t_stack *a, t_stack *b)
{
	t_stack *tail;

	tail = b;
	while (b && b->next)
	{
		if (b->value < (b->next)->value)
			return (0);
		b = b->next;
	}
	if (tail && a && (a->value < tail->value))
		return (0);
	while (a && a->next)
	{
		if (a->value > (a->next)->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int				is_stack_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > (a->next)->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack			*get_last_element(t_stack *a)
{
	while (a && a->next)
		a = a->next;
	return a;
}

void			push_max(t_stack **aa, t_stack **bb)
{
	t_stack 	*first;
	t_stack 	*last;
	t_stack 	*next;
	t_stack		*a;
	t_stack		*b;

	b = *aa;
	a = *bb;
	if (a && a->next)
	{
		next = a->next;
		first = a;
		a = get_last_element(a);
		last = get_last_element(*aa);
		if (last->value > first->value && last->value >= next->value)
		{
			if ((*aa) && a && (a->value > (*aa)->value))
				ft_putstr(rrr(aa, bb));
			else
				ft_putstr(rrb(bb));
		}
		else if (next->value > first->value && next->value > last->value)
		{
			if (next->next && (next->next)->next && ((next->next)->value > last->value)
				&& ((next->next)->value > first->value))
				ft_putstr(rb(aa));
			else
				ft_putstr(sb(*aa));
		}
		ft_putstr(pa(aa, bb));
	}
}

void			push_min(t_stack **aa, t_stack **bb)
{
	t_stack 	*first;
	t_stack 	*last;
	t_stack 	*next;
	t_stack		*a;
	t_stack		*b;

	a = *aa;
	b = *bb;
	if (a && a->next)
	{
		next = a->next;
		first = a;
		b = get_last_element(b);
		last = get_last_element(*aa);
		 if (last->value < first->value && last->value <= next->value)
		{
			if ((*bb) && b && (b->value > (*bb)->value))
				ft_putstr(rrr(aa, bb));
			else
				ft_putstr(rra(aa));
		}
		else if (next->value < first->value && next->value < last->value)
		{
			if (next->next && (next->next)->next && ((next->next)->value < last->value)
				&& ((next->next)->value < first->value))
				ft_putstr(ra(aa));
			else
				ft_putstr(sa(*aa));
		}
		if (!is_stack_sorted(*aa))
				ft_putstr(pb(aa, bb));
	}
}

int			is_rev_sorted(t_stack **aa)
{
	t_stack			*a;
	long long int	v;
	long long int	vnext;

	a = *aa;
	while (a && a->next)
	{	
		v = a->value;
		vnext = (a->next)->value;	
		if (v < vnext)
			return (0);
		a = a->next;
	}
	ft_putstr(sa(*aa));
	return (1);
}

void		sort_stack(t_stack **a, t_stack **b)
{
	if (!a || !*a || !((*a)->next))
		return ;
	while ((*a)->next && (!is_sorted(*a, *b) && !is_stack_sorted(*a)))
	{
		is_rev_sorted(a);
		push_min(a, b);
	}
	while ((*b) && (*b)->next && !is_sorted(*a, *b))
	{
		push_max(a, b);
	  
	}
	if (is_sorted(*a, *b))
	{
		while (*b)
			ft_putstr(pa(a, b));
	}
	else
	{
		if (is_stack_sorted(*a) && is_stack_sorted(*b))
			ft_putstr(pa(a, b));		
		//sort_stack(a, b);
	}
}
