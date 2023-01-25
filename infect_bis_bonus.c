/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infect_bis_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:52:35 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 20:18:59 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	repeat_frame(t_str *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->dirt, 0, 0);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			frame_repeat_util(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	paths(t_str *data)
{
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
	data->enemy = mlx_xpm_file_to_image(data->mlx, data->path_enemy,
			&data->img_width, &data->img_height);
}

int	enemy_moves(t_str *data)
{
	int			i;
	int static	num;

	if (num == 6000)
	{
		printf("%d\n", num);
		srand(time(NULL));
		i = rand() % 4;
		enemy_sub(data, i);
		enemy_sub_bis(data, i);
		repeat_frame(data);
	}
	if (num > 6000)
		num = 0;
	num++;
	return (0);
}

void	enemy_sub(t_str *data, int i)
{
	if (i == 0)
	{
		if (data->map[(data->ey) / 50][((data->ex) / 50) - 1] != '1'
			&& data->map[(data->ey) / 50][((data->ex) / 50) - 1] != 'E'
			&& data->map[(data->ey) / 50][((data->ex) / 50) - 1] != 'C')
			data->ex -= 50;
		if (data->px == data->ex && data->py == data->ey)
		{
			ft_printf("You LOSE !!!\n");
			exit_free(data);
		}
	}
	if (i == 1)
	{
		if (data->map[(data->ey) / 50][((data->ex) / 50) + 1] != '1'
			&& data->map[(data->ey) / 50][((data->ex) / 50) + 1] != 'E'
			&& data->map[(data->ey) / 50][((data->ex) / 50) + 1] != 'C')
			data->ex += 50;
		if (data->px == data->ex && data->py == data->ey)
		{
			ft_printf("You LOSE !!!\n");
			exit_free(data);
		}
	}
}

void	enemy_sub_bis(t_str *data, int i)
{
	if (i == 2)
	{
		if (data->map[((data->ey) / 50) - 1][((data->ex) / 50)] != '1'
			&& data->map[((data->ey) / 50) - 1][((data->ex) / 50)] != 'E'
			&& data->map[((data->ey) / 50) - 1][((data->ex) / 50)] != 'C')
			data->ey -= 50;
		if (data->px == data->ex && data->py == data->ey)
		{
			ft_printf("You LOSE !!!\n");
			exit_free(data);
		}
	}
	if (i == 3)
	{
		if (data->map[((data->ey) / 50) + 1][((data->ex) / 50)] != '1'
			&& data->map[((data->ey) / 50) + 1][((data->ex) / 50)] != 'E' &&
			data->map[((data->ey) / 50) + 1][((data->ex) / 50)] != 'C')
			data->ey += 50;
		if (data->px == data->ex && data->py == data->ey)
		{
			ft_printf("You LOSE !!!\n");
			exit_free(data);
		}
	}
}
