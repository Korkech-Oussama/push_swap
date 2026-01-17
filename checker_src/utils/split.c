/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okorkech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:33:09 by okorkech          #+#    #+#             */
/*   Updated: 2026/01/08 09:33:10 by okorkech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static	int	word_count(const char *str, char sep)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
		{
			counter++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (counter);
}

static	char	**empty_s(void)
{
	char	**arr_v;

	arr_v = malloc(sizeof(char *));
	if (!arr_v)
		return (NULL);
	arr_v[0] = NULL;
	return (arr_v);
}

static	void	free_all(char **ar_v, size_t j)
{
	while (j)
		free(ar_v[--j]);
	free(ar_v);
}

static	char	**fill_arr_v(char **arr_v, const char *str, char sep)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		start = i;
		while (str[i] && str[i] != sep)
			i++;
		if (i > start)
		{
			arr_v[j] = ft_substr(str, start, (i - start));
			if (!arr_v[j])
			{
				free_all(arr_v, j);
				return (NULL);
			}
			j++;
		}
	}
	return (arr_v);
}

char	**split(const char *str, char sep)
{
	char	**arr_v;
	int		arr_c;

	if (!str || !*str)
		return (empty_s());
	arr_c = word_count(str, sep);
	arr_v = malloc(sizeof(char *) * (arr_c + 1));
	if (!arr_v)
		return (NULL);
	arr_v[arr_c] = NULL;
	arr_v = fill_arr_v(arr_v, str, sep);
	return (arr_v);
}
