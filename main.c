/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:03:30 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/04 17:27:42 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	check_duplicates(int *input, int len)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < len)
	{
		while (++j < len)
		{
			if (*(input + i) == *(input + j))
				return (0);
		}
	}
	return (1);
}

static int build_stack(t_stack **a,int argc, char const *argv[])
{
	int				i;
	long long int	*input;
	int				error;

	i = -1;
	error = 0;
	input = (long long int*)malloc(sizeof(long long int) * (argc - 1));
	while (++i < argc - 1)
	{
		*(input + i) = long_atoi(argv[i + 1], &error);
		if (error || (*(input + i) > MAX) || (*(input + i) < MIN))
		{
			free(input);
			ft_putstr("Error\n");
			return (0);
		}	
	}
	*a = init_stack(input, argc - 1);
	free(input);
	return (1);
}

int main(int argc, char const *argv[])
{
	t_stack			*stack;
	t_stack			*b_stack;

	b_stack = NULL;
	if (argc > 1) 
	{
		if (!build_stack(&stack, argc, argv))
			return (1);
		sort_stack(&stack, &b_stack);
		printf("\nresult:\n");
		printstack(stack);
		free_stack(b_stack);
		free_stack(stack);
	}
	return 0;
}