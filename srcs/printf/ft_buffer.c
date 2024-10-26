/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:29:53 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/03 03:43:11 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffer_clear(t_data *data)
{
	if (data->strout)
		*(data->str_output) = ft_strjoin(*(data->str_output), data->buffer);
	else
		(void)write(data->fd, data->buffer, data->buff_index);
	data->total_count += data->buff_index;
	data->buff_index = 0;
}

void	ft_buffer_format(const char *format, t_data *data)
{
	while (data->buff_index < BUFF_SIZE
		&& format[data->format_index]
		&& (data->ff || format[data->format_index] != FORMAT_TRIGGER))
		data->buffer[data->buff_index++] = format[data->format_index++];
	if (data->buff_index == BUFF_SIZE)
	{
		ft_buffer_clear(data);
		ft_buffer_format(format, data);
	}
}

void	ft_buffer_char(const char c, size_t count, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < count && data->buff_index < BUFF_SIZE)
	{
		data->buffer[data->buff_index++] = c;
		i++;
	}
	if (data->buff_index == BUFF_SIZE)
	{
		ft_buffer_clear(data);
		ft_buffer_char(c, count - i, data);
	}
}

void	ft_buffer_str(const unsigned char *str, size_t len, t_data *data)
{
	size_t	i;

	i = 0;
	while (data->buff_index < BUFF_SIZE && str[i] && i < len)
	{
		data->buffer[data->buff_index++] = str[i];
		i++;
	}
	if (data->buff_index == BUFF_SIZE)
	{
		ft_buffer_clear(data);
		ft_buffer_str(str + i, len - i, data);
	}
}
