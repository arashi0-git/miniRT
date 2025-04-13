/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:59:52 by ymizukam          #+#    #+#             */
/*   Updated: 2025/04/14 05:24:33 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

double	parse_double(bool *res, const char *token, int line, t_vec lim)
{
	double	d;

	// todo 失敗したら*res = false　にしエラーメッセージをはく
	d = atof(token);
	if (lim.z != 0.0 && (d < lim.x || lim.y < d))
	{
		if (lim.y == __DBL_MAX__)
			printf("line: %d:  field must be positve\n", line);
		else
			printf("line: %d:  field must be in range [%6f, %6f]\n", line,
				lim.x, lim.y);
		*res = false;
	}
	return (d);
}
