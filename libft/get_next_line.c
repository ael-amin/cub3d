/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:49:03 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/07/28 10:02:56 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_own(char *s1, char *s2)
{
	char	*str;
	int		size;

	if (!s1)
		s1 = ft_strdup("");
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[size] = '\0';
	free(s1);
	return (str);
}

char	*get_buff(int fd, char *sub)
{
	char	*buff;
	int		i;

	buff = (char *)malloc(sizeof(char ) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			break ;
		buff[i] = '\0';
		sub = ft_strjoin_own(sub, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (sub);
}

char	*get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[0])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_substr(buff, 0, i + 1);
	return (line);
}

char	*get_sub(char *buff)
{
	char	*sub;
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	i++;
	sub = ft_substr(buff, i, ft_strlen(buff) - i);
	free(buff);
	return (sub);
}

char	*get_next_line(int fd)
{
	static char	*sub;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sub = get_buff(fd, sub);
	if (!sub)
		return (NULL);
	line = get_line(sub);
	sub = get_sub(sub);
	return (line);
}
