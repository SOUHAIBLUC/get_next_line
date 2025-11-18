/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:57:36 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/18 12:53:01 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


int fill_buffer(int fd, char **reminder)
{
    static char buffers[1024][1024];
    int bytes_read;
    size_t total_len;

    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(*reminder, '\n'))
    {
        total_len = ft_strlen(*reminder);
        if (total_len >= 1024)
            return -1;
        bytes_read = read(fd, buffers[fd], 1024 - total_len);
        if (bytes_read < 0)
            return -1;
        buffers[fd][bytes_read] = '\0';
        if (bytes_read > 0)
        {
            char *temp = *reminder;
            *reminder = ft_strjoin(*reminder, buffers[fd]);
            free(temp);
            if (!*reminder)
                return -1;
        }
    }
    return 0;
}
static char *extract_line(char **reminder)
{
	char (*newline_pos), (*line), (*temp);

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
	if (!line)
		return (NULL);
	return (line);
}

char *read_line(int fd, char **reminder)
{
	if (fill_buffer(fd, &reminder[fd]) == -1)
{
    free(reminder[fd]);
    reminder[fd] = NULL;
    return NULL;
}

	return (extract_line(reminder[fd]));
}

char *get_next_line(int fd)
{
    static char *reminder[1024];
    char *line;

    if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
        return NULL;

    if (!reminder[fd])
        reminder[fd] = ft_strdup("");
    if (!reminder[fd])
        return NULL;

    line = read_line(fd, reminder);
    if (!line)
    {
        free(reminder[fd]);
        reminder[fd] = NULL;
        return NULL;
    }
    return line;
}

