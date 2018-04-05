/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:55:44 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/04 19:12:18 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	execute_command(char *cmd, t_stack **stack)
{
	int i;

	i = -1;
	if (!cmd)
		return ;
	while (*(cmd + i) != '\n')
		i++;
	*(cmd + i) = '\0';
	
	printf("%s\n", cmd);

}

int main(int argc, char const *argv[])
{
	t_stack *stack;
	char	buf[100];
	size_t	k;

	*buf = '\0';
	//if (argc )
	//	return (print_error(0));
	if (!build_stack(&stack, argc, argv))
		return (1);
	while((k = read(0, buf, 100))>1)
	{
		execute_command(buf, &stack);
	}
	return 0;
}