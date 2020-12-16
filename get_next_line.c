/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:33:47 by nblackbu          #+#    #+#             */
/*   Updated: 2020/12/13 14:18:38 by nblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_po(char **ostatok, char **line)
{
	char	*p_n;
	char	*vr_perem;

	if ((p_n = ft_strchr(*ostatok, '\n')))
	{
		*p_n = '\0';
		*line = ft_strdup(*ostatok);
		++p_n;
		vr_perem = *ostatok;
		*ostatok = ft_strdup(p_n);
		free(vr_perem);
		if (*line == NULL || *ostatok == NULL)
			return (-1);
		return (1);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

int		ft_read_of_file(int fd, char *buf, char **line, char **ostatok)
{
	int			pr_byte;
	char		*vr_perem;
	int			v;

	while ((pr_byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[pr_byte] = '\0';
		if (*ostatok == NULL)
			*ostatok = ft_strdup("");
		vr_perem = *ostatok;
		*ostatok = ft_strjoin(vr_perem, buf);
		free(vr_perem);
		if (*ostatok == NULL)
			return (-1);
		if (1 == (v = ft_po(ostatok, line)))
			break ;
		else if (v == -1)
			return (-1);
	}
	if (pr_byte > 0)
		return (1);
	else if (pr_byte < 0)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*ostatok;
	int			output;
	char		*buf;
	int			v;

	if (line == NULL || BUFFER_SIZE < 1 || -1 == (v = ft_po(&ostatok, line))
	|| fd < 0 || NULL == (buf = (char *)malloc(1 * (BUFFER_SIZE + 1))))
		return (-1);
	if (v == 1)
	{
		free(buf);
		return (1);
	}
	output = ft_read_of_file(fd, buf, line, &ostatok);
	free(buf);
	if (output != 0 || ostatok == NULL || ostatok[0] == '\0')
	{
		if (output == 0)
			*line = ft_strdup("");
		return (output);
	}
	*line = ostatok;
	ostatok = NULL;
	return (output);
}
