/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 02:41:57 by markik            #+#    #+#             */
/*   Updated: 2022/12/08 02:41:58 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_reading_to_stock(int fd, char *stock)
{
	char	str[BUFFER_SIZE + 1];
	int		count;

	count = 1;
	while (ft_strchr(stock, '\n') == 0 && count != 0)
	{
		count = read(fd, str, BUFFER_SIZE);
		if (count == -1)
			return (0);
		str[count] = '\0';
		if (stock == NULL)
			stock = ft_strdup(str);
		else
			stock = ft_strjoin(stock, str);
	}
	return (stock);
}

char	*ft_liner(char *stock)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	while (stock[j] && stock[j] != '\n')
	{
		str[j] = stock[j];
		j++;
	}
	if (stock[j] == '\n')
	{
		str[j] = '\n';
		str[j + 1] = '\0';
	}
	else
		str[j] = '\0';
	return (str);
}

char	*ft_stockage(char *stock)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stock)
	{
		free(stock);
		return (0);
	}
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!str)
		return (0);
	while (stock[i])
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock = ft_reading_to_stock(fd, stock);
	if (!stock || stock[0] == '\0')
	{
		free(stock);
		return (0);
	}
	line = ft_liner(stock);
	stock = ft_stockage(stock);
	return (line);
}
