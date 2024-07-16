/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:20:33 by gbetting          #+#    #+#             */
/*   Updated: 2024/06/18 13:34:29 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %[flags][width][.precision][length]specifier

static uint64_t	ft_fflags(const char *format, t_data *data)
{
	uint64_t	i;

	i = 0;
	data->format_data.flags = 0;
	while (format[i] && ft_strchr("+- #0", format[i]))
	{
		if (format[i] == '-')
			data->format_data.flags |= FLAG_MINUS;
		else if (format[i] == '+')
			data->format_data.flags |= FLAG_PLUS;
		else if (format[i] == ' ')
			data->format_data.flags |= FLAG_SPACE;
		else if (format[i] == '#')
			data->format_data.flags |= FLAG_HASH;
		else if (format[i] == '0')
			data->format_data.flags |= FLAG_ZERO;
		i++;
	}
	return (i);
}

static uint64_t	ft_fwidth(const char *format, t_data *data)
{
	uint64_t	i;

	i = 0;
	data->format_data.width = 0;
	if (format[i] == '*')
	{
		data->format_data.width = va_arg(data->args, int);
		if (data->format_data.width < 0)
		{
			data->format_data.flags |= FLAG_MINUS;
			data->format_data.width *= -1;
		}
		i++;
	}
	else
	{
		while (ft_isdigit(format[i]))
		{
			data->format_data.width
				= data->format_data.width * 10 + format[i] - '0';
			i++;
		}
	}
	return (i);
}

static uint64_t	ft_fprecision(const char *format, t_data *data)
{
	uint64_t	i;

	i = 0;
	data->format_data.precision = -1;
	if (format[i] == '.')
	{
		data->format_data.precision = 0;
		i++;
		if (format[i] == '*')
		{
			data->format_data.precision = va_arg(data->args, int);
			i++;
		}
		else
		{
			while (ft_isdigit(format[i]))
			{
				data->format_data.precision = data->format_data.precision * 10
					+ format[i] - '0';
				i++;
			}
		}
	}
	return (i);
}

static uint64_t	ft_flength(const char *format, t_data *data)
{
	uint64_t	i;

	i = 0;
	data->format_data.length = LENGTH_NONE;
	if (format[i] == 'h' && format[i + 1] == 'h' && ++i && ++i)
		data->format_data.length = LENGTH_HH;
	else if (format[i] == 'h' && ++i)
		data->format_data.length = LENGTH_H;
	else if (format[i] == 'l' && format[i + 1] == 'l' && ++i && ++i)
		data->format_data.length = LENGTH_LL;
	else if (format[i] == 'l' && ++i)
		data->format_data.length = LENGTH_L;
	else if (format[i] == 'j' && ++i)
		data->format_data.length = LENGTH_J;
	else if (format[i] == 'z' && ++i)
		data->format_data.length = LENGTH_Z;
	else if (format[i] == 't' && ++i)
		data->format_data.length = LENGTH_T;
	else if (format[i] == 'L' && ++i)
		data->format_data.length = LENGTH_LF;
	return (i);
}

void	ft_format(const char *format, t_data *data)
{
	uint64_t	i;

	i = ft_fflags(format, data);
	i += ft_fwidth(format + i, data);
	i += ft_fprecision(format + i, data);
	i += ft_flength(format + i, data);
	data->format_data.specifier = format[i];
	data->format_index += i + 1;
}
