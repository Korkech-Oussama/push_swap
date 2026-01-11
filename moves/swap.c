/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:15:54 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/09 09:15:56 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*tail;
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*head || !(*head)->next || *head == (*head)->next)
		return ;
	if ((*head)->next->next != *head)
	{
		first = *head;
		tail = first->prev;
		second = first->next;
		third = second->next;
		second->next = first;
		first->prev = second;
		first->next = third;
		second->prev = tail;
		third->prev = first;
		tail->next = second;
		*head = second;
	}
	else
		*head = (*head)->next;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
