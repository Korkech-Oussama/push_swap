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

int	stack_sorted(t_stack *stack)
{
	t_stack	*head;

	if (!stack)
		return (1);
	head = stack;
	while (stack->next != head)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
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
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	push_to_b(a, b);
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		push_back_to_a(a, b);
	}
	min_on_top(a);
}
