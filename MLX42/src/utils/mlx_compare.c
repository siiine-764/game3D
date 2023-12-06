/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:20:19 by jvan-hal          #+#    #+#             */
/*   Updated: 2023/12/05 17:11:58 by hben-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

//= Private =//

bool mlx_equal_image(void* lstcontent, void* val)
{
	const mlx_image_t* lcontent = lstcontent;
	const mlx_image_t* lval = val;

	return (lcontent == lval);
}

bool mlx_equal_inst(void* lstcontent, void* val)
{
	const draw_queue_t* lcontent = lstcontent;
	const mlx_image_t* lval = val;

	return (lcontent->image == lval);
}