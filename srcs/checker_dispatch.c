/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:45:26 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/05 17:05:46 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int		get_function_index(char *cmd)
{
	char	commands[11][4] =
	{"pa","pb","sa","sb","ss","ra","rb","rr","rra","rrb","rrr"};
	int		i;

	i = -1;
	while (++i < 11)
	{
		if ((ft_strlen(commands[i]) == ft_strlen(cmd)) &&
			(!ft_strcmp(commands[i], cmd)))
			return (i);
	}
	return (-1);
}

void			init_functions(t_func *func)
{
	func[0] = &pa;
	func[1] = &pb;
	func[2] = &sa;
	func[3] = &sb;
	func[4] = &ss;
	func[5] = &ra;
	func[6] = &rb;
	func[7] = &rr;
	func[8] = &rra;
	func[9] = &rrb;
	func[10] = &rrr;
}

t_func			get_function(char *cmd)
{
	static t_func *func;
	int		index;

	if (cmd)
	{
		index = get_function_index(cmd);
		if (index == -1)
			return (0);
		if (!func)
		{
			if (!(func = ft_memalloc(sizeof(t_func) * 11)))
			return (0);
		}
		init_functions(func);
		return (func[index]);
	}
	return (0);
}