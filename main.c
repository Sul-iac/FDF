/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:26:05 by qbarron           #+#    #+#             */
/*   Updated: 2024/02/17 14:26:05 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); //les  donnees generee dans la structure + y (largeur de l'image creee) multiplie par la longeur d'une ligne + la longeur de la fenetre multiplie par la taille des pixels generes \ 8 (pour avoir a la fin une taille connues de Bits par couleur et pouvoir les skipper facilement)
	*(unsigned int*)dst = color; 												// on le convertie en unsigned int
}

void	ft_set_variables(t_vars *vars)
{
	int	i;

	i = 0;
	vars->nbr_lines = 4;
	vars->nbr_colonnes = 2;
	vars->size_grid = 50;
	vars->map = malloc(sizeof(int *) * vars->nbr_lines);
	while (i < vars->nbr_lines)
	{
		vars->map[i] = malloc(sizeof(int *) * vars->nbr_colonnes);
		i++;
	}
	vars->map[0][0] = 0;  // x-coordinate of the first point of the first line
	vars->map[0][1] = 0;  // y-coordinate of the first point of the first line
	vars->map[1][0] = 100; // x-coordinate of the second point of the first line
	vars->map[1][1] = 0;  // y-coordinate of the second point of the first line
	vars->map[2][0] = 0;  // x-coordinate of the first point of the second line
	vars->map[2][1] = 100; // y-coordinate of the first point of the second line
	vars->map[3][0] = 100; // x-coordinate of the second point of the second line
	vars->map[3][1] = 100;
}

int main()
{
	t_data img;
	t_vars vars;

	vars.mlx = mlx_init();
	img.img = mlx_new_window(vars.mlx, 1220, 770, "Fdf");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	ft_set_variables(&vars);

	my_mlx_pixel_put(&img, 10, 100, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}












//============================== juste un test ========================================//


/*

int main(void)
	{
		....mettre le reste des fonctions necessaires
		int x = 50;
    	int y = 50;
    	int size = 400;
		draw_flag(&img, x, y, size);
	}

void draw_vertical_line(t_data *img, int x, int start_y, int end_y, int color)
{
	int y;

	for (y = start_y; y <= end_y; y++)
		my_mlx_pixel_put(img, x, y, color); 
}

void draw_horizontal_line(t_data *img, int start_x, int end_x, int y, int color)
{
	int x;

	for (x = start_x; x <= end_x; x++)
		my_mlx_pixel_put(img, x, y, color);
}

void draw_square(t_data *img, int x, int y, int size, int color)
{
	draw_horizontal_line(img, x, x + size, y, color); //la ligne du haut, on prend x plus la taille (longueur), y et la couleur
	draw_horizontal_line(img, x, x + size, y + size, color);	//la ligne du bas, on prend x plus la taille, y plus la taille(pour savoir ou se situe la fin de la hauteur du carre)
	draw_vertical_line(img, x, y, y + size, color);				//la ligne de gauche, y plus size pour savori quand s'arrete le carre
	draw_vertical_line(img, x + size, y, y + size, color);		//la ligne de droite, x plus size pour savoir quand commence la ligne et y plus size pour savoir quand est ce qu'elle s'arrete
}

void draw_flag(t_data *img, int x, int y, int size)
{
    int band_width = size / 3;
    int blue_color = 0x000000FF;    
    int white_color = 0x00FFFFFF;   
    int red_color = 0x00FF0000;     
	int third_width = size / 3;

    draw_vertical_line(img, x, y, y + size, blue_color);
    draw_vertical_line(img, x + band_width, y, y + size, white_color);
    draw_vertical_line(img, x + 2 * band_width, y, y + size, white_color);

   
    draw_horizontal_line(img, x, x + third_width, y, blue_color);							//premiere ligne du haut
    draw_horizontal_line(img, x + third_width, x + 2 * third_width, y, white_color); 		//deuxieme ligne du haut
    draw_horizontal_line(img, x + 2 * third_width, x + size, y, red_color); 				//troisieme ligne du haut
    
    draw_horizontal_line(img, x, x + third_width, y + size, blue_color); 					//premiere ligne du bas
    draw_horizontal_line(img, x + third_width, x + 2 * third_width, y + size, white_color); //deuxieme ligne du bas
    draw_horizontal_line(img, x + 2 * third_width, x + size, y + size, red_color); 			//troisieme ligne du bas

    draw_vertical_line(img, x, y, y + size, blue_color); 									//bordure de gauche
    draw_vertical_line(img, x + size, y, y + size, red_color); 								//bordure de droite
}
*/
