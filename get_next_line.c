/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:27:27 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/15 17:27:30 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char *ft_alloc_and_check(size_t size)
{
	char *ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}
static int fill_buffer(int fd, char **reminder)
{
	char *buffer;
	int bytes_read;

	buffer = ft_alloc_and_check(BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(*reminder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
		{
			char *temp = *reminder;
			*reminder = ft_strjoin(*reminder, buffer);
			free(temp);
		}
	}
	free(buffer);
	return (0);
}
static char *extract_line(char **reminder)
{
	char *newline_pos;
	char *line;
	char *temp;

	newline_pos = ft_strchr(*reminder, '\n');
	if (newline_pos)
	{
		line = ft_strndup(*reminder, newline_pos - *reminder + 1);
		temp = *reminder;
		*reminder = ft_strdup(newline_pos + 1);
		free(temp);
	}
	else if (ft_strlen(*reminder) > 0)
	{
		line = ft_strdup(*reminder);
		if (!line)
			return (NULL);
		temp = *reminder;
		free(temp);
		*reminder = NULL;
	}
	else
		return (NULL);
	if (!line || !*reminder)
		return (NULL);
	return (line);
}

char *read_line(int fd, char **reminder)
{
	if (fill_buffer(fd, reminder) == -1)
		return (NULL);
	return (extract_line(reminder));
}

char *get_next_line(int fd)
{
    static char *reminder = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!reminder)
        reminder = ft_strdup("");
    line = read_line(fd, &reminder);
    if (!line)
    {
        free(reminder);
        reminder = NULL;
        return (NULL);
    }
    return (line);
}
