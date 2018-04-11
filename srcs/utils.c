/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:54:56 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/10 15:47:27 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

long long int	long_atoi(const char *str, int *error)
{
	int					sign;
	size_t				i;
	long long int		check;

	sign = 1;
	i = 0;
	check = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		check = check * 10 + (str[i] - 48);
		i++;
	}
	if ((i) != ft_strlen(str))
		*error = 1;
	return (check * sign);
}

void			ft_putbignbr(long long nb)
{
	if (nb >= 10 || nb <= -10)
	{
		ft_putbignbr(nb / 10);
		if (nb < 0)
			ft_putchar(-(nb % 10) + '0');
		else
			ft_putchar(nb % 10 + '0');
	}
	else
	{
		if (nb < 0)
			ft_putchar(-(nb % 10) + '0');
		else
			ft_putchar(nb % 10 + '0');
	}
}

int				check_duplicates(long long int *input, int len)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (*(input + i) == *(input + j))
				return (0);
		}
	}
	return (1);
}

int				print_error(long long int *input)
{
	if (input)
		free(input);
	ft_putstr("Error\n");
	return (0);
}

int				build_stack(t_stack **a, int argc, char const *argv[])
{
	int				i;
	long long int	*input;
	int				error;

	i = -1;
	error = 0;
	//printf("argc: %d\n", argc);
	input = (long long int*)malloc(sizeof(long long int) * (argc - 1));
	while (++i < argc - 1)
	{
		*(input + i) = long_atoi(argv[i + 1], &error);
		//printf("%lld\n", *(input+ i));
		if (error || (*(input + i) > MAX) || (*(input + i) < MIN))
			return (print_error(input));
	}
	if (!check_duplicates(input, argc - 1))
		return (print_error(input));
	*a = init_stack(input, argc - 1);
	free(input);
	return (1);
}
