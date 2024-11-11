/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:46:25 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/11 01:47:36 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_exec(t_pf_data *data)
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
	ft_buffer_clear(data);
	return (data->total_count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	t_pf_data	data;

	if (format == NULL)
		return (-1);
	va_start(data.args, format);
	data.fd = fd;
	data.strout = false;
	ft_printf_process(format, &data);
	va_end(data.args);
	return (data.total_count);
}

int	ft_printf(const char *format, ...)
{
	t_pf_data	data;

	if (format == NULL)
		return (-1);
	va_start(data.args, format);
	data.fd = STDOUT_FILENO;
	data.strout = false;
	ft_printf_process(format, &data);
	va_end(data.args);
	return (data.total_count);
}

int	ft_asprintf(char **str, const char *format, ...)
{
	t_pf_data	data;

	if (format == NULL)
		return (-1);
	va_start(data.args, format);
	data.fd = STDOUT_FILENO;
	data.strout = true;
	data.str_output = str;
	*(data.str_output) = ft_strdup("");
	ft_printf_process(format, &data);
	va_end(data.args);
	return (data.total_count);
}
