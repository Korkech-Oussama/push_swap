/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:29:05 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/13 16:29:07 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_rank(t_stack *stack)
{
	t_stack	*head;
	t_stack	*compare;
	int		rank;

	if (!stack)
		return ;
	head = stack;
	while (1)
	{
		rank = 0;
		compare = head;
		while (1)
		{
			if (compare->value < stack->value)
				rank++;
			compare = compare->next;
			if (compare == head)
				break ;
		}
		stack->rank = rank;
		stack = stack->next;
		if (stack == head)
			return ;
	}
}

void	set_index(t_stack *stack)
{
	t_stack	*head;
	int		i;
	int		median;

	if (!stack)
		return ;
	head = stack;
	median = stack_len(stack) / 2;
	i = 0;
	while (1)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		if (stack == head)
			break ;
		i++;
	}
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*b_head;

	if (!a || !b)
		return ;
	b_head = b;
	while (1)
	{
		b->target_node = get_best_match(a, b->value);
		b = b->next;
		if (b == b_head)
			break ;
	}
}

void	cost_analysis(t_stack *a, t_stack *b)
{
	int		cost_total;
	int		b_moves;
	int		a_moves;
	t_stack	*b_head;

	b_head = b;
	while (1)
	{
		if (b->above_median)
			b_moves = b->index;
		else
			b_moves = stack_len(b) - (b->index);
		if (b->target_node->above_median)
			a_moves = b->target_node->index;
		else
			a_moves = stack_len(a) - b->target_node->index;
		cost_total = a_moves + b_moves;
		b->push_cost = cost_total;
		b = b->next;
		if (b == b_head)
			break ;
	}
}

void	set_cheapest(t_stack *b)
{
	t_stack	*b_head;
	t_stack	*best_node;
	long	best_value;

	if (!b)
		return ;
	b_head = b;
	best_value = LONG_MAX;
	while (1)
	{
		b->cheapest = false;
		if (b->push_cost < best_value)
		{
			best_value = b->push_cost;
			best_node = b;
		}
		b = b->next;
		if (b == b_head)
			break ;
	}
	best_node->cheapest = true;
}
