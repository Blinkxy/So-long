/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:59:07 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/11 19:09:18 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

char	*ft_strjoin(char *s1, char *s2, int k, int l)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	k = ft_strlen(s1);
	l = ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	str = ft_calloc(k + l + 1, 1);
	if (!str)
		return (0);
	while (s1[i] && i < k)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && i < l + k && j < l)
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

char	*save_rest(char *stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(stash) - i + 1, 1);
	if (!temp)
		return (NULL);
	if (stash[i] == '\n')
		i++;
	j = 0;
	while (stash[i])
	{
		temp[j++] = stash[i++];
	}
	free(stash);
	return (temp);
}

char	*get_each_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\0';
		i++;
	}
	return (line);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(ft_strlen(s1) + 1, 1);
	if (!str)
		return (NULL);
	while (s1[i] && i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
