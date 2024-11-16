/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:44:34 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/16 03:46:16 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_specifier_exec(t_pf_data *data)
{
	size_t			i;
	t_pf_specifier	*specifiers;

	i = 0;
	specifiers = ft_get_specifier();
	if (data->format_data.flags & FLAG_COLOR)
		ft_color(data);
	while (specifiers[i].specifier)
	{
		if (specifiers[i].specifier == data->format_data.specifier)
		{
			if (!specifiers[i].function(data))
				data->ff = true;
			break ;
		}
		i++;
	}
	if (data->format_data.flags & FLAG_COLOR)
		ft_endcolor(data);
}

int	ft_printf_process(const char *format, t_pf_data *data)
{
	data->buff_index = 0;
	data->total_count = 0;
	data->format_index = 0;
	data->ff = false;
	ft_bzero(data->buffer, BUFF_SIZE);
	while (format[data->format_index])
	{
		if (format[data->format_index] == FORMAT_TRIGGER)
		{
			data->format_index++;
			ft_format(format + (data->format_index), data);
			ft_specifier_exec(data);
		}
		else
			ft_buffer_format(format, data);
	}
	return (data->total_count);
}
