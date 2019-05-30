/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:52:15 by akorol            #+#    #+#             */
/*   Updated: 2019/05/24 16:52:18 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			vis_read_size(t_mlx *vis_t, char *line)
{
	char		*str;
	char		**tab;

	if (line[10] == '0')
		str = ft_strsub(line, 8, 6);
	else
		str = ft_strsub(line, 8, 5);
	tab = ft_strsplit(str, ' ');
	vis_t->mp_r = ft_atoi(tab[0]);
	vis_t->mp_c = ft_atoi(tab[1]);
	create_map(vis_t);
	put_map(vis_t);
	clean_vis(vis_t);
	free(tab[0]);
	free(tab[1]);
	free(tab);
	free(str);
}

void			create_map(t_mlx *vis_t)
{
	char		**tab;
	char		*line;
	size_t		a;
	int			i;

	i = -1;
	tab = (char**)malloc(sizeof(char*) * vis_t->mp_r + 1);
	tab[vis_t->mp_r] = NULL;
	a = get_next_line(0, &line);
	free(line);
	while (++i < vis_t->mp_r)
	{
		get_next_line(0, &line);
		tab[i] = ft_strsub(line, 4, vis_t->mp_c);
		free(line);
	}
	vis_t->map = tab;
	if (vis_t->mp_r == 100)
		vis_t->size = 5;
	else if (vis_t->mp_r == 24)
		vis_t->size = 15;
	else
		vis_t->size = 30;
}

int				exit_func(int keycode, void *param)
{
	t_mlx		*vis_t;

	vis_t = (t_mlx*)param;
	if (keycode == 53)
	{
		mlx_destroy_window(vis_t->mlx_ptr, vis_t->wd_ptr);
		exit(1);
	}
	return (0);
}

t_mlx			*launch_gui(void)
{
	void		*mlx_ptr;
	void		*wd_ptr;
	t_mlx		*vis_t;
	int			(*func)(int, void*);

	vis_t = (t_mlx*)malloc(sizeof(t_mlx));
	mlx_ptr = mlx_init();
	wd_ptr = mlx_new_window(mlx_ptr, WX, WY, "Filler");
	func = &exit_func;
	vis_t->mlx_ptr = mlx_ptr;
	vis_t->wd_ptr = wd_ptr;
	mlx_key_hook(vis_t->wd_ptr, func, vis_t);
	return (vis_t);
}

int				main(void)
{
	char		*line;
	t_mlx		*vis_t;

	vis_t = launch_gui();
	while (get_next_line(0, &line))
	{
		if (line[0] == 'P' && line[1] == 'l')
			vis_read_size(vis_t, line);
		free(line);
	}
	mlx_loop(vis_t->mlx_ptr);
	free(vis_t);
	return (0);
}
