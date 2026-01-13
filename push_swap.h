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
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}			t_stack;

t_stack	*create_node(int value);
t_stack	*last(t_stack *head);
void	append_node(t_stack **head, int value);
void	print_list(t_stack *head);

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

t_stack	*stack_init(int ac, char **av);

#endif