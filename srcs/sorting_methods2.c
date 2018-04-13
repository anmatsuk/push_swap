/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_methods2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:52:42 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/11 18:06:16 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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

int			vector_count(t_stack *a)
{
	int c;

	c = 0;
	while (a)
	{
		if (a->len)
			c++;
		a = a->next;
	}
	return (c);
}

t_stack			*get_last_element(t_stack *a)
{
	while (a && a->next)
		a = a->next;
	return (a);
}

int			stack_len(t_stack *a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void		merge_to_a(t_stack **a, t_stack **b, int direct, int loc) // 1 - max down, 0 - max -up
{
	t_stack *last;
	int		total;
	int		up;
	int		down;
	int		ll;

	last = get_last_element(*a);
	down = last->len;
	up = (*a)->len;
	total = (vector_count(*a) == 1 ? 1 : up + down);
	ll = total;
	printf("direct: %d\n", direct);
	printf("total: %d\n", total);
	while (total > 0 && *a)
	{
		if (up && down)
		{
			
			last = get_last_element(*a);
			printf("direct: %d\n", direct);
			printf("both!!!! compare : %lld and %lld\n",(*a)->value , last->value);
			
			if ((!direct && (*a)->value < last->value) || (direct && ((*a)->value > last->value)))
			{
				ft_putstr(rra(a, b));
				down--;	
			}
			else
				up--;
		}
		else if (up)
			up--;
		else if (down)
		{
			ft_putstr(rra(a, b));
			down--;
		}
		ft_putstr(pb(a, b));
		if (loc && ll)
		{
			(*b)->len = ll;
			ll = 0;
		}
		else
			(*b)->len = 0;
		total--;
	}
	if (!loc)
		(*b)->len = ll;
}

int			get_direction(int len, int iter, int step)
{
	int c;

	c = (len % 2 == 0 ? len / 2 : (len / 2) + 1);
	if ((c) % 2 == 0)
		return (iter % 2);
	else
	{
		if (iter <= (len / (2 * step)))
			return ((iter % 2));
		else if (iter == (len / (2 * step)) + 1)
			return (0);
		else
			return ((iter % 2 == 0 ? 1 : 0));
	}
}

int			get_location(int step, int iter, int len)
{
	int c;

	c = (len % 2 == 0 ? len / 2 : (len / 2) + 1);
	if (c % 2 == 0)
		return (iter <= (len / (2 * step)) ? 0 : 1);
	else
		return (iter <= (len / (2 * step)) + 1 ? 0 : 1);//1 down
}




void		merge_sort(t_stack **a, t_stack **b)
{
	int 	len;
	int 	step;
	int		direct;
	int		iter;

	//len = stack_len(*a);
	step = 2;
	while (step != 4)
	{
		len = vector_count(*a);
		iter = (len % step == 0 ? len / step : (len / step) + 1);
		while (iter > 0)
		{
			direct = get_direction(len, iter, step);
			printf("direct: %d\n", direct);
			merge_to_a(a, b, direct, get_location(step, iter, len));
			iter--;
		}
		
		len = vector_count(*b);
		iter = (len % step == 0 ? len / step : (len / step) + 1);
		while (iter > 0)
		{
			direct = get_direction(len, iter, step);
			//printf("direct: %d\n", direct);
			merge_to_a(b, a, direct, get_location(step, iter, len));
			iter--;
			printstack(*a);
			printf("\nlen: %d\n", len);
			printstack(*b);
		}
		
		step += step; 
	}
	step = stack_len(*b);
}

void		sort_stack(t_stack **a, t_stack **b)
{
	int len;
	printstack(*a);
	len = stack_len(*a);
	if (len > 7)
		merge_sort(a, b);
	printstack(*a);
	printf("\nlen: %d\n", len);
	printstack(*b);
}