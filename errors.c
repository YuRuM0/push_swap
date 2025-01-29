/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:11:44 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 21:55:31 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head->next)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_contains(char *argv[], int i, int val)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == val)
			return (1);
		i++;
	}
	return (0);
}

void	ft_free(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_isnum(char *val)
{
	int	i;

	i = 0;
	if (val[0] == '-' && val[1] == '\0')
		return (0);
	if (val[0] == '-')
		i++;
	while (val[i])
	{
		if (!ft_isdigit(val[i]))
			return (0);
		i++;
	}
	return (1);
}
