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

char    *read_line(int fd, char **reminder)
{
	char *buffer;
	int bytes_read;
	char *newline_pos;
	char *line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(*reminder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
			*reminder = ft_strjoin(*reminder, buffer);
		if (!*reminder)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	newline_pos = ft_strchr(*reminder, '\n');
	*reminder = ft_strdup(newline_pos + 1); // check if newlinepos = "ksajhas\n";
	if(!*reminder)
		return (NULL);

char	*get_next_line(int fd)
{
	static char *reminder;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		line = read_line(fd, &reminder);
	if (!line)
		return (NULL);
	return (line);
}
