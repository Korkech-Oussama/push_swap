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

void	current_index(t_stack *stack)
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