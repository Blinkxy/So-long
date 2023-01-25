/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:58:53 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 20:06:19 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_sub(int key, t_str *data)
{
	if (key == 124 && data->map[(data->py) / 50][((data->px) / 50) + 1] != '1')
	{
		data->px += 50;
		data->moves++;
		ft_printf("%d\n", data->moves);
	}
	if (key == 123 && data->map[(data->py) / 50][((data->px) / 50) - 1] != '1')
	{
		data->px -= 50;
		data->moves++;
		ft_printf("%d\n", data->moves);
	}
}

int	move_player(int key, t_str *data)
{
	frame_coins(key, data);
	frame_exit_enemy(key, data);
	move_sub(key, data);
	if (key == 126 && data->map[((data->py) / 50) - 1][((data->px)
			/ 50)] != '1')
	{
		data->py -= 50;
		data->moves++;
		ft_printf("%d\n", data->moves);
	}
	if (key == 125 && data->map[((data->py) / 50) + 1][((data->px)
			/ 50)] != '1')
	{
		data->py += 50;
		data->moves++;
		ft_printf("%d\n", data->moves);
	}
	win_exit(key, data);
	repeat_frame(data);
	return (0);
}

void	frame_coins(int key, t_str *data)
{
	if (key == 124 && data->map[(data->py) / 50][((data->px) / 50) + 1] == 'C')
	{
		data->map[(data->py) / 50][((data->px) / 50) + 1] = '0';
		data->coins_c--;
	}
	if (key == 123 && data->map[(data->py) / 50][((data->px) / 50) - 1] == 'C')
	{
		data->map[(data->py) / 50][((data->px) / 50) - 1] = '0';
		data->coins_c--;
	}
	if (key == 125 && data->map[((data->py) / 50) + 1][(data->px) / 50] == 'C')
	{
		data->map[((data->py) / 50) + 1][(data->px) / 50] = '0';
		data->coins_c--;
	}
	if (key == 126 && data->map[((data->py) / 50) - 1][((data->px)
			/ 50)] == 'C')
	{
		data->map[((data->py) / 50) - 1][((data->px) / 50)] = '0';
		data->coins_c--;
	}
}

int	frame_exit_enemy(int key, t_str *data)
{
	if (key == 123 && (data->py) / 50 == (data->ey) / 50
		&& ((data->px) / 50) - 1 == (data->ex) / 50)
	{
		ft_printf("You LOSE !!!\n");
		exit_free(data);
	}
	if (key == 124 && (data->py) / 50 == (data->ey) / 50
		&& ((data->px) / 50) + 1 == (data->ex) / 50)
	{
		ft_printf("You LOSE !!!\n");
		exit_free(data);
	}
	if (key == 125 && ((data->py) / 50) + 1 == (data->ey) / 50
		&& ((data->px) / 50) == (data->ex) / 50)
	{
		ft_printf("You LOSE !!!\n");
		exit_free(data);
	}
	if (key == 126 && ((data->py) / 50) - 1 == (data->ey) / 50
		&& ((data->px) / 50) == (data->ex) / 50)
	{
		ft_printf("You LOSE !!!\n");
		exit_free(data);
	}
	return (0);
}

int	win_exit(int key, t_str *data)
{
	if (key == 124 && data->map[(data->py) / 50][((data->px) / 50)] == 'E'
		&& data->coins_c == 0)
	{
		ft_printf("GG! You WIN !!!\n");
		exit_free(data);
	}
	if (key == 123 && data->map[(data->py) / 50][((data->px) / 50)] == 'E'
		&& data->coins_c == 0)
	{
		ft_printf("GG! You WIN !!!\n");
		exit_free(data);
	}
	if (key == 125 && data->map[((data->py) / 50)][(data->px) / 50] == 'E'
		&& data->coins_c == 0)
	{
		ft_printf("GG! You WIN !!!\n");
		exit_free(data);
	}
	if (key == 126 && data->map[((data->py) / 50)][((data->px) / 50)] == 'E'
		&& data->coins_c == 0)
	{
		ft_printf("GG! You WIN !!!\n");
		exit_free(data);
	}
	return (0);
}
