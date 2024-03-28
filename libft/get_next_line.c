/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:22:30 by agpereir          #+#    #+#             */
/*   Updated: 2023/12/06 18:17:29 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_keep(char *buffer)
{
	int		i;
	int		j;
	int		size;
	char	*keep;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	size = ft_strlen(buffer);
	keep = malloc((size - i + 1) * sizeof(char));
	if (!keep)
		return (0);
	i++;
	j = 0;
	while (buffer[i])
		keep[j++] = buffer[i++];
	keep[j] = '\0';
	free(buffer);
	return (keep);
}

char	*get_line_gnl(char *buffer)
{
	int		j;
	int		i;
	char	*line;

	j = 0;
	if (!buffer[j])
		return (0);
	while (buffer[j] && buffer[j] != '\n')
		j++;
	line = (char *)malloc(sizeof(char) * (j + 2));
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[j] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line [i] = '\0';
	return (line);
}

char	*read_line(char *buffer, int fd)
{
	int			bytes;
	char		*curr;

	curr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!curr)
		return (0);
	bytes = 1;
	while (bytes != 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		bytes = read(fd, curr, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(curr);
			free(buffer);
			return (0);
		}
		curr[bytes] = '\0';
		if (!buffer)
			buffer = ft_calloc(1, sizeof(char));
		buffer = ft_strjoin_gnl(buffer, curr);
	}
	free(curr);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_line(buffer, fd);
	if (!buffer)
		return (0);
	line = get_line_gnl(buffer);
	buffer = get_keep(buffer);
	return (line);
}
