/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:43:28 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/16 22:00:11 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_u_process(const char *nbr, t_data *data)
{
	int64_t	nbrlen;
	int64_t	len;

	if (data->format_data.precision == 0 && nbr[0] == '0' && !nbr[1]
		&& data->format_data.width == 0 && data->format_data.flags == 0)
		nbr = "";
	else if (data->format_data.precision == 0 && nbr[0] == '0' && !nbr[1])
		nbr = " ";
	nbrlen = ft_strlen(nbr);
	len = ft_max(nbrlen, data->format_data.precision);
	if (!(data->format_data.flags & FLAG_MINUS)
		&& data->format_data.width > len)
		ft_buffer_char(ft_t_int(data->format_data.flags & FLAG_ZERO, '0', ' '),
			data->format_data.width - len, data);
	if (nbrlen != len)
		ft_buffer_char('0', len - nbrlen, data);
	ft_buffer_str((unsigned char *)nbr, nbrlen, data);
	if (data->format_data.flags & FLAG_MINUS
		&& data->format_data.width > len)
		ft_buffer_char(' ', data->format_data.width - len, data);
}

static void	ft_u_preprocess(t_data *data)
{
	if (data->format_data.flags & FLAG_ZERO && data->format_data.precision >= 0)
		data->format_data.flags &= ~FLAG_ZERO;
	if (data->format_data.flags & FLAG_MINUS
		&& data->format_data.flags & FLAG_ZERO)
		data->format_data.flags &= ~FLAG_ZERO;
	return ;
}

bool	ft_u_header(t_data *data)
{
	uint64_t	unbr;

	if (data->format_data.length == LENGTH_NONE)
		unbr = va_arg(data->args, unsigned int);
	else if (data->format_data.length == LENGTH_HH)
		unbr = (unsigned char)va_arg(data->args, unsigned int);
	else if (data->format_data.length == LENGTH_H)
		unbr = (unsigned short int)va_arg(data->args, unsigned int);
	else if (data->format_data.length == LENGTH_L)
		unbr = va_arg(data->args, unsigned long int);
	else if (data->format_data.length == LENGTH_LL)
		unbr = va_arg(data->args, unsigned long long int);
	else if (data->format_data.length == LENGTH_J)
		unbr = va_arg(data->args, uintmax_t);
	else if (data->format_data.length == LENGTH_Z)
		unbr = va_arg(data->args, size_t);
	else if (data->format_data.length == LENGTH_T)
		unbr = va_arg(data->args, ptrdiff_t);
	else
		return (false);
	ft_u_preprocess(data);
	return (ft_u_process(ft_nbrbase_nm(unbr, DECIMAL_BASE), data), true);
}