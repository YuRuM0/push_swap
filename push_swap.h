/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:21:25 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 22:37:27 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_combined/libft.h"
# include <limits.h>

typedef struct s_node
{
	int					val;
	int					index;
	struct s_node		*next;
}	t_node;

//utils
void	ft_lstadd_back2(t_node **lst, t_node *new);
void	ft_lstadd_front2(t_node **lst, t_node *new);
t_node	*ft_lstlast2(t_node *lst);
t_node	*ft_lstnew2(int content);
int		ft_lstsize2(t_node *lst);

//stack_init
t_node	*stack_init(int argc, char *argv[]);

//moves
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rra(t_node **stack_a);
void	swap(t_node **stack);

//radix_sort
void	radix_sort(t_node **stack_a, t_node **stack_b);

// errors
int		write_error(void);
int		is_sorted(t_node **stack);
int		ft_isnum(char *val);
int		ft_contains(char *argv[], int i, int val);
void	ft_free(char **str);

// more errors
int		if_empty(char *str);

//low_sort
void	low_sort(t_node **stack_a, t_node **stack_b);

//low_sort_utils
int		min_push(t_node **stack_a, int min);

//main
long	ft_atol(const char *nptr);
void	input_check(int argc, char *argv[], int i);
void	free_stack(t_node **stack);
void	free_single_stack(t_node *stack);
int		main(int argc, char *argv[]);

#endif
