/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:59:44 by akorol            #+#    #+#             */
/*   Updated: 2019/05/22 14:59:47 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				root(int num)
{
	int			b;

	b = 1;
	while(b * b < num)
	{
		b++;
		if (b * b > num)
		{
			b--;
			break;
		}
	}
	return (b);
}

void			reading_map(t_filler *my_t)
{
	char		**tab;
	char		*line;
	size_t		a;
	int			i;

	i = -1;
	tab = (char**)malloc(sizeof(char*) * my_t->map_row + 1);
	tab[my_t->map_row] = NULL;
	a = get_next_line(0, &line);
	free(line);
	ft_putstr_fd("Map\n", g_fd);
	while (++i < my_t->map_row)
	{
		get_next_line(0, &line);
		tab[i] = ft_strsub(line, 4, my_t->map_col);
		free(line);
	}
	my_t->map = tab;
	i = -1;
	while (++i < my_t->map_row)
	{
		ft_putstr_fd(tab[i], g_fd);
		ft_putstr_fd("\n", g_fd);
	}
}

void			fill_token_xy(char **tab, t_filler *my_t)
{
	int			i;
	int			j;
	int			k;


	my_t->tok_x = (int*)malloc(sizeof(int) * my_t->count);
	my_t->tok_y = (int*)malloc(sizeof(int) * my_t->count);
	i = -1;
	k = 0;
	ft_putstr_fd("my count\n", g_fd);
	ft_putnbr_fd(my_t->count, g_fd);
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putnbr_fd(j, g_fd);
			ft_putstr_fd("\n", g_fd);
			if (tab[i][j] == '*')
			{
				my_t->tok_x[k] = i;
				my_t->tok_y[k] = j;
				k++;
			}
			j++;
		}
	}
}

void			reading_token(t_filler *my_t)
{
	char		**tab;
	char		*line;
	size_t		a;
	int			i;
	int			j;

	i = -1;
	tab = (char**)malloc(sizeof(char*) * my_t->tok_row + 1);
	tab[my_t->tok_row] = NULL;
	while (++i < my_t->tok_row)
	{
		j = -1;
		get_next_line(0, &line);
		tab[i] = ft_strdup(line);
		while (tab[i][++j])
		{
			if (tab[i][j] == '*')
				my_t->count++;
		}
		free(line);
	}
	// my_t->tok = tab;
	
	i = -1;
	ft_putstr_fd("Token\n", g_fd);
	while (++i < my_t->tok_row)
	{
		ft_putstr_fd(tab[i], g_fd);
		ft_putstr_fd("\n", g_fd);
	}
	fill_token_xy(tab, my_t);

	
	for(int p=0; p<my_t->count; p++)
	{
		ft_putnbr_fd(my_t->tok_x[p], g_fd);
		ft_putnbr_fd(my_t->tok_y[p], g_fd);
	}
}
