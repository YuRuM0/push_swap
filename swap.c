/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuleumpark <yuleumpark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:49:18 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 00:45:27 by yuleumpark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*one;
	t_node	*two;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	one = *stack;
	two = (*stack)->next;
	one->next = two->next;
	two->next = one;
	*stack = two;
	write(1, "sa\n", 3);
}

//int main(int argc, char *argv[])
//{
//	t_node **stack_a;

//	stack_a = (t_node **)malloc(sizeof(t_node *));
//	*stack_a  = stack_init(argc, argv);
//	swap(stack_a);
//	while((*stack_a))
//	{
//		printf("%d\n", (*stack_a) -> val);
//		(*stack_a)=(*stack_a)->next;
//	}
//	return(0);
//}
