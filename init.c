/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:22:37 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/08 15:27:23 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_atof_fracpart(char *nbr, char *tmp, int sign)
{
	int		fracpart;
	int		counter;
	double	ret;
	int		intpart;

	*nbr = '\0';
	intpart = ft_atoi(tmp);
	nbr++;
	tmp = nbr;
	counter = 0;
	while (*nbr)
	{
		counter++;
		nbr++;
	}
	fracpart = ft_atoi(tmp);
	ret = intpart + fracpart / pow(10, counter);
	return (sign * ret);
}

double	ft_atof(char *nbr)
{
	char	*tmp;
	double	sign;

	if (nbr == 0)
		return (0);
	sign = 1;
	if (*nbr == '-')
	{
		sign = -1;
		nbr++;
	}
	tmp = nbr;
	while (*nbr && *nbr != '.')
		nbr++;
	if (*nbr == '.')
		return (ft_atof_fracpart(nbr, tmp, sign));
	return (sign * ft_atoi(tmp));
}

void	init_fractal_dimensions(t_fractal *fractal, char **argv, int argc)
{
	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
	{
		fractal->x_max = 2;
		fractal->x_min = -2;
		fractal->y_max = 2;
		fractal->y_min = -2;
	}
	else
	{
		fractal->x_max = 2;
		fractal->x_min = -2;
		fractal->y_max = 2;
		fractal->y_min = -2;
		fractal->z.re = ft_atof(argv[2]);
		fractal->z.re = ft_atof(argv[3]);
		if (argc < 3)
			fractal->z.re = 0.43;
		if (argc < 4)
			fractal->z.im = 0.33;
	}
}

static void	init_vars(t_fractal *fractal)
{
	fractal->name = 0;
	fractal->mlx = NULL;
	fractal->mlx_win = NULL;
	fractal->img.img = NULL;
	fractal->x_min = 0.0;
	fractal->x_max = 0.0;
	fractal->y_min = 0.0;
	fractal->y_max = 0.0;
	fractal->scale = 1.0;
	fractal->mouse_pressed = 0;
	fractal->x = 0;
	fractal->y = 0;
	fractal->disp_x = 0;
	fractal->disp_y = 0;
	fractal->z.mod_squared = 0.0;
	fractal->j_pressed = 0;
	fractal->k_pressed = 0;
	fractal->color_set = "rainbow";
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
	{
		ft_putstr_fd("Error initializing MiniLibX\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	fractal_init(t_fractal *fractal)
{
	init_vars(fractal);
	fractal->mlx_win = mlx_new_window(fractal->mlx, 800, 800, "Fract-ol");
	if (fractal->mlx_win == NULL)
	{
		ft_putstr_fd("Error creating window\n", 2);
		exit(EXIT_FAILURE);
	}
	fractal->img.img = mlx_new_image(fractal->mlx, HEIGHT, WIDTH);
	if (fractal->img.img == NULL)
	{
		ft_putstr_fd("Error creating image\n", 2);
		exit(EXIT_FAILURE);
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	if (fractal->img.addr == NULL)
	{
		ft_putstr_fd("Error getting data address\n", 2);
		mlx_destroy_image(fractal->mlx, fractal->img.img);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		exit(EXIT_FAILURE);
	}
}
