/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:13:06 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/29 17:04:44 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

void	input_check(int argc, char *argv[], int i)
{
	long	tmp;
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		if (!args[i][0])
			write_error();
		tmp = ft_atol(args[i]);
		if (!ft_isnum(args[i]) || ft_contains(args, i, tmp))
			write_error();
		if (tmp < -2147483648 || tmp > 2147483647)
			write_error();
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

void	free_stack(t_node **stack)
{
	t_node	*head;
	t_node	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}

void	free_single_stack(t_node *stack)
{
	t_node	*head;
	t_node	*temp;

	head = stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	main(int argc, char *argv[])
{
	t_node	**stack_a;
	t_node	**stack_b;
	int		i;

	if (argc < 2)
		return (0);
	if (!argv[1][0] || !if_empty(argv[1]))
		write_error();
	i = 0;
	input_check(argc, argv, i);
	stack_b = malloc(sizeof(t_node));
	stack_a = malloc(sizeof(t_node));
	*stack_b = NULL;
	*stack_a = NULL;
	*stack_a = stack_init(argc, argv);
	if (!is_sorted(stack_a))
	{
		if (ft_lstsize2(*stack_a) < 6)
			low_sort(stack_a, stack_b);
		else
			radix_sort(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
