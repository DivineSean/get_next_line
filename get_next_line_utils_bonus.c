/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:02:35 by markik            #+#    #+#             */
/*   Updated: 2022/12/10 01:02:41 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char		*dest;
	size_t		src_size;

	src_size = ft_strlen(src);
	dest = malloc(sizeof (char) * (src_size + 1));
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpy(dest, src);
	return (dest);
}

void	ft_strcat(char *str, char *dest, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[j])
	{
		str[i] = dest [i];
		i++;
		j++;
	}
	j = 0;
	while (src[j])
	{
		str[i] = src[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	char	*str;

	len = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	str = (char *)malloc(sizeof (char) * len);
	if (!str)
		return (0);
	ft_strcat(str, (char *)s1, (char *)s2);
	free(s1);
	return (str);
}
