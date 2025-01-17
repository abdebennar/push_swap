/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abennar <abennar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:29:39 by abennar           #+#    #+#             */
/*   Updated: 2024/01/15 15:29:01 by abennar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*eter_line(char **line)
{
	char	*str;
	char	*r_line;
	int		i;

	if (!line || !*line)
		return (NULL);
	str = *line;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	r_line = ft_strndup(str, i);
	*line = ft_strndup((str + i), ft_strlen(str + i));
	m_free(str);
	return (r_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	ssize_t		r;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483424)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (m_free(line), line = NULL, NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (m_free(line), line = NULL, NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (!buff)
			break ;
		buff[r] = '\0';
		line = strjoin(line, buff);
		if (detect_n(buff))
			break ;
	}
	m_free(buff);
	return (eter_line(&line));
}
