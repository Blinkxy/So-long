/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:42:46 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/19 13:38:59 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

char	*ft_strnstr(char *haystack, char *needle, int len)
{
	int	j;
	int	i;

	i = 0;
	if (needle[i] == '\0')
		return (haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len && haystack[i + j]
			&& needle[j])
			j++;
		if (j == ft_strlen(needle))
			return (&haystack[i]);
		i++;
	}
	return (NULL);
}
