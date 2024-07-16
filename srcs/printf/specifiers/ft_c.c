/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:19:14 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/03 02:13:56 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_c(t_data *data)
{
	int	c;

	c = va_arg(data->args, int);
	if (!(data->format_data.flags & FLAG_MINUS))
	{
		ft_buffer_char(' ', ft_minu(data->format_data.width - 1,
				data->format_data.width), data);
	}
	ft_buffer_char(c, 1, data);
	if (data->format_data.flags & FLAG_MINUS)
	{
		ft_buffer_char(' ', ft_minu(data->format_data.width - 1,
				data->format_data.width), data);
	}
	return (true);
}

bool	ft_c_header(t_data *data)
{
	if (data->format_data.length == LENGTH_NONE)
		return (ft_c(data));
	return (false);
}
