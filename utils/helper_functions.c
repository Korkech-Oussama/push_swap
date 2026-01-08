/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:33:24 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/08 09:33:25 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *nptr)
{
	size_t		j;
	long		res;
	int			sign;

	j = 0;
	sign = 1;
	res = 0;
	while (nptr && ((nptr[j] >= 9 && nptr[j] <= 13) || (nptr[j] == 32)))
		j++;
	if (nptr && (nptr[j] == '-' || nptr[j] == '+'))
	{
		if (nptr && (nptr[j] == '-'))
			sign = -1;
		j++;
	}
	while (nptr && ft_isdigit(nptr[j]))
	{
		res = res * 10 + (nptr[j] - '0');
		j++;
	}
	return (res * sign);
}

int	ft_isnum(char *nptr)
{
	int	i;

	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		i++;
	if (nptr[i] == '\0')
		return (1);
	return (0);
}
