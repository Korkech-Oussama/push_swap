/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:53:13 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/16 22:53:15 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				rank;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}			t_stack;

// moves
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

t_stack	*create_node(int value);
t_stack	*last(t_stack *head);
void	append_node(t_stack **head, int value);

int		is_syntax_err(char **av);
int		contains_duplicate(t_stack *head, int value);
void	print_error(void);
int		is_empty(char *str);
void	empty_error(t_stack **stack);

int		error_exit(t_stack **a, t_stack **b);

int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
int		ft_isnum(char *nptr);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**split(const char *str, char sep);

t_stack	*stack_init(int ac, char **av);
int		ft_strcmp(const char *s1, const char *s2);

char	*get_next_line(int fd);
int		stack_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
int		stack_len(t_stack *stack);

#endif