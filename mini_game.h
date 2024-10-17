/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:27:36 by aelidrys          #+#    #+#             */
/*   Updated: 2023/09/10 12:08:30 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_GAME_H
#define MINI_GAME_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <sys/time.h>
#include "mlx_linux/mlx.h"
#include <X11/Xlib.h>
// #include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <math.h>
#include "src/get_next_line.h"

# ifndef SIZE
# define SIZE 64
#endif

typedef struct s_paddle
{
	int		m_u;
	int		m_d;
	int		x;
	int		y;
	int		speed;
}	t_paddle;

typedef struct s_imgs{
	void *pos_g;
	void *pos_g0;
	void *pos_g1;
	void *pos_g2;
	void *pos;
	void *pos_0;
	void *pos_1;
	void *pos_2;
	void *pos_3;
	void *pos_4;
	void *home;
	void *home1;
	void *play_n;
	void *play_ai;
	void *restart1;
	void *restart2;
	void *restart1_1;
	void *restart1_2;
	void *restart2_1;
	void *restart2_2;
}	t_imgs;

typedef struct s_imge{
	char	dir;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		heigth;
	char	*addr;
	void	*ptr;
	struct s_imge *next;
} t_imge;

typedef struct s_ball{
	int		m_r;
	int		m_l;
	int		m_u;
	int		m_d;
	int		speed;
	int		rot_rhit;
	int		rot_left;
	int		dimtr;
	float	x;
	float	y;
	float	teta;
}	t_ball;

typedef struct s_game
{
	int		win_1;
	int		start;
	int		restart;
	int		win_2;
	int		lose;
	int		lose_1;
	int		lose_2;
	int		pos;
	int		w_size;
	int		size;
	void	*mlx;
	void	*win;
	t_ball		*ball;
	t_paddle	*paddle1;
	t_paddle	*paddle2;
	t_imgs		*imgs;
	t_imge		*img;
	t_imge		*img1;
	char **map;
}	t_game;



void	boot1(t_game *game);
void	boot2(t_game *game);
void	init_var(t_game * game);
void	ft_lose(t_game *game);
void	ft_pos(t_game *game);
void	ft_start(t_game *game);
void	init_img_win(t_game *game, char *file_name);


void	my_mlx_pixel_put1(t_imge *data, int x, int y, int color);
void	put_score(t_game *game);
void	put_background(t_game *game);
void	put_square(t_game * game, int old_x, int old_y, int color);
void	put_ball(t_game *game, float x_p, float y_p, int color);
void	put_paddle(t_game *game, int s);
void	my_mlx_put(t_game *game, int x, int y, int color);

void	mouse_restart(int x, int y, t_game *game);
void	mouse_start(int x, int y, t_game *game);
void	mouse_pos(int x, int y, t_game *game);
int		mouse_presse(int key, int x, int y, t_game *game);
int		mouse_event(int x, int y, t_game *game);

int		motion(t_game *game);
void	randrine(t_game *game);
int		presse_key(int key, t_game *game);
int		relesse_key(int key, t_game *game);
int		presse_key_m(int key, t_game *game);
int		relesse_key_m(int key, t_game *game);
void	mov_paddle(t_game *game);
void	mov_up(t_game *game);
void	mov_down(t_game *game);
void	mov_rhit(t_game *game);
void	mov_left(t_game *game);

char	*conv_to_str(int p, int win);
char	**spl1(char*s, char c);
int		ft_exit(void);
void	ft_lose(t_game *game);

#endif
