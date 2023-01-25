/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:02:46 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 20:15:57 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	first_frame(t_str *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->dirt, 0, 0);
	while ((data->map[i]))
	{
		j = 0;
		while (data->map[i][j])
		{
			frame_utils(data, i, j);
			j++;
		}
		i++;
	}
}

void	f_check_sub(t_str *data)
{
	if (data->map[data->i][data->j] == 'P')
	{
		data->py = (data->i) * 50;
		data->px = (data->j) * 50;
	}
	if (data->map[data->i][data->j] == 'X')
	{
		data->ey = (data->i) * 50;
		data->ex = (data->j) * 50;
	}
}

void	frame_check(t_str *data)
{
	data->i = 0;
	while (data->map[(data->i)])
	{
		data->j = 0;
		while (data->map[data->i][(data->j)])
		{
			f_check_sub(data);
			data->j++;
		}
		data->i++;
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
	{
		ft_printf("Invalid number of arguments !\n");
		exit(EXIT_FAILURE);
	}
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
		frame_check(data);
		init_mlx(data);
		first_frame(data);
		mlx_looping(data);
	}
	return (0);
}
