/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuleumpark <yuleumpark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:15:31 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 01:36:18 by yuleumpark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **to_stack, t_node **from_stack)
{
	t_node	*tmp;

	if (!from_stack || !*from_stack)
		return ;
	tmp = *from_stack;
	*from_stack = (*from_stack)->next;
	ft_lstadd_front2(to_stack, tmp);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
