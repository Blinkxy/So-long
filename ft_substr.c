/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:01:48 by mzoheir           #+#    #+#             */
/*   Updated: 2022/11/28 22:48:54 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	if (start >= ft_strlen(s) || !s)
		return (ft_strdup(""));
	if (start + len <= ft_strlen(s))
		str = malloc(len + 1);
	else
		str = malloc(ft_strlen(s) - start + 1);
	if (!str)
		return (NULL);
	i = start;
	while (i < (start + len) && s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
