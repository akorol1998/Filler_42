/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_file1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:54:25 by akorol            #+#    #+#             */
/*   Updated: 2019/05/30 13:54:26 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			draw_square(int i, int j, t_mlx *vis_t)
{
	int			k;
	int			p;
	int			color;

	k = -1;
	if (vis_t->map[i][j] == 'O' || vis_t->map[i][j] == 'o')
	{
		vis_t->o++;
		color = 0X6da7ff;
	}
	else if (vis_t->map[i][j] == 'X' || vis_t->map[i][j] == 'x')
	{
		vis_t->x++;
		color = 0Xf47142;
	}
	else
		color = 0Xefdec4;
	while (++k < vis_t->size)
	{
		p = -1;
		while (++p < vis_t->size)
			mlx_pixel_put(vis_t->mlx_ptr, vis_t->wd_ptr,
				vis_t->mi + k, vis_t->mj + p, color);
	}
}

void			clear_score(t_mlx *vis_t)
{
	char	*str;

	str = ft_itoa(vis_t->o);
	mlx_string_put(vis_t->mlx_ptr, vis_t->wd_ptr, 100,
		720, 0X6da7ff, "Player 1");
	mlx_string_put(vis_t->mlx_ptr, vis_t->wd_ptr, 200,
		720, 0X6da7ff, str);
	free(str);
	str = ft_itoa(vis_t->x);
	mlx_string_put(vis_t->mlx_ptr, vis_t->wd_ptr, 500,
		720, 0Xf47142, "Player 2");
	mlx_string_put(vis_t->mlx_ptr, vis_t->wd_ptr, 600,
		720, 0Xf47142, str);
	free(str);
}

void			score(t_mlx *vis_t)
{
	int			k;
	int			p;

	k = -1;
	while (++k + 720 < 750)
	{
		p = -1;
		while (++p + 190 < 250)
			mlx_pixel_put(vis_t->mlx_ptr, vis_t->wd_ptr,
				p + 190, k + 720, 0X000000);
	}
	k = -1;
	while (++k + 720 < 750)
	{
		p = -1;
		while (++p + 595 < 660)
			mlx_pixel_put(vis_t->mlx_ptr, vis_t->wd_ptr, p + 595,
				k + 720, 0X000000);
	}
	clear_score(vis_t);
}

int				put_map(void *param)
{
	t_mlx		*vis_t;
	int			i;
	int			j;

	vis_t = (t_mlx*)param;
	vis_t->mi = MR;
	vis_t->mj = MR;
	i = -1;
	vis_t->x = 0;
	vis_t->o = 0;
	while (vis_t->map[++i])
	{
		j = -1;
		while (vis_t->map[i][++j])
		{
			draw_square(i, j, vis_t);
			vis_t->mj += vis_t->size + 1;
		}
		vis_t->mi += vis_t->size + 1;
		vis_t->mj = MR;
	}
	score(vis_t);
	mlx_do_sync(vis_t->mlx_ptr);
	return (0);
}

void			clean_vis(t_mlx *vis_t)
{
	int			i;

	i = -1;
	while (++i < vis_t->mp_r)
	{
		free(vis_t->map[i]);
	}
	free(vis_t->map);
}
