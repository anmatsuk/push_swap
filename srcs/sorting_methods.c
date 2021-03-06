/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:59:38 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/10 17:28:47 by amatsuk          ###   ########.fr       */
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
	return (a);
}

void			push_max(t_stack **aa, t_stack **bb)
{
	t_stack *first;
	t_stack *last;
	t_stack *next;
	t_stack *b;

	b = *bb;
	if (b && b->next)
	{
		next = b->next;
		first = b;
		b = get_last_element(b);
		last = get_last_element(*aa);
		if (b->value > first->value && b->value >= next->value)
		{
			if (aa && (*aa) && ((*aa)->value > last->value))
				ft_putstr(rrr(aa, bb));
			else
				ft_putstr(rrb(0, bb));
			push_max(aa, bb);
		}
		else if (next->value > first->value && next->value > b->value)
		{
			if (next->next && ((next->next)->value > (b)->value)
				&& ((next->next)->value > first->value))
			{
				ft_putstr(rb(0, aa));
				push_max(aa, bb);
			}
			else
				ft_putstr(sb(0, bb));
		}
		ft_putstr(pa(aa, bb));
	}
	else if (b)
		ft_putstr(pa(aa, bb));
}

void			push_min(t_stack **aa, t_stack **bb)
{
	t_stack *first;
	t_stack *last;
	t_stack *next;
	t_stack *a;
	t_stack *b;

	a = *aa;
	b = *bb;
	if (a && a->next)
	{
		next = a->next;
		first = a;
		b = get_last_element(b);
		last = get_last_element(*aa);
		if (last->value <= first->value && last->value <= next->value)
		{
			if ((*bb) && b && (b->value > (*bb)->value))
				ft_putstr(rrr(aa, bb));
			else
				ft_putstr(rra(aa, 0));
			push_min(aa, bb);
		}
		else if (next->value < first->value && next->value < last->value)
		{
			if (next->next && ((next->next)->value < last->value)
				&& ((next->next)->value < first->value))
			{
				ft_putstr(ra(aa, 0));
				push_min(aa, bb);
			}
			else
				ft_putstr(sa(aa, 0));
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
	ft_putstr(sa(aa, 0));
	return (1);
}

/*
void		sort_stack(t_stack **a, t_stack **b)
{
	if (!a || !*a || !((*a)->next))
		return ;
	while ((*a)->next && (!is_sorted(*a, *b) && !is_stack_sorted(*a)))
	{
		if (!is_rev_sorted(a))
			push_min(a, b);
	}
	while ((*b) && (*b)->next && !is_sorted(*a, *b))
		push_max(a, b);
	if (is_sorted(*a, *b))
	{
		while (*b)
			ft_putstr(pa(a, b));
	}
	else
	{
		if (is_stack_sorted(*a) && is_stack_sorted(*b) && !is_sorted(*a, *b))
			push_max(a, b);
		sort_stack(a, b);
	}
}

*/
//---------------------------- v.2 -------------------------
void		init_elements(t_stack **stack, t_stack **last, t_stack **next, t_stack **nnext)
{
	*last = get_last_element(*stack);
	*next = (*stack)->next;
	*nnext = (*next)->next;
}

void		buble_min(t_stack **a, t_stack **b)
{
	t_stack *last;
	t_stack *next;
	t_stack *nnext;
	t_stack *first;

	first = *a;
	if (is_sorted(*a, *b))
		return ;
	init_elements(a, &last, &next, &nnext);

	if (last->value < first->value && last->value <= next->value) //last (rra or rrr)
	{
		if (*b && (*b)->next && (*b)->value < (get_last_element(*b))->value) /// rrr
			ft_putstr(rrr(a, b));
		else
			ft_putstr(rra(a, b));
		buble_min(a, b);
	}
	else if (next->value < first->value && next->value < last->value)//next (sa or ra)
	{
		if (nnext && first->value < last->value && first->value >= nnext->value) //ra or rr
		{
			if ((*b) && (*b)->next && (*b)->value < (get_last_element(*b))->value && (*b)->value < ((*b)->next)->value)
				ft_putstr(rr(a, b));
			else
				ft_putstr(ra(a, b));
			buble_min(a, b);
		}
		else
		{
			if (*b && (*b)->next && (*b)->value < ((*b)->next)->value)
				ft_putstr(ss(a, b));
			else
				ft_putstr(sa(a, b));
		}
	}
}

void		buble_max(t_stack **a, t_stack **b)
{
	t_stack *last;
	t_stack *next;
	t_stack *nnext;
	t_stack *first;

	first = *b;
	if (is_sorted(*a, *b))
		return ;
	init_elements(b, &last, &next, &nnext);
	if (last->value > first->value && last->value >= next->value) //last (rra or rrr)
	{
		if (*a && (*a)->next && (*a)->value > (get_last_element(*a))->value) /// rrr
			ft_putstr(rrr(a, b));
		else
			ft_putstr(rrb(a, b));
		buble_max(a, b);
	}
	else if (next->value > first->value && next->value > last->value)//next (sa or ra)
	{
		if (nnext && first->value > last->value && first->value <= nnext->value) //ra or rr
		{
			if ((*a) && (*a)->next && (*a)->value < (get_last_element(*a))->value && (*a)->value < ((*a)->next)->value)
				ft_putstr(rr(a, b));
			else
				ft_putstr(rb(a, b));
			buble_max(a, b);
		}
		else
		{
			if (*a && (*a)->next && (*a)->value < ((*a)->next)->value)
				ft_putstr(ss(a, b));
			else
				ft_putstr(sb(a, b));
		}
	}
}


void process_min(t_stack **a, t_stack **b) //min on the head of the a
{
	if (*b && (*b)->next)
	{
	}
	ft_putstr(pb(a, b));
}

void process_max(t_stack **a, t_stack **b) //min on the head of the a
{
	if (*a && (*a)->next)
	{
	}
	ft_putstr(pa(a, b));
}

void		sort_stack(t_stack **a, t_stack **b)
{
	// push min to b
	while ((*a)->next && (!is_sorted(*a, *b)) && (!is_stack_sorted(*a)))
	{
		
		buble_min(a, b);
		if (!is_sorted(*a, *b))
			process_min(a, b);
	}
	// push max to a
	while ((*b) && (*b)->next && (!is_sorted(*a, *b)))
	{
		buble_max(a, b);
		if (!is_sorted(*a, *b))
			process_max(a, b);
	}
	if (is_sorted(*a, *b))
	{
		while (*b)
			ft_putstr(pa(a, b));
	}
	else
		sort_stack(a, b);
	//https://github.com/Matt-Hurd/42-push_swap
}

