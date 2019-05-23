/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:29:35 by akorol            #+#    #+#             */
/*   Updated: 2019/05/23 09:29:40 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			setting_up_token(t_filler *my_t)
{
	int		k;
	
	k = can_we_fit_it(my_t);
	ft_putstr_fd("Our k", g_fd);
	ft_putnbr_fd(k, g_fd);
	if (k)
	{
		searching_place(my_t);

		ft_putstr_fd("\nWell, the dist is", g_fd);
		ft_putnbr_fd(my_t->dist, g_fd);
		ft_putstr_fd("\n", g_fd);
		ft_putnbr_fd(my_t->x_cor, g_fd);
		ft_putstr_fd(" ", g_fd);
		ft_putnbr_fd(my_t->y_cor, g_fd);
		ft_putnbr(my_t->x_cor);
		ft_putstr(" ");
		ft_putnbr(my_t->y_cor);
		ft_putstr("\n");

		clean_structure(my_t);
		return (1);
	}
	else
	{
		ft_putnbr(0);
		ft_putstr(" ");
		ft_putnbr(0);
		ft_putstr("\n");
		clean_structure(my_t);
		return (0);
	}
}

int			can_we_fit_it(t_filler *my_t)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (my_t->map[++i])
	{
		j = -1;
		while (my_t->map[i][++j])
		{
			if (my_t->map[i][j] == my_t->sign ||
				my_t->map[i][j] == my_t->sign + 32)
			{
				if (token_check(i, j, my_t))		// should return something, wether we can fit it or can not
				{
					my_t->valid_x[k] = i - my_t->tok_x[my_t->head];
					my_t->valid_y[k] = j - my_t->tok_y[my_t->head];
					ft_putstr_fd("\nPossible place", g_fd);
					ft_putnbr_fd(my_t->valid_x[k], g_fd);
					ft_putnbr_fd(my_t->valid_y[k], g_fd);
					++k;
					my_t->valid_x[k] = -999;
					my_t->valid_y[k] = -999;
				}
			}
		}
	}
	return (k);
}

int			check_map_cell(t_filler *my_t)
{
	int		flag;
	char	enemy;

	enemy = my_t->sign == 'X' ? 'O' : 'X';
	flag = 1;
	if (my_t->x_cor < my_t->map_row && my_t->x_cor >= 0 &&
		my_t->y_cor < my_t->map_col && my_t->y_cor >= 0)
	{
		if (my_t->map[my_t->x_cor][my_t->y_cor] != enemy &&
			my_t->map[my_t->x_cor][my_t->y_cor] != enemy + 32)
		{
			if (my_t->map[my_t->x_cor][my_t->y_cor] != '.')
				my_t->cross++;
			return (1);
		}
	}
	return (0);
}

void		token_calculations(int i, int j, int k, t_filler *my_t)
{
	int		p;

	p = 0;
	if ((p = my_t->tok_x[my_t->head] - my_t->tok_x[k]) < 0)
		my_t->x_cor = i + p * -1;
	else
		my_t->x_cor = i - p;
	if ((p = my_t->tok_y[my_t->head] - my_t->tok_y[k]) < 0)
		my_t->y_cor = j + p * -1;
	else
		my_t->y_cor = j - p;
}

int			token_check(int	i, int j, t_filler *my_t)
{
	int		k;
	int		valid;

	my_t->head = -1;
	while (++my_t->head < my_t->count)
	{
		k = -1;
		valid = 0;
		my_t->cross = 0;
		while (++k < my_t->count)
		{
			token_calculations(i, j, k, my_t);
			valid += check_map_cell(my_t);
			if (my_t->cross > 1)
				break;
			if (valid == my_t->count)
				return (1);
		}
	}
	return (0);
}