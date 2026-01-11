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

#include "../push_swap.h"

void  add_top(t_stack **dest, t_stack *new_node)
{
    t_stack *tail;
    t_stack *first;
    
    first = *dest;
    tail = first->prev;
    new_node->next = first;
    new_node->prev = tail;
    first->prev = new_node;
    tail->next = new_node;
    *dest = new_node;
}

void  push(t_stack **dest, t_stack **src)
{
  t_stack *second;
  t_stack *tail_src;

  if (!*src)
    return ;
  if (!*dest)
  {
    second = (*src)->next;
    tail_src = (*src)->prev;
    (*src)->next = *src;
    (*src)->prev = *src;
    *dest = *src;
    *dest = *src;
    second->prev = tail_src;
    tail_src->next = second;
    *src = second;
  }
  else
  {
      second = (*src)->next;
      tail_src = (*src)->prev;
      add_top(dest,*src);
      second->prev = tail_src;
      tail_src->next = second;
      *src = second;
  }
}
