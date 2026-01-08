/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:24:56 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/08 09:24:58 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*last(t_stack *head)
{
	if (!head)
		return (NULL);
	return (head->prev);
}

void	append_node(t_stack **head, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = create_node(value);
	if (!new_node || !head)
		return ;
	if (!*head)
	{
		*head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last_node = last(*head);
		new_node->prev = last_node;
		new_node->next = *head;
		last_node->next = new_node;
		(*head)->prev = new_node;
	}
}

void	print_list(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		return ;
	temp = head;
	while (1)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
		if (temp == head)
			break ;
	}
}

