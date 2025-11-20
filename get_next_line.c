/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:27:27 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/20 13:30:47 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_and_return(char *ptr, int ret_value)
{
	if (ptr)
		free(ptr);
	return (ret_value);
}

static int	fill_buffer(int fd, char **reminder)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(*reminder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_return(buffer, -1));
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
		{
			temp = *reminder;
			*reminder = ft_strjoin(*reminder, buffer);
			free(temp);
			if (!*reminder)
				return (free_and_return(buffer, -1));
		}
	}
	return (free_and_return(buffer, 0));
}

static char	*extract_line(char **reminder)
{
	char	*newline_pos;
	char	*line;
	char	*temp;

	if (!*reminder || !**reminder)
		return (NULL);
	newline_pos = ft_strchr(*reminder, '\n');
	if (newline_pos)
	{
		line = ft_strndup(*reminder, newline_pos - *reminder + 1);
		if (!line)
			return (NULL);
		temp = *reminder;
		*reminder = ft_strdup(newline_pos + 1);
		free(temp);
		if (!*reminder)
			return (free(line), NULL);
	}
	else
	{
		line = ft_strdup(*reminder);
		free(*reminder);
		*reminder = NULL;
	}
	return (line);
}

char	*read_line(int fd, char **reminder)
{
	if (fill_buffer(fd, reminder) == -1)
		return (NULL);
	return (extract_line(reminder));
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!reminder)
		reminder = ft_strdup("");
	if (!reminder)
		return (NULL);
	line = read_line(fd, &reminder);
	if (!line)
	{
		free(reminder);
		reminder = NULL;
		return (NULL);
	}
	return (line);
}
