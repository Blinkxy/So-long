/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:05:59 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/14 16:08:55 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

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

void	frame_exit(int key, t_str *data)
{
	if (key == 124 && data->map[(data->py) / 50][((data->px) / 50) + 1] == 'E'
		&& data->coins_c == 0)
	{
		ft_printf("YOU WIN !!!");
		exit(EXIT_SUCCESS);
	}
	if (key == 123 && data->map[(data->py) / 50][((data->px) / 50) - 1] == 'E'
		&& data->coins_c == 0)
	{
		ft_printf("YOU WIN !!!");
		exit(EXIT_SUCCESS);
	}
	if (key == 125 && data->map[((data->py) / 50) + 1][(data->px) / 50] == 'E'
		&& data->coins_c == 0)
	{
		ft_printf("YOU WIN !!!");
		exit(EXIT_SUCCESS);
	}
	if (key == 126 && data->map[((data->py) / 50) - 1][((data->px) / 50)] == 'E'
		&& data->coins_c == 0)
	{
		ft_printf("YOU WIN !!!");
		exit(EXIT_SUCCESS);
	}
}

int	valid_path(t_str *data)
{
	int	i;
	int	j;

	i = 1;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i+1][j] != '1')
				data->map[i+1][j] = 'P';
			if (data->map[i][j] == 'P' && data->map[i-1][j] != '1')
				data->map[i-1][j] = 'P';
			if (data->map[i][j] == 'P' && data->map[i][j+1] != '1')
				data->map[i][j+1] = 'P';
			if (data->map[i][j] == 'P' && data->map[i][j-1] != '1')
				data->map[i][j-1] = 'P';
			j++;
		}
	}
}