/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:55:44 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/05 19:28:22 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	execute_command(char *cmd, t_stack **a, t_stack **b)
{
	t_func f;
	if (!(f= get_function(cmd)))
	{
		print_error(0);
		free_stack(*a);
		free_stack(*b);
		exit(0);
	}
	else
	{
		f(a, b);
		//printstack(*a);
	}
}

int 		main(int argc, char const *argv[])
{
	t_stack *a;
	t_stack *b;
	char	buf[100];
	char	*line;
	//size_t	k;

	line = NULL;
	*buf = '\0';
	b = NULL;
	if (argc == 1)
		return (0);
	//	return (print_error(0));
	if (!build_stack(&a, argc, argv))
		return (1);
	//while((k = read(0, buf, 3))>0)
	while (get_next_line(0,&line) != 0)
	{
		if (line)
			execute_command(line, &a, &b);
	}
	if (!b && is_stack_sorted(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}