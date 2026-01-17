/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:28:13 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/03 13:28:16 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (stack_sorted(*a))
		return ;
	if (len == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (len == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_init(ac, av);
	stack_b = NULL;
	if (!stack_a)
		return (0);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
