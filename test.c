/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:54:20 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/13 18:40:36 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

void	ff(t_str *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->dirt, 0, 0);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall, j
						* 50, i * 50);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit, j
						* 50, i * 50);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->coins, j
						* 50, i * 50);
			j++;
		}
		i++;
	}
}
