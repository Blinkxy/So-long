/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:26:55 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 19:34:26 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (data->map[data->i][data->j] == 'X')
	{
		data->ey = data->i;
		data->ex = data->j;
	}
}

void	init_mlx(t_str *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(0);
	data->win = mlx_new_window(data->mlx, (data->j) * 50, (data->i) * 50,
			"The Legend of Zelda: So_Long");
	data->path_player = "textures/player.xpm";
	data->path_wall = "textures/wall.xpm";
	data->path_exit = "textures/exit.xpm";
	data->path_coins = "textures/coins.xpm";
	data->path_dirt = "textures/dirt.xpm";
	data->path_enemy = "textures/enemy.xpm";
	data->img_height = 200;
	data->img_width = 200;
	paths(data);
}

int	escape_key(int key, t_str *data)
{
	(void)data;
	if (key == 53)
	{
		ft_printf("Game manually closed: Escape\n");
		exit_free(data);
	}
	return (0);
}

int	x_close(t_str *data)
{
	ft_printf("Game manually closed: Red cross\n");
	exit_free(data);
	return (0);
}

int	exit_free(t_str *data)
{
	int	i;

	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->coins);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->dirt);
	mlx_destroy_image(data->mlx, data->enemy);
	mlx_destroy_window(data->mlx, data->win);
	i = 0;
	while (data->map[i] && data->map_bis[i])
	{
		free(data->map[i]);
		free(data->map_bis[i]);
		i++;
	}
	free(data->map);
	free(data->map_bis);
	free(data);
	exit(0);
	return (0);
}
