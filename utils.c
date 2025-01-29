/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuleumpark <yuleumpark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:54:39 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 00:46:11 by yuleumpark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back2(t_node **lst, t_node *new)
{
	t_node	*end;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		end = ft_lstlast2(*lst);
		end -> next = new;
	}
}

void	ft_lstadd_front2(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	new -> next = *lst;
	*lst = new;
}

t_node	*ft_lstlast2(t_node *lst)
{
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}

t_node	*ft_lstnew2(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node -> val = content;
	node -> next = NULL;
	return (node);
}

int	ft_lstsize2(t_node *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		lst = lst -> next;
		counter++;
	}
	return (counter);
}
