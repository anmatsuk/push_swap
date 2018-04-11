/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:03:30 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/10 15:24:34 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int main(int argc, char const *argv[])
{
	t_stack			*stack;
	t_stack			*b_stack;

	b_stack = NULL;
	if (argc > 1) 
	{
		if (!build_stack(&stack, argc, argv))
			return (1);
		if (stack && stack->next)
			sort_stack(&stack, &b_stack);
		//printf("\nresult:\n");
		//printstack(stack);
		free_stack(b_stack);
		free_stack(stack);
	}
	return 0;
}
