/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:40:58 by amatsuk           #+#    #+#             */
/*   Updated: 2018/04/05 19:09:00 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

# define MIN (-2147483648)
# define MAX 2147483647

typedef struct 			s_stack
{
	long long int		value;
	struct s_stack		*next;
}						t_stack;

typedef char* (*t_func)(t_stack**, t_stack**);

//methods:
void			init_functions(t_func *func);
t_func			get_function(char *s);
int				check_duplicates(long long int *input, int len);
int				build_stack(t_stack **a,int argc, char const *argv[]);
int				print_error(long long int *input);
t_stack			*new_stack(long long int value);
void			free_stack(t_stack *head);
long long int	long_atoi(const char *str, int *error);
t_stack			*init_stack(long long int *input, int len);
void			ft_putbignbr(long long nb);
void			printstack(t_stack *head);
int				is_sorted(t_stack *a, t_stack *b);
void			sort_stack(t_stack **a, t_stack **b);
int				is_stack_sorted(t_stack *a);
//commands:
char			*pa(t_stack **a, t_stack **b);
char			*pb(t_stack **a, t_stack **b);
char			*sa(t_stack **a, t_stack **b);
char			*sb(t_stack **a, t_stack **b);
char			*ss(t_stack **a, t_stack **b);
char			*ra(t_stack **a, t_stack **b);
char			*rb(t_stack **a, t_stack **b);
char			*rr(t_stack **a, t_stack **b);
char			*rra(t_stack **a, t_stack **b);
char			*rrb(t_stack **a, t_stack **b);
char			*rrr(t_stack **a, t_stack **b);

#endif