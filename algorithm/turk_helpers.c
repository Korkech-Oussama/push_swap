/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:22:51 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/15 18:22:53 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (36);
	else
		return (70);
}

int	stack_len(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	if (!stack)
		return (0);
	i = 0;
	temp = stack;
	while (1)
	{
		i++;
		temp = temp->next;
		if (temp == stack)
			break ;
	}
	return (i);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*head;
	t_stack	*min_node;
	int		min;

	if (!stack)
		return (NULL);
	min = stack->value;
	min_node = stack;
	head = stack;
	while (1)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (min_node);
}

t_stack	*get_best_match(t_stack *a, int b_value)
{
	t_stack	*node;
	t_stack	*curr_a;
	long	best_match;

	curr_a = a;
	best_match = LONG_MAX;
	while (1)
	{
		if (curr_a->value > b_value && curr_a->value < best_match)
		{
			best_match = curr_a->value;
			node = curr_a;
		}
		curr_a = curr_a->next;
		if (curr_a == a)
			break ;
	}
	if (best_match == LONG_MAX)
		node = find_min(a);
	return (node);
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_node(a, b);
	cost_analysis(a, b);
	set_cheapest(b);
}
