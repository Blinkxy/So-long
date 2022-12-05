/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:02:46 by mzoheir           #+#    #+#             */
/*   Updated: 2022/12/05 17:29:59 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_Long.h"

int	handle_input(int key, t_str *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		exit(0);
	}
	else
		ft_printf("%d\n", key);
	return (0);
}

int	x_close(t_str *data)
{
	free(data->mlx);
	exit(0);
	return (0);
}

int	main(void)
{
	t_str	*data;
	
	data =(t_str *) ft_calloc(1,sizeof(t_str));
	if(!data)
		return 0;
	data->path1 = "textures/player.xpm";
	data->path2 = "textures/wall->xpm";
	data->img_height = 200;
	data->img_width = 200;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 500, "Hello World!");
	data->player = mlx_xpm_file_to_image(data->mlx, data->path1, &data->img_width,
			&data->img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx, data->path2, &data->img_width,
			&data->img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->player, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->wall, 0, 100);
	mlx_hook(data->win, 2, 0, handle_input, &data);
	mlx_hook(data->win, 17, 0, x_close, &data);
	mlx_loop(data->mlx);
	return (0);
}
