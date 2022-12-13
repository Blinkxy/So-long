/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:22:17 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/08 21:59:16 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     char *s1 = "yolq";
//     char *s2 = "yolq";
//     printf("%d",ft_strncmp(s1,s2,4));
//     return(0);
// }