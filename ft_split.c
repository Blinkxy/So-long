/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:36 by mzoheir           #+#    #+#             */
/*   Updated: 2022/11/28 22:47:22 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

static int	count_strings(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**allocation(char *s, int i, char c, char **str)
{
	int	len;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			len = 0;
			while (s[i + len] != '\0' && s[i + len] != c)
				len++;
			str[j] = ft_substr(s, i, len);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		len;
	char	**str;
	int		str_count;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	if (!s)
		return (NULL);
	str_count = count_strings(s, c);
	str = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (!str)
		return (NULL);
	allocation(s, i, c, str);
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char		*str;
// 	char		c;

// 	char		**s;
// 	str = "Hello, si;o, marouane";
// 	c = ',';

// 	s = ft_split(str, c);
// 	for(int i = 0; i<4;i++)
// 		printf("%s\n",s[i]);
// 	return (0);
// }
