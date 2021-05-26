/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:08:27 by antheven          #+#    #+#             */
/*   Updated: 2021/04/22 16:05:14 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_append_read(char *fds[65535], int fd, int bs)
{
	char	*buffer;
	char	*swap;
	int		i;

	buffer = malloc(bs + 1 * sizeof(char));
	i = bs + 1;
	while (i > 0)
		*(buffer + --i) = 0;
	i = read(fd, buffer, bs);
	if (!fds[fd])
	{
		fds[fd] = malloc(1);
		*fds[fd] = '\0';
	}
	swap = fds[fd];
	fds[fd] = ft_strjoin(swap, buffer);
	free(swap);
	free(buffer);
	return (i <= 0 ? i : 1);
}

int		get_next_line(int fd, char **line)
{
	static	char	*fds[65535];
	char			*tmp;
	int				line_len;
	int				eof;

	eof = 1;
	while (!ft_strchr(fds[fd], '\n') && eof > 0)
		eof = ft_append_read(fds, fd, BUFFER_SIZE);
	if (eof >= 0)
	{
		if (eof == 0)
			line_len = ft_strchr(fds[fd], '\0') - fds[fd];
		else
			line_len = ft_strchr(fds[fd], '\n') - fds[fd];
		if (!(*line = malloc((line_len + 1) * sizeof(char))))
			return (-1);
		else
			ft_memcpy(*line, fds[fd], line_len + 1);
		if (eof > 0)
			*(ft_strchr(*line, '\n')) = '\0';
		tmp = eof == 0 ? 0 : ft_strdup(ft_strchr(fds[fd], '\n') + 1);
		free(fds[fd]);
		fds[fd] = eof == 0 ? 0 : tmp;
	}
	return (eof);
}