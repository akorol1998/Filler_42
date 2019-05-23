/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:03:28 by akorol            #+#    #+#             */
/*   Updated: 2019/05/23 12:03:30 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		calculate_distance(int i, int j, int k, t_filler *my_t)
{
	int		x;
	int		y;
	int		res;

	x = i - my_t->valid_x[k];
	x *= x;
	y = j - my_t->valid_y[k];
	y *= y;
	res = root(x + y);
	if (!my_t->dist)
	{
		my_t->dist = res;
		my_t->x_cor = my_t->valid_x[k];
		my_t->y_cor = my_t->valid_y[k];
	}
	if (res < my_t->dist)
	{
		my_t->dist = res;
		my_t->x_cor = my_t->valid_x[k];
		my_t->y_cor = my_t->valid_y[k];
	} 
}

void		searching_place(t_filler *my_t)
{
	int		k;
	int		i;
	int		j;	
	char	enemy;

	k = -1;
	enemy = my_t->sign == 'X' ? 'O' : 'X';
	my_t->dist = 0;
	while (my_t->valid_x[++k] != -999)
	{
		i = -1;
		while (my_t->map[++i])
		{
			j = -1;
			while (my_t->map[i][++j])
			{
				if (my_t->map[i][j] == enemy ||
					my_t->map[i][j] == enemy + 32)
					calculate_distance(i, j, k, my_t);
			}
		}
	}
}

void		clean_structure(t_filler *my_t)
{
	int		i;
	int		j;

	i = -1;
	while (my_t->map[++i])
		free(my_t->map[i]);
	free(my_t->map);
	free(my_t->tok_x);
	free(my_t->tok_y);
	free(my_t->valid_x);
	free(my_t->valid_y);
}














