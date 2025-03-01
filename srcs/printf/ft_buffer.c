/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:29:53 by gbetting          #+#    #+#             */
/*   Updated: 2025/03/01 20:40:00 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffer_clear(t_pf_data *data)
{
	char	*tmp;
	int		write_result;

	if (data->strout)
	{
		tmp = *(data->str_output);
		*(data->str_output) = ft_strnjoin(*(data->str_output),
				data->buffer, data->buff_index);
		free(tmp);
	}
	else
	{
		write_result = write(data->fd, data->buffer, data->buff_index);
		if (write_result == -1)
			data->fd_error = true;
	}
	data->total_count += data->buff_index;
	data->buff_index = 0;
}

void	ft_buffer_format(const char *format, t_pf_data *data)
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

void	ft_buffer_char(const char c, size_t count, t_pf_data *data)
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

void	ft_buffer_str(const unsigned char *str, size_t len, t_pf_data *data)
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
