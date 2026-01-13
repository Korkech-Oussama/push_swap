/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:00:40 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/13 19:00:42 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	else
		return (45);
}
void	push_to_b(t_stack **a, t_stack **b)
{
	int	limit;
	int	chunk_size;

	chunk_size = get_chunk_size(stack_len(*a));
	current_index(*a);
	limit = chunk_size;
	while (stack_len(*a) > 3)
	{
		if ((*a)->index < limit)
		{
			pb(b, a);
			if ((*b)->index < limit - (chunk_size /2))
				rb(b);
			if (stack_len(*b) == limit)
				limit += chunk_size;
		}
		else
			ra(a);
	}
}

void	sort_three(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	second = (*stack)->next;
	third = (*stack)->prev;
	if (!stack)
		return ;
	if (first->value > second->value && first->value > third->value)
		ra(stack);
	else if (second->value > first->value && second->value > third->value)
		rra(stack);
	if (first > second)
		ra(stack);
}
