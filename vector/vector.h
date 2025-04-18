/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:19:29 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/15 18:05:03 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>

# define FT_EPSILON 0.0001

/* ************************************************************************** */
/*                                 VECTOR                                     */
/* ************************************************************************** */

typedef struct s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef t_vec	t_unit_vec;
typedef t_vec	t_pos_vec;

t_vec			vec(double x, double y, double z);
t_vec			vec0(void);
t_vec			vec_add(t_vec v1, t_vec v2);
t_vec			vec_sub(t_vec v1, t_vec v2);
t_vec			vec_mul(t_vec v, double scalar);
t_unit_vec		dir(t_pos_vec v1, t_pos_vec v2);
t_vec			vec_hadamard(t_vec v1, t_vec v2);
t_vec			vec_div(t_vec v, double scalar);
double			vec_dot(t_vec v1, t_vec v2);
t_vec			vec_cross(t_vec v1, t_vec v2);
double			vec_magnitude(t_vec v);
t_unit_vec		vec_normalize(t_vec v);
double			vec_distance(t_vec v1, t_vec v2);

/* ************************************************************************** */
/*                                  LINE                                      */
/* ************************************************************************** */

typedef struct s_line
{
	t_pos_vec	p1;
	t_pos_vec	p2;
}				t_line;

typedef struct s_unit_line
{
	t_pos_vec	pos;
	t_unit_vec	dir;
}				t_unit_line;

t_line			line(t_pos_vec p1, t_pos_vec p2);
double			line_distance(t_line l, t_pos_vec p);
t_unit_line		unit_line(t_pos_vec pos, t_vec dir);
t_unit_line		unit_line2(t_pos_vec pos, t_pos_vec p2);

t_unit_line		line_normalize(t_line l);

/* ************************************************************************** */
/*                                SPHERE                                      */
/* ************************************************************************** */

typedef struct s_sphere
{
	t_pos_vec	center;
	double		radius;
	void		*material;
}				t_sphere;

// t_sphere		sphere(t_vec center, double radius);
double			sphere_distance(t_sphere s, t_vec p);

t_sphere		*sphere_new(t_pos_vec center, double radius, void *material);
void			sphere_clear(t_sphere *sp);

/* ************************************************************************** */
/*                                PLANE                                       */
/* ************************************************************************** */

typedef struct s_plane
{
	t_unit_vec	wdir;
	t_unit_vec	hdir;
	t_unit_vec	normal;
	t_pos_vec	pos;
	double		width;
	double		height;
	void		*material;
}				t_plane;

typedef t_plane	t_rect;
typedef t_plane	t_square;

t_plane			*plane_new(t_pos_vec pos, t_vec normal, void *material);
void			plane_clear(t_plane *pl);

/* ************************************************************************** */
/*                              CYLINDER                                      */
/* ************************************************************************** */

typedef struct s_cylinder
{
	t_pos_vec	center;
	double		radius;
	t_unit_vec	normal;
	double		height;

	void		*material;
}				t_cylinder;

t_cylinder		*cylinder_new(t_pos_vec center, t_vec normal, t_vec lengths,
					void *material);
void			cylinder_clear(t_cylinder *cy);

/* ************************************************************************** */
/*                                TRIANGLE                                    */
/* ************************************************************************** */

typedef struct s_triangle
{
	t_pos_vec	p0;
	t_pos_vec	p1;
	t_pos_vec	p2;

	t_unit_vec	normal;

	void		*material;
}				t_triangle;

typedef struct s_tr_elements
{
	t_vec		e1;
	t_vec		e2;
	t_vec		h;
	t_vec		s;
	t_vec		q;
	double		a;
	double		f;
	double		u;
	double		v;
	double		t;
}				t_tr_elements;

t_triangle		*triangle_new(t_pos_vec p0, t_pos_vec p1, t_pos_vec p2,
					void *material);
void			triangle_clear(t_triangle *triangle);
bool			is_point_in_triangle(t_pos_vec p, const t_triangle *tri);

/* ************************************************************************** */
/*                                  CONE                                      */
/* ************************************************************************** */

typedef struct s_cone
{
	t_pos_vec	vertex;
	t_vec		normal;
	double		angle;
	double		height;
	double		radius;
	void		*material;
}				t_cone;

t_cone			*cone_new(t_pos_vec vertex, t_vec normal, t_vec angles,
					void *material);

void			cone_clear(t_cone *cone);

/* ************************************************************************** */
/*                                  UTILS                                     */
/* ************************************************************************** */

typedef struct s_roots
{
	int			n;
	double		x1;
	double		x2;
}				t_roots;

t_roots			solve_eq(double a, double b, double c);
#endif