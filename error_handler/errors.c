/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:09:44 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/08 09:09:46 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_syntax_err(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_isnum(av[i]))
			return (1);
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	contains_duplicate(t_stack *head, int value)
{
	t_stack	*temp;

	if (!head)
		return (0);
	temp = head;
	while (1)
	{
		if (temp->value == value)
			return (1);
		temp = temp->next;
		if (temp == head)
			break ;
	}
	return (0);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
