/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:13:23 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 20:24:40 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	frame_utils(t_str *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 50, i
			* 50);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, j * 50, i
			* 50);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coins, j * 50, i
			* 50);
	if (data->map[i][j] == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy, j * 50, i
			* 50);
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, j * 50, i
			* 50);
}

void	frame_repeat_util(t_str *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 50, i
			* 50);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, j * 50, i
			* 50);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coins, j * 50, i
			* 50);
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->px,
			data->py);
	if (data->map[i][j] == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy, data->ex,
			data->ey);
}
