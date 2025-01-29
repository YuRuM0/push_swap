/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuleumpark <yuleumpark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:50:13 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 01:46:52 by yuleumpark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_push(t_node **stack_a, int min)
{
	t_node	*head;
	int		counter;

	counter = 0;
	head = *stack_a;
	while (head)
	{
		if (head->index == min)
			return (counter);
		else
		{
			head = head->next;
			counter++;
		}
	}
	return (counter);
}
