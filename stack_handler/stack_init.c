/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:17:45 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/08 19:17:47 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*curr;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	head = *stack;
	curr = head;
	while (1)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
		if (curr == head)
			break ;
	}
	*stack = NULL;
}

int	append_args(t_stack **stack, char **args)
{
	long	val;
	int		j;

	if (is_syntax_err(args))
		return (1);
	j = 0;
	while (args[j])
	{
		val = ft_atol(args[j]);
		if (contains_duplicate(*stack, val))
			return (1);
		append_node(stack, (int)val);
		j++;
	}
	return (0);
}

t_stack	*stack_init(int ac, char **av)
{
	t_stack	*stack_a;
	char	**args;
	int		i;

	if (ac < 2)
		return (NULL);
	if (!av)
		return (NULL);
	stack_a = NULL;
	i = 1;
	while (av[i])
	{
		args = split(av[i], ' ');
		if (!args || append_args(&stack_a, args))
		{
			free_args(args);
			free_stack(&stack_a);
			return (print_error(), NULL);
		}
		free_args(args);
		i++;
	}
	return (stack_a);
}
