/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:22:36 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/08 12:33:15 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_exit(t_fractal *fractal)
{
	ft_putstr_fd("Exiting program cleanly.\n", 1);
	if (!fractal)
		exit(0);
	if (fractal->img.img)
		mlx_destroy_image(fractal->mlx, fractal->img.img);
	if (fractal->mlx_win && fractal->mlx)
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	if (fractal->mlx)
	{
		mlx_loop_end(fractal->mlx);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(0);
	return (0);
}

static void	wrong_format2(void)
{
	ft_putstr_fd("respectively.\n", 2);
	ft_putstr_fd("                   [EXAMPLES]                    \n", 2);
	ft_putstr_fd("./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol julia 0.33 0.11\n\n", 2);
	ft_putstr_fd("------------------- COMMANDS ------------------- \n", 2);
	ft_putstr_fd("[j]...............Decrement the C constant by ", 2);
	ft_putstr_fd("0.01 for the Julia set.\n", 2);
	ft_putstr_fd("[k]...............Increase the C constant by 0.01 ", 2);
	ft_putstr_fd("for the Julia set.\n", 2);
	ft_putstr_fd("[Arrows L R U D]--Move the fractal.\n", 2);
	ft_putstr_fd("[Scroll U D]......Zoom in at mouse position.\n", 2);
	ft_putstr_fd("[1/2].............Choose set to render: ", 2);
	ft_putstr_fd("Mandelbrot, Julia, respectively.\n", 2);
	ft_putstr_fd("[r]...............Reset fractals to original position.\n", 2);
	ft_putstr_fd("\n\n", 2);
}

void	wrong_format(t_fractal *fractal)
{
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[ERROR] Wrong format. Please specify the fractal ", 2);
	ft_putstr_fd("name followed by the optional parameters.\n\n", 2);
	ft_putstr_fd("------------------ PARAMETERS ------------------\n", 2);
	ft_putstr_fd("[2]...............Choose type of Fractal: mandelbrot", 2);
	ft_putstr_fd(", julia\n", 2);
	ft_putstr_fd("[2]...............IF julia SELECTED, you can choose the", 2);
	ft_putstr_fd(" initial constant value in the\n", 2);
	ft_putstr_fd("following format:\n", 2);
	ft_putstr_fd("a  b (where a and b are the real and imaginary", 2);
	ft_putstr_fd(" components of the constant c (a + b*i),\n", 2);
	ft_putstr_fd("respectively.\n", 2);
	wrong_format2();
	clean_exit(fractal);
}
