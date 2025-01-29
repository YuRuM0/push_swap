/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:19:37 by yulpark           #+#    #+#             */
/*   Updated: 2025/01/25 17:24:04 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_newlist(int val)
{
	t_node	*new_list;

	new_list = malloc(sizeof(t_node));
	if (!new_list)
		return (NULL);
	new_list -> val = val;
	new_list -> index = 0;
	new_list -> next = NULL;
	return (new_list);
}

static t_node	*ft_lstend(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

static t_node	*ft_addbehind(t_node *stack, t_node *new)
{
	t_node	*end;

	if (stack)
	{
		end = ft_lstend(stack);
		end -> next = new;
		new -> next = NULL;
	}
	else
	{
		stack = new;
		new->next = NULL;
	}
	return (stack);
}

static t_node	*rank_finder(t_node *stack_init)
{
	t_node	*min;
	t_node	*head;

	if (ft_lstsize2(stack_init) == 1)
	{
		free_single_stack(stack_init);
		exit(0);
	}
	head = stack_init;
	min = stack_init;
	stack_init = stack_init -> next;
	while (min)
	{
		if (stack_init->val > min->val)
			stack_init->index++;
		if (stack_init -> next)
			stack_init = stack_init -> next;
		else
		{
			stack_init = head;
			min = min -> next;
		}
	}
	return (head);
}

t_node	*stack_init(int argc, char *argv[])
{
	char	**args;
	int		i;
	t_node	*new;
	t_node	*a;

	a = NULL;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i++;
		args = argv;
	}
	while (args[i])
	{
		new = ft_newlist(ft_atoi(args[i]));
		a = ft_addbehind(a, new);
		i++;
	}
	if (argc == 2)
		ft_free(args);
	a = rank_finder(a);
	return (a);
}

//int main(int argc, char*argv[])
//{
//	t_node *a;
//	t_node *tmp;

//	a = stack_init(argc, argv);
//	while (a != NULL)
//	{
//		printf("%d\n", a->index);
//		a = a->next;
//	}
//}
