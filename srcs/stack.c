/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:52:13 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/11 15:37:00 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char		*ra(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	t_stack *iter;

	b = NULL;
	if (a && *a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		iter = *a;
		while (iter->next)
			iter = iter->next;
		iter->next = tmp;
		tmp->next = NULL;
	}
	return ("ra\n");
}

t_stack		*new_stack(long long int value)
{
	t_stack *s;

	s = (t_stack*)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->value = value;
	s->next = NULL;
	s->v = 1;
	s->len = 1;
	return (s);
}

t_stack		*init_stack(long long int *input, int len)
{
	t_stack *tmp;
	t_stack *n;
	t_stack *head;
	int		i;

	head = new_stack(*input);
	tmp = head;
	i = 0;
	while (++i < len)
	{
		n = new_stack(*(input + i));
		tmp->next = n;
		tmp = tmp->next;
	}
	return (head);
}

void		free_stack(t_stack *head)
{
	t_stack *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void		printstack(t_stack *head)
{
	t_stack *tmp;

	tmp = head;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->len);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
