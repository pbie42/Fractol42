/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:57:30 by pbie              #+#    #+#             */
/*   Updated: 2016/03/15 17:33:58 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_fractol_init(t_mlx *m)
{
	if (!(ft_strcmp(m->argv, "mandelbrot")))
		ft_init_mandel(m);
	if (!(ft_strcmp(m->argv, "julia")))
		ft_init_julia(m);
}

void			ft_print_fractol(t_mlx *m)
{
	if (!(ft_strcmp(m->argv, "mandelbrot")))
		ft_mandelbrot(m);
	if (!(ft_strcmp(m->argv, "julia")))
		ft_julia(m);
}

int				main(int argc, char **argv)
{
	t_mlx		m;
	int			c_x;
	int			c_y;

	m.argv = argv[1];
	if (argc == 2 && ((!(ft_strcmp(m.argv, "mandelbrot")))
			|| (!(ft_strcmp(m.argv, "julia")))))
	{
		ft_putendl(argv[1]);
		c_x = WIN_X * 2 / 5;
		c_y = WIN_Y * 2 / 5;
		m.mlx = mlx_init();
		m.win = mlx_new_window(m.mlx, WIN_X, WIN_Y, "fractol");
		m.im = mlx_new_image(m.mlx, WIN_X, WIN_Y);
		m.imc = mlx_get_data_addr(m.im, &m.bpp, &m.imlen, &m.endi);
		ft_fractol_init(&m);
		ft_print_fractol(&m);
		//mlx_string_put(m.mlx, m.win, c_x + 100, c_y, 0x009999FF, HELLO);
		//mlx_string_put(m.mlx, m.win, c_x +16, c_y + 30, 0x009999FF, START);
		mlx_hook(m.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_julia_hook, &m);
		mlx_hook(m.win, KEYPRESS, KEYPRESSMASK, ft_key_binding, &m);
		mlx_hook(m.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &m);
		mlx_loop_hook(m.mlx, ft_keycore, &m);
		mlx_loop(m.mlx);
	}
	else
		ft_exit("Error: Wrong Number of Arguments");
	return (0);
}