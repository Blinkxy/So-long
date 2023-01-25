/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:08:18 by mzoheir           #+#    #+#             */
/*   Updated: 2023/01/25 20:27:02 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"
# include <time.h>

# ifndef

#  define FRAME = 40

# endif

void	paths(t_str *data);
int		enemy_moves(t_str *data);
int		repeat_frame(t_str *data);
void	first_frame(t_str *data);
void	first_frame_bis(t_str *data, int i, int j);
int		frame_exit_enemy(int key, t_str *data);
int		win_exit(int key, t_str *data);
void	enemy_sub(t_str *data, int i);
void	enemy_sub_bis(t_str *data, int i);
void	frame_utils(t_str *data, int i, int j);
void	frame_repeat_util(t_str *data, int i, int j);
#endif
