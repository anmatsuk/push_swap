/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:03:30 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/02 16:20:17 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int main(int argc, char const *argv[])
{
	int 			i;
	int				err;
	long long int	*input;
	t_stack			*stack;
	t_stack			*b_stack;

	i = -1;
	err = 0;
	b_stack = NULL;
	input = (long long int*)malloc(sizeof(long long int) * (argc - 1));
	while (++i < argc - 1)
	{
		*(input + i) = long_atoi(argv[i + 1], &err);
		if (err)
		{
			printf("Error\n");
			free(input);
			return (1);
		}	
	}
	if (argc > 1) 
	{
		stack = init_stack(input, argc - 1);
		sort_stack(&stack, &b_stack);
		printf("\nresult:\n");
		printstack(stack);
		free(b_stack);
		free_stack(stack);
	}
	free(input);
	return 0;
}