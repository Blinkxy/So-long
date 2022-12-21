/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:26:55 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/20 15:50:06 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

void	check_extra(t_str *data)
{
	if (data->map[data->i][data->j] == 'E')
	{
		(data->exit_c)++;
		(data->exit_bis)++;
	}
	if (data->map[data->i][data->j] == 'C')
	{
		(data->coins_c)++;
		(data->coins_bis)++;
	}
	if (data->map[data->i][data->j] == 'P')
	{
		(data->player_c)++;
		data->py = data->i;
		data->px = data->j;
	}
}

void	init_mlx(t_str *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(0);
	data->win = mlx_new_window(data->mlx, (data->j) * 50, (data->i)
			* 50, "The Legend of Zelda: So_Long");
	data->path_player = "textures/player.xpm";
	data->path_wall = "textures/wall.xpm";
	data->path_exit = "textures/exit.xpm";
	data->path_coins = "textures/coins.xpm";
	data->path_dirt = "textures/dirt.xpm";
	data->img_height = 200;
	data->img_width = 200;
	data->player = mlx_xpm_file_to_image(data->mlx, data->path_player,
			&(data->img_width), &(data->img_height));
	data->wall = mlx_xpm_file_to_image(data->mlx, data->path_wall,
			&data->img_width, &data->img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx, data->path_exit,
			&data->img_width, &data->img_height);
	data->coins = mlx_xpm_file_to_image(data->mlx, data->path_coins,
			&data->img_width, &data->img_height);
	data->dirt = mlx_xpm_file_to_image(data->mlx, data->path_dirt,
			&data->img_width, &data->img_height);
	first_frame(data);
}

int	escape_key(int key, t_str *data)
{
	(void)data;
	if (key == 53)
		exit_free(data);
	return (0);
}

int	x_close(t_str *data)
{
	exit_free(data);
	return (0);
}

int	exit_free(t_str *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->coins);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->dirt);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
	return (0);
}
