/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuleumpark <yuleumpark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:15:38 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 00:43:57 by yuleumpark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tail;

	if (!*stack || (*stack)->next == NULL)
		return ;
	else
	{
		tail = ft_lstlast2(*stack);
		tmp = *stack;
		*stack = tmp->next;
		tmp -> next = NULL;
		tail->next = tmp;
	}
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rra(t_node **stack)
{
	t_node	*tail;
	t_node	*second_last;

	if (!*stack || (*stack)->next == NULL)
		return ;
	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	tail = ft_lstlast2(*stack);
	second_last->next = NULL;
	tail->next = *stack;
	*stack = tail;
	write(1, "rra\n", 4);
}
//int main(int argc, char* argv[])
//{
//	t_node **stack_a = (t_node **)malloc(sizeof(t_node *));
//	*stack_a = stack_init(argc, argv);
//	rra(stack_a);
//	while((*stack_a))
//	{
//		printf("%d\n", (*stack_a) -> val);
//		(*stack_a)=(*stack_a)->next;
//	}
//	return(0);
//}
