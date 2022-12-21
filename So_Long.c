/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:02:46 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/20 15:49:52 by mzoheir          ###   ########.fr       */
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

void	f_check_sub(t_str *data)
{
	if (data->map[data->i][data->j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, data->x,
			data->y);
	if (data->map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, data->x,
			data->y);
	if (data->map[data->i][data->j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->j
			* 50, data->i * 50);
		data->py = (data->i) * 50;
		data->px = (data->j) * 50;
	}
	if (data->map[data->i][data->j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coins, data->x,
			data->y);
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
			f_check_sub(data);
			data->x += 50;
		}
		data->y += 50;
	}
}

void	full_check(t_str *data)
{
	if (validmap(data) == 0)
	{
		ft_printf("INVALID MAP !!!\n");
		exit(EXIT_FAILURE);
	}
	if (valid_path(data) == 0)
	{
		ft_printf("INVALID PATH !!!\n");
		exit(EXIT_FAILURE);
	}
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
			return (0);
		ft_checkmap(av[1], data);
		ft_checkmap_bis(av[1], data);
		if (!data->map)
			return (0);
		if (!data->map_bis)
			return (0);
		full_check(data);
		init_mlx(data);
		frame_check(data);
		mlx_looping(data);
	}
	return (0);
}
