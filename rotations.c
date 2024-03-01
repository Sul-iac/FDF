/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:57:10 by qbarron           #+#    #+#             */
/*   Updated: 2024/03/01 10:57:10 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point init(int x, int y, int z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	
	return(point);
}

t_point rotation_x(t_point a, t_vars *vars)
{
	float temp_y;
	float temp_z;

	temp_y = 0;
	temp_z = 0;
	a.y = temp_y * cos(vars->theta) + temp_z * sin(vars->theta);
	a.z = -temp_y * cos(vars->theta) + temp_z * sin(vars->theta);
	return(a);
}

t_point rotation_y(t_point a, t_vars *vars)
{
	float	temp_x;
	float	temp_z;

	temp_x = 0;
	temp_z = 0;
	a.x = temp_x * cos(vars->phi) + temp_z * sin(vars->phi);
	a.z = -temp_x * sin(vars->phi) + temp_z * cos(vars->phi);
	return(a);
}

t_point rotation_z(t_point a, t_vars *vars)
{
	float temp_x;
	float temp_y;

	temp_x = 0;
	temp_y = 0;
	a.x = temp_x * cos(vars->qsi) - temp_y * sin(vars->qsi);
	a.y = temp_x * sin(vars->qsi ) + temp_y * cos(vars->qsi);
	return(a);
}


