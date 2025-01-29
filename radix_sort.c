/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuleumpark <yuleumpark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:59:51 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 00:42:38 by yuleumpark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bit(t_node **stack)
{
	t_node	*head;
	int		max;
	int		max_bit;

	max_bit = 0;
	head = *stack;
	max = (*stack)->index;
	head = head->next;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head -> next;
	}
	while (max >> max_bit != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	max_binary;
	int	j;
	int	max_len;

	i = 0;
	max_len = ft_lstsize2(*stack_a);
	max_binary = max_bit(stack_a);
	while (i < max_binary)
	{
		j = 0;
		while (j < max_len)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_b, stack_a);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

//int main(int argc, char *argv[])
//{
//	t_node **stack_a;
//	t_node **stack_b;

//	stack_a = (t_node **)malloc(sizeof(t_node *));
//	*stack_b = NULL;
//	*stack_a  = stack_init(argc, argv);

//	radix_sort(stack_a, stack_b);
//	return(0);
//}
