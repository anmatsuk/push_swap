/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:54:56 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/04 17:31:17 by amatsuk          ###   ########.fr       */
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
