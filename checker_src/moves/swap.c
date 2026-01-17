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

#include "../checker.h"

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
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
