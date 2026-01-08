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

int	main(int ac, char *av[])
{
	t_stack *stack_a;

	stack_a = stack_init(ac, av);
	if (!stack_a)
		return (0);
	print_list(stack_a);
	free(stack_a);
	return (0);
}
