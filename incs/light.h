#ifndef LIGHT_H
# define LIGHT_H
# include "color.h"
# include "vector.h"

# define MAX_LIGHT 10

/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */

typedef struct s_light
{
	t_pos_vec	pos;
	double		intensity;
	t_fcol		color;
}				t_light;

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

t_light			*light_init(t_pos_vec pos, t_fcol col, double intensity,
					t_sys *sys);
void			light_deinit(t_light *light[], int size);

#endif