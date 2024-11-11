/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:05:50 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/10 19:03:26 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_s(t_pf_data *data)
{
	char	*str;
	size_t	len;

	str = va_arg(data->args, char *);
	str = ft_t_ptr(str != NULL, str,
			ft_t_ptr(data->format_data.precision < 6
				&& data->format_data.precision > 0, "", "(null)"));
	len = ft_t_int(data->format_data.precision < 0, ft_strlen(str),
			ft_min(data->format_data.precision, ft_strlen(str)));
	if (!(data->format_data.flags & FLAG_MINUS)
		&& data->format_data.width > (int64_t)len)
		ft_buffer_char(' ', data->format_data.width - len, data);
	ft_buffer_str((unsigned char *)str, len, data);
	if (data->format_data.flags & FLAG_MINUS
		&& data->format_data.width > (int64_t)len)
		ft_buffer_char(' ', data->format_data.width - len, data);
	return (true);
}

bool	ft_s_header(t_pf_data *data)
{
	if (data->format_data.length == LENGTH_NONE)
		return (ft_s(data));
	return (false);
}
