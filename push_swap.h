/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:56:27 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/02 17:56:29 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

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

t_stack	*create_node(int value);
t_stack	*last(t_stack *head);
void	append_node(t_stack **head, int value);

int		is_syntax_err(char **av);
int		contains_duplicate(t_stack *head, int value);
int		print_error(void);

int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
int		ft_isnum(char *nptr);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**split(const char *str, char sep);
int		is_empty(char *str);
void	empty_error(t_stack **stack);
t_stack	*stack_init(int ac, char **av);

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

int		stack_len(t_stack *stack);
void	set_index(t_stack *stack);
void	set_rank(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*get_best_match(t_stack *a, int b_value);
void	set_target_node(t_stack *a, t_stack *b);
int		get_chunk_size(int size);
void	cost_analysis(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);
void	sort_three(t_stack **stack);
void	min_on_top(t_stack **a);
void	push_back_to_a(t_stack **a, t_stack **b);
void	prep_to_push(t_stack **stack, t_stack *cheapest, char c);
void	push_to_b(t_stack **a, t_stack **b);
void	sort_stacks(t_stack **a, t_stack **b);

int		stack_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
#endif