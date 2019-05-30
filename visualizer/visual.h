/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:52:46 by akorol            #+#    #+#             */
/*   Updated: 2019/05/30 17:11:04 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# include <mlx.h>
# include "../libft/libft.h"
# include "../filler.h"
# define VISUAL_H
# define MR	50
# define WX 800
# define WY 800

typedef	struct	s_mlx
{
	int			mp_r;
	int			mp_c;
	int			mi;
	int			mj;
	int			size;
	void		*mlx_ptr;
	void		*wd_ptr;
	int			x;
	int			o;
	char		**map;
}				t_mlx;

void			create_map(t_mlx *vis_t);
int				put_map(void *param);
void			clean_vis(t_mlx *vis_t);
#endif
