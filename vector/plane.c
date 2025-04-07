/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:33:54 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/08 06:52:50 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,255
// id pos normal color

t_plane	*plane_new(t_pos_vec pos, t_vec normal, t_scaled_col color)
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->pos = pos;
	plane->normal = vec_normalize(normal);
	plane->color = color;
	return (plane);
}
