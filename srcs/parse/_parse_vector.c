/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:29:36 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 12:37:55 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// todo parse_double にres :boolを持たせてparseの失敗を検知するaaaみたいな小数ではないものが来ても、
// res=false とするだけで最後までparseする
t_vec	parse_vector(bool *res, const char *token, int line)
{
	char	**el;
	t_vec	vec3;

	el = ft_split(token, ',');
	if (!el || !el[0] || !el[1] || !el[2] || el[3])
	{
		ft_strs_clear(el);
		printf("line: %d:  vector and color should 3 fields\n", line);
		*res = false;
		return (vec(0, 0, 0));
	}
	vec3 = vec(parse_double(res, el[0], line, vec0()), parse_double(res, el[1],
				line, vec0()), parse_double(res, el[2], line, vec0()));
	ft_strs_clear(el);
	return (vec3);
}

t_vec	parse_color(bool *res, const char *token, int line)
{
	t_vec	color;

	color = parse_vector(res, token, line);
	if (0 > color.x || color.x > 255 || 0 > color.y || color.y > 255
		|| 0 > color.z || color.z > 255)
	{
		printf("line: %d:  RGB must be positive and less than 255\n", line);
		*res = false;
	}
	return (color);
}
