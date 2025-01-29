/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:29:23 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 16:35:23 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_sort(t_node **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap(stack_a);
}

static void	three_sort(t_node **stack_a, int min, int min2)
{
	if ((*stack_a)->index == min)
	{
		ra(stack_a);
		swap(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->index == min2)
	{
		if ((*stack_a)->next->index != min)
			rra(stack_a);
		else
			swap(stack_a);
	}
	else
	{
		if ((*stack_a)->next->index == min)
			ra(stack_a);
		else
		{
			swap(stack_a);
			rra(stack_a);
		}
	}
}

// counter comes from min push
static void	four_sort(t_node **stack_a, t_node **stack_b, int m)
{
	int	counter;

	counter = min_push(stack_a, m);
	if (counter < 2)
	{
		while (counter)
		{
			ra(stack_a);
			counter--;
		}
	}
	else
	{
		while (counter < 4)
		{
			rra(stack_a);
			counter++;
		}
	}
	if (!is_sorted(stack_a))
	{
		pb(stack_b, stack_a);
		three_sort(stack_a, m + 1, m + 2);
		pa(stack_a, stack_b);
	}
}

static void	five_sort(t_node **stack_a, t_node **stack_b, int ct)
{
	if (ct < 2)
	{
		while (ct)
		{
			ra(stack_a);
			ct--;
		}
	}
	else
	{
		while (ct < 5)
		{
			rra(stack_a);
			ct++;
		}
	}
	pb(stack_b, stack_a);
	if (!is_sorted(stack_a))
		four_sort(stack_a, stack_b, 1);
	pa(stack_a, stack_b);
}

void	low_sort(t_node **stack_a, t_node **stack_b)
{
	int	counter;

	counter = min_push(stack_a, 0);
	if (ft_lstsize2(*stack_a) == 1)
		write_error();
	else if (ft_lstsize2(*stack_a) == 2)
		two_sort(stack_a);
	else if (ft_lstsize2(*stack_a) == 3)
		three_sort(stack_a, 0, 1);
	else if (ft_lstsize2(*stack_a) == 4)
		four_sort(stack_a, stack_b, 0);
	else if (ft_lstsize2(*stack_a) == 5)
		five_sort(stack_a, stack_b, counter);
}

//int main(int argc, char *argv[])
//{
//	t_node **stack_a;
//	t_node **stack_b;
//	int counter;

//	stack_a = (t_node **)malloc(sizeof(t_node *));
//	*stack_a  = stack_init(argc, argv);
//	stack_b = (t_node **)malloc(sizeof(t_node *));
//	stack_b = NULL;

//	low_sort(stack_a, stack_b);
//	free_stack(stack_a);
//	free_stack(stack_a);
//	return(0);
//	}
