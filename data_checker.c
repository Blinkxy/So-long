/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:26:55 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/14 15:21:47 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

void	zeroing_data(t_str *data)
{
	data->coins = 0;
	data->player = 0;
	data->wall = 0;
	data->i = 0;
	data->j = 0;
	data->exit = 0;
	data->counter = 0;
	data->player_c = 0;
	data->exit_c = 0;
	data->x = 0;
	data->y = 0;
}

void	check_extra(char **str, t_str *data)
{
	if (str[data->i][data->j] == 'E')
		(data->exit_c)++;
	if (str[data->i][data->j] == 'C')
		(data->coins_c)++;
	if (str[data->i][data->j] == 'P')
	{
		(data->player_c)++;
		data->px = data->j;
		data->py = data->i;
	}
}

void	init_mlx(t_str *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->j) * 50, (data->counter - 1)
			* 50, "The Legend of Zelda: So_Long");
}

int	escape_key(int key, t_str *data)
{
	(void)data;
	if (key == 53)
	{
		free(data->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	x_close(t_str *data)
{
	free(data->mlx);
	exit(EXIT_SUCCESS);
}
