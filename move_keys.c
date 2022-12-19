/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:58:53 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/19 22:34:40 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

void	frame_all(int key, t_str *data)
{
	first_frame(data);
	move_to_wall(key, data);
	frame_coins(key, data);
	frame_exit(key, data);
}

void	move_sub(int key, t_str *data)
{
	if (key == 124 && data->map[(data->py) / 50][((data->px) / 50) + 1] != '1')
	{
		data->px += 50;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->px,
			data->py);
	}
	if (key == 123 && data->map[(data->py) / 50][((data->px) / 50) - 1] != '1')
	{
		data->px -= 50;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->px,
			data->py);
	}
}

int	move_player(int key, t_str *data)
{
	frame_all(key, data);
	move_sub(key, data);
	if (key == 126 && data->map[((data->py) / 50) - 1][((data->px)
			/ 50)] != '1')
	{
		data->py -= 50;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->px,
			data->py);
	}
	if (key == 125 && data->map[((data->py) / 50) + 1][((data->px)
			/ 50)] != '1')
	{
		data->py += 50;
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->px,
			data->py);
	}
	return (0);
}

void	move_to_wall(int key, t_str *data)
{
	if (key == 124 && data->map[(data->py) / 50][((data->px) / 50) + 1] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->px,
			data->py);
	if (key == 123 && data->map[(data->py) / 50][((data->px) / 50) - 1] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->px,
			data->py);
	if (key == 126 && data->map[((data->py) / 50) - 1][((data->px)
			/ 50)] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->px,
			data->py);
	if (key == 125 && data->map[((data->py) / 50) + 1][((data->px)
			/ 50)] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->px,
			data->py);
}

void	frame_coins(int key, t_str *data)
{
	if (key == 124 && data->map[(data->py) / 50][((data->px) / 50) + 1] == 'C')
	{
		data->map[(data->py) / 50][((data->px) / 50) + 1] = '0';
		first_frame(data);
		data->coins_c--;
	}
	if (key == 123 && data->map[(data->py) / 50][((data->px) / 50) - 1] == 'C')
	{
		data->map[(data->py) / 50][((data->px) / 50) - 1] = '0';
		data->coins_c--;
		first_frame(data);
	}
	if (key == 125 && data->map[((data->py) / 50) + 1][(data->px) / 50] == 'C')
	{
		data->map[((data->py) / 50) + 1][(data->px) / 50] = '0';
		data->coins_c--;
		first_frame(data);
	}
	if (key == 126 && data->map[((data->py) / 50) - 1][((data->px)
			/ 50)] == 'C')
	{
		data->map[((data->py) / 50) - 1][((data->px) / 50)] = '0';
		data->coins_c--;
		first_frame(data);
	}
}
