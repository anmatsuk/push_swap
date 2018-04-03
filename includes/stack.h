# ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct 			s_stack
{
	long long int		value;
	struct s_stack		*next;
}						t_stack;


//methods:
t_stack		*new_stack(long long int value);
void		free_stack(t_stack *head);
int			long_atoi(const char *str, int *error);
t_stack		*init_stack(long long int *input, int len);
void		ft_putbignbr(long long nb);
void		printstack(t_stack *head);
int			is_sorted(t_stack *a, t_stack *b);
void		sort_stack(t_stack **a, t_stack **b);
//commands:
char		*pa(t_stack **a, t_stack **b);
char		*pb(t_stack **a, t_stack **b);
char		*sa(t_stack *a);
char		*sb(t_stack *b);
char		*ss(t_stack *a, t_stack *b);
char		*ra(t_stack **a);
char		*rb(t_stack **b);
char		*rra(t_stack **a);
char		*rrb(t_stack **b);
char		*rrr(t_stack **a, t_stack **b);

#endif