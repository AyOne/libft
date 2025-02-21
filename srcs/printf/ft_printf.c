/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:46:25 by gbetting          #+#    #+#             */
/*   Updated: 2025/02/21 15:53:27 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	t_pf_data	data;

	if (format == NULL)
		return (-1);
	ft_bzero(&data, sizeof(t_pf_data));
	va_start(data.args, format);
	data.fd = fd;
	data.strout = false;
	ft_printf_process(format, &data);
	ft_buffer_clear(&data);
	va_end(data.args);
	if (data.fd_error)
		return (-1);
	return (data.total_count);
}

int	ft_printf(const char *format, ...)
{
	t_pf_data	data;

	if (format == NULL)
		return (-1);
	ft_bzero(&data, sizeof(t_pf_data));
	va_start(data.args, format);
	data.fd = STDOUT_FILENO;
	data.strout = false;
	ft_printf_process(format, &data);
	ft_buffer_clear(&data);
	va_end(data.args);
	if (data.fd_error)
		return (-1);
	return (data.total_count);
}

int	ft_asprintf(char **str, const char *format, ...)
{
	t_pf_data	data;

	if (format == NULL || str == NULL)
		return (-1);
	ft_bzero(&data, sizeof(t_pf_data));
	va_start(data.args, format);
	data.fd = STDOUT_FILENO;
	data.strout = true;
	data.str_output = str;
	*(data.str_output) = ft_strdup("");
	if (*(data.str_output) == NULL)
		return (va_end(data.args), -1);
	ft_printf_process(format, &data);
	ft_buffer_clear(&data);
	va_end(data.args);
	if (*str == NULL)
		return (-1);
	return (data.total_count);
}

int	ft_bufferprintf(int fd, bool do_flush, const char *format, ...)
{
	static t_pf_data	data = {0};

	if (format == NULL)
		return (-1);
	va_start(data.args, format);
	data.fd = fd;
	data.strout = false;
	ft_printf_process(format, &data);
	va_end(data.args);
	if (do_flush)
		ft_buffer_clear(&data);
	if (data.fd_error)
		return (-1);
	return (data.total_count);
}
