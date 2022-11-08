/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:30:52 by greita            #+#    #+#             */
/*   Updated: 2022/02/07 10:33:52 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_split_lines(char *ptr_n, char **line, char **lines)
{
	char	*temp;

	*ptr_n = '\0';
	*line = ft_strjoin(*lines, "\n");
	temp = ft_strdup(ptr_n + 1);
	free(*lines);
	*lines = temp;
}

static char	*ft_get_line(char **lines)
{
	char	*temp;
	char	*line;
	char	*ptr_n;

	ptr_n = ft_strchr(*lines, '\n');
	if (!ptr_n && **lines)
	{
		temp = *lines;
		*lines = NULL;
		return (temp);
	}
	else if (!**lines)
	{
		free(*lines);
		return (*lines = NULL);
	}
	ft_split_lines(ptr_n, &line, lines);
	if (!line)
		return (NULL);
	if (!*lines)
	{
		free(line);
		return (line = NULL);
	}
	return (line);
}

static int	ft_read_buf(int fd, ssize_t *bytes, char **lines)
{
	char	*temp;
	char	buf[BUFFER_SIZE + 1];

	*bytes = read(fd, buf, BUFFER_SIZE);
	if (*bytes <= 0)
		return (0);
	buf[*bytes] = '\0';
	temp = ft_strjoin(*lines, buf);
	free(*lines);
	*lines = temp;
	return (1);
}

char	*ft_get_nextline(int fd)
{
	static char		*lines = NULL;
	ssize_t			bytes;

	if (fd < 0)
		return (NULL);
	bytes = 0;
	if (!lines)
	{
		lines = malloc(sizeof(*lines));
		if (!lines)
			return (NULL);
		*lines = '\0';
	}
	while (!ft_strchr(lines, '\n') && ft_read_buf(fd, &bytes, &lines))
		if (!lines)
			return (NULL);
	if (bytes < 0)
	{
		free(lines);
		return (lines = NULL);
	}
	return (ft_get_line(&lines));
}
