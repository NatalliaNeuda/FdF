/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:57:31 by nneuda            #+#    #+#             */
/*   Updated: 2019/11/01 12:14:26 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_string(char **s, int fd)
{
	int		len;
	char	*tmp;
	char	*new_str;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		new_str = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(&s[fd][len + 1]);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else
	{
		new_str = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (new_str);
}

int			get_next_line(const int fd, char **line)
{
	static char *s[8192];
	char		buff[BUFF_SIZE + 1];
	int			bytes_read;
	char		*tmp;

	if (!line || fd < 0)
		return (-1);
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (bytes_read < 0)
		return (-1);
	else if (bytes_read == 0 && s[fd] == NULL)
		return (0);
	*line = find_string(s, fd);
	return (1);
}
