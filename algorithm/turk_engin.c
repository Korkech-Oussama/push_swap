/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_engin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:53:51 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/16 12:53:55 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	int	limit;
	int	chunk_size;

	chunk_size = get_chunk_size(stack_len(*a));
	set_rank(*a);
	limit = chunk_size;
	while (stack_len(*a) > 3)
	{
		if ((*a)->rank < limit)
		{
			pb(b, a);
			if ((*b)->rank < limit - (chunk_size / 2))
				rb(b);
			if (stack_len(*b) == limit)
				limit += chunk_size;
		}
		else
			ra(a);
	}
}

void	prep_to_push(t_stack **stack, t_stack *cheapest, char c)
{
	if (c == 'a')
	{
		while ((*stack != cheapest) && (cheapest->above_median))
			ra(stack);
		while ((*stack != cheapest) && !(cheapest->above_median))
			rra(stack);
	}
	else if (c == 'b')
	{
		while ((*stack != cheapest) && (cheapest->above_median))
			rb(stack);
		while ((*stack != cheapest) && !(cheapest->above_median))
			rrb(stack);
	}
}

t_stack	*get_cheapest(t_stack **b)
{
	t_stack	*curr_b;

	if (!b || !*b)
		return (NULL);
	curr_b = *b;
	while (1)
	{
		if (curr_b->cheapest)
			return (curr_b);
		curr_b = curr_b->next;
		if (curr_b == *b)
			break ;
	}
	return (NULL);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	if (!a || !b || !*a || !*b)
		return ;
	cheapest = get_cheapest(b);
	if (!cheapest)
		return ;
	while ((*b != cheapest && *a != cheapest->target_node)
		&& (cheapest->above_median && cheapest->target_node->above_median))
		rr(a, b);
	while ((*b != cheapest && *a != cheapest->target_node)
		&& (!cheapest->above_median && !cheapest->target_node->above_median))
		rrr(a, b);
	prep_to_push(a, cheapest->target_node, 'a');
	prep_to_push(b, cheapest, 'b');
	pa(a, b);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	set_index(*a);
	min = find_min(*a);
	prep_to_push(a, min, 'a');
}
