/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 22:48:20 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/08 22:48:23 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	add_top(t_stack **dest, t_stack *new_node)
{
	new_node->next = *dest;
	new_node->prev = (*dest)->prev;
	(*dest)->prev->next = new_node;
	(*dest)->prev = new_node;
	*dest = new_node;
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_push;

	if (!*src)
		return ;
	node_push = *src;
	if (node_push->next == node_push)
		*src = NULL;
	else
	{
		node_push->prev->next = node_push->next;
		node_push->next->prev = node_push->prev;
		*src = node_push->next;
	}
	if (!*dest)
	{
		node_push->next = node_push;
		node_push->prev = node_push;
		*dest = node_push;
	}
	else
		add_top(dest, node_push);
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
}
