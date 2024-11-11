/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:14:14 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/10 19:03:50 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_i_process_2(const char *nbr, t_pf_data *data, bool neg)
{
	int64_t	nbrlen;
	int64_t	len;
	bool	sign;

	nbrlen = ft_strlen(nbr);
	len = ft_max(nbrlen, data->format_data.precision);
	sign = (neg || data->format_data.flags & FLAG_PLUS
			|| data->format_data.flags & FLAG_SPACE);
	if (sign && !(data->format_data.flags & FLAG_ZERO))
		ft_buffer_char(ft_t_int(neg, '-', ft_t_int(
					data->format_data.flags & FLAG_PLUS, '+', ' ')), 1, data);
	if (nbrlen != len)
		ft_buffer_char('0', len - nbrlen, data);
	ft_buffer_str((unsigned char *)nbr, nbrlen, data);
	if (data->format_data.flags & FLAG_MINUS
		&& data->format_data.width > (len + sign))
		ft_buffer_char(' ', data->format_data.width - (len + sign), data);
}

static void	ft_i_process(const char *nbr, t_pf_data *data, bool neg)
{
	int64_t	nbrlen;
	int64_t	len;
	bool	sign;

	if (data->format_data.precision == 0 && nbr[0] == '0' && !nbr[1]
		&& data->format_data.width == 0 && data->format_data.flags == 0)
		nbr = "";
	else if (data->format_data.precision == 0 && nbr[0] == '0' && !nbr[1])
		nbr = " ";
	nbrlen = ft_strlen(nbr);
	len = ft_max(nbrlen, data->format_data.precision);
	sign = (neg || data->format_data.flags & FLAG_PLUS
			|| data->format_data.flags & FLAG_SPACE);
	if (sign && data->format_data.flags & FLAG_ZERO)
		ft_buffer_char(ft_t_int(neg, '-', ft_t_int(
					data->format_data.flags & FLAG_PLUS, '+', ' ')), 1, data);
	if (!(data->format_data.flags & FLAG_MINUS)
		&& data->format_data.width > (len + sign))
		ft_buffer_char(ft_t_int(data->format_data.flags & FLAG_ZERO, '0', ' '),
			data->format_data.width - (len + sign), data);
	ft_i_process_2(nbr, data, neg);
}

static void	ft_i_preprocess(t_pf_data *data)
{
	if (data->format_data.flags & FLAG_ZERO && data->format_data.precision >= 0)
		data->format_data.flags &= ~FLAG_ZERO;
	if (data->format_data.flags & FLAG_MINUS
		&& data->format_data.flags & FLAG_ZERO)
		data->format_data.flags &= ~FLAG_ZERO;
	return ;
}

static bool	ft_i_header_2(t_pf_data *data, int64_t nbr, uint64_t unbr)
{
	char	*str;

	if (data->format_data.length == LENGTH_Z)
	{
		str = ft_t_ptr(unbr == SIZE_MAX, "1",
				ft_nbrbase_nm(unbr, DECIMAL_BASE));
		ft_i_preprocess(data);
		return (ft_i_process(str, data, unbr == SIZE_MAX), true);
	}
	str = ft_nbrbase_nm(ft_t_int(nbr < 0, -nbr, nbr), DECIMAL_BASE);
	ft_i_preprocess(data);
	return (ft_i_process(str, data, nbr < 0), true);
}

bool	ft_i_header(t_pf_data *data)
{
	int64_t		nbr;
	uint64_t	unbr;

	nbr = 0;
	unbr = 0;
	if (data->format_data.length == LENGTH_NONE)
		nbr = va_arg(data->args, int);
	else if (data->format_data.length == LENGTH_HH)
		nbr = (signed char)va_arg(data->args, int);
	else if (data->format_data.length == LENGTH_H)
		nbr = (short int)va_arg(data->args, int);
	else if (data->format_data.length == LENGTH_L)
		nbr = va_arg(data->args, long int);
	else if (data->format_data.length == LENGTH_LL)
		nbr = va_arg(data->args, long long int);
	if (data->format_data.length == LENGTH_J)
		nbr = va_arg(data->args, intmax_t);
	else if (data->format_data.length == LENGTH_Z)
		unbr = va_arg(data->args, size_t);
	else if (data->format_data.length == LENGTH_T)
		nbr = va_arg(data->args, ptrdiff_t);
	return (ft_i_header_2(data, nbr, unbr));
}
