/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:32:41 by akorol            #+#    #+#             */
/*   Updated: 2019/05/24 14:32:51 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>

int		g_fd;

typedef struct	s_filler
{
	char		**map;
	int			sign;
	int			map_row;
	int			map_col;
	int			tok_row;
	int			tok_col;
	int			*tok_x;
	int			*tok_y;
	int			*valid_x;
	int			*valid_y;
	int			cross;
	int			count;
	int			x_cor;
	int			y_cor;
	int			head;
	int			dist;
}				t_filler;

int				root(int num);
void			reading_map(t_filler *my_t);
void			reading_token(t_filler *my_t);
int				can_we_fit_it(t_filler *my_t);
int				token_check(int	i, int j, t_filler *my_t);
int				check_map_cell(t_filler *my_t);
void			token_calculations(int i, int j, int k, t_filler *mt_t);
int				setting_up_token(t_filler *my_t);
void			searching_place(t_filler *my_t);
void			calculate_distance(int i, int j, int k, t_filler *myt);
void			clean_structure(t_filler *my_t);
void			make_structure(t_filler *my_t);
void			read_figure(char *line, char **tab, t_filler *my_t);
void			token_coordinates(char **tab, t_filler *my_t);
#endif
