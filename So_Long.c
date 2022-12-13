/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:02:46 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/13 20:00:28 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

void	first_frame(t_str *data)
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

void	frame_check(t_str *data)
{
	data->i = -1;
	while (data->map[++(data->i)])
	{
		data->x = 0;
		data->j = -1;
		while (data->map[data->i][++(data->j)])
		{
			if (data->map[data->i][data->j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall,
						data->x, data->y);
			if (data->map[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit,
						data->x, data->y);
			if (data->map[data->i][data->j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->player,
						data->j * 50, data->i * 50);
				data->py = (data->i) * 50;
				data->px = (data->j) * 50;
			}
			if (data->map[data->i][data->j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->coins,
						data->x, data->y);
			data->x += 50;
		}
		data->y += 50;
	}
}

void	path_images_mlx(t_str *data)
{
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

int	main(int ac, char **av)
{
	t_str	*data;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (valid_mapfile(av[1]))
	{
		data = (t_str *)ft_calloc(1, sizeof(t_str));
		if (!data)
			exit(EXIT_FAILURE);
		ft_checkmap(av[1], data);
		if (!data->map)
			return (0);
		if (validmap(data) == 0)
		{
			ft_printf("INVALID MAP !!!\n");
			exit(EXIT_FAILURE);
		}
		init_mlx(data);
		path_images_mlx(data);
		frame_check(data);
		mlx_looping(data);
	}
	return (0);
}
