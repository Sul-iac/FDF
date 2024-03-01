/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:21:05 by qbarron           #+#    #+#             */
/*   Updated: 2024/02/17 15:21:05 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}				t_data;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;

	float	theta;					//variable de rotation de x (theta)
	float	qsi;					//variable de rotation de z (theta_z)
	float	phi;					//variable de rotation de y (theta_y)

	int	nbr_lines;
	int	nbr_colonnes;
	int	**map;
	float	size_grid;


}				t_vars;


#endif




