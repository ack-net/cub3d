/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:11:59 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:58:01 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_separator(char c, char c2)
{
	if (c == c2 || c == '\0')
		return (1);
	return (0);
}

static int	ft_len(char *str, int from, char c)
{
	int		len;

	len = 0;
	while (!is_separator(str[from + len], c)
			&& str[from + len] != '\0')
		len++;
	return (len);
}

static int	ft_split_size(char *str, char c)
{
	int		split_size;
	int		i;

	if (!str)
		return (0);
	i = 0;
	split_size = 1;
	while (str[i])
	{
		if (!is_separator(str[i + 1], c)
				&& ft_len(str, i + 1, c) > 0)
			split_size += is_separator(str[i], c);
		i++;
	}
	return (split_size);
}

char		**ft_split(const char *str, char c)
{
	char	**splitted;
	int		split_size;
	int		i;
	int		r;
	int		len;

	split_size = ft_split_size((char*)str, c);
	if (!(splitted = malloc(sizeof(splitted) * (split_size + 1))) || !str)
		return (0);
	i = -1;
	r = 0;
	while (r < split_size && str[++i])
	{
		len = 0;
		if (ft_len((char*)str, i, c) > 0)
		{
			splitted[r] = malloc(sizeof(char) * (ft_len((char*)str, i, c) + 1));
			while (!is_separator(str[i], c) && str[i] != '\0')
				splitted[r][len++] = str[i++];
			splitted[r++][len] = '\0';
		}
	}
	splitted[r] = 0;
	return (splitted);
}
