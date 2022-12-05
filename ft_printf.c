/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:43:28 by mzoheir           #+#    #+#             */
/*   Updated: 2022/11/28 22:50:37 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(p, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_argprint(p, s[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	va_end(p);
	return (count);
}
// int main(void)
// {
// ft_printf("%s", "");
// }
// //     // printf(" NULL %s NULL ", NULL);
// // //     // printf("%d",i);
// // //     return (i);
// // }
