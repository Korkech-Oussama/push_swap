/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:52:20 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/16 22:52:22 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_commands(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		sa(a);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(command, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b);
	else
		error_exit(a, b);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (ac < 2)
		return (0);
	stack_a = stack_init(ac, av);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		parse_commands(&stack_a, &stack_b, line);
		free(line);
	}
	if (stack_sorted(stack_a) && stack_len(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
