/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infect_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:52:35 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 20:11:49 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	infectos(t_str *data, int *res, int i, int j)
{
	if (data->map_bis[i][j] == 'P' && data->map_bis[i + 1][j] != '1'
		&& data->map_bis[i + 1][j] != 'P' && data->map_bis[i + 1][j] != 'X')
	{
		data->map_bis[i + 1][j] = 'P';
		*res = 1;
	}
	if (data->map_bis[i][j] == 'P' && data->map_bis[i - 1][j] != '1'
		&& data->map_bis[i - 1][j] != 'P' && data->map_bis[i - 1][j] != 'X')
	{
		data->map_bis[i - 1][j] = 'P';
		*res = 1;
	}
}

void	frame_bis(t_str *data, int i, int j)
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
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player,
			data->px, data->py);
}
