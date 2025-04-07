/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:24:23 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 06:39:08 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

/* ************************************************************************** */
/*                                 STRUCT         :)                          */
/* ************************************************************************** */
typedef struct s_material
{
	t_scaled_col	color;
	double			gloss;
	bool			checker;
	bool			mirror;
	bool			bump;
	char			*ref;
}					t_material;

/* ************************************************************************** */
/*                                  FUNCS                                     */
/* ************************************************************************** */

t_material			*material_init(t_vec color);

t_material			*get_material(t_list *list);

#endif