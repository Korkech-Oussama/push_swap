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


void	push_to_b(t_stack **a, t_stack **b)
{
	int		index;
	int		len;
	t_stack	*temp;

	len = stack_len(*a);
	current_index(*a);
	while (len > 3)
	{

		
		len--;
	}
	
}

void	sort_three(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = stack;
	second = stack->next;
	third = stack->prev;
	if (!stack)
		return ;
	if (first->value < second->value)
		sa(&stack);
	else if (second->value < third->value)
		rra(&stack);
}
