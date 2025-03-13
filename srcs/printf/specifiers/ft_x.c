/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:10:59 by gbetting          #+#    #+#             */
/*   Updated: 2025/03/13 13:08:42 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_x_process2(char *nbr, char *prefix, t_pf_data *data)
{
	int64_t	nbrlen;
	int64_t	len;
	int64_t	prefix_len;
	bool	sign;

	prefix_len = 0;
	nbrlen = ft_strlen(nbr);
	len = ft_max(nbrlen, data->format_data.precision);
	sign = (data->format_data.flags & FLAG_HASH && nbr[0] != '0');
	if (sign)
		prefix_len = ft_strlen(prefix);
	if (sign && !(data->format_data.flags & FLAG_ZERO))
		ft_buffer_str((unsigned char *)prefix, prefix_len, data);
	if (nbrlen != len)
		ft_buffer_char('0', len - nbrlen, data);
	ft_buffer_str((unsigned char *)nbr, nbrlen, data);
	if (data->format_data.flags & FLAG_MINUS
		&& data->format_data.width > (len + prefix_len))
		ft_buffer_char(' ', data->format_data.width - (len + prefix_len), data);
}

static void	ft_x_process(char *nbr, char *prefix, t_pf_data *data)
{
	int64_t	nbrlen;
	int64_t	len;
	int64_t	prefix_len;
	bool	sign;

	if (data->format_data.precision == 0 && nbr[0] == '0' && !nbr[1]
		&& data->format_data.width == 0 && data->format_data.flags == 0)
		nbr = "";
	else if (data->format_data.precision == 0 && nbr[0] == '0' && !nbr[1])
		nbr = " ";
	prefix_len = 0;
	nbrlen = ft_strlen(nbr);
	len = ft_max(nbrlen, data->format_data.precision);
	sign = (data->format_data.flags & FLAG_HASH && nbr[0] != '0');
	if (sign)
		prefix_len = ft_strlen(prefix);
	if (sign && data->format_data.flags & FLAG_ZERO)
		ft_buffer_str((unsigned char *)prefix, prefix_len, data);
	if (!(data->format_data.flags & FLAG_MINUS)
		&& data->format_data.width > (len + prefix_len))
		ft_buffer_char(ft_t_int(data->format_data.flags & FLAG_ZERO, '0', ' '),
			data->format_data.width - (len + prefix_len), data);
	ft_x_process2(nbr, prefix, data);
}

static void	ft_x_preprocess(t_pf_data *data, size_t nbr_len)
{
	if (data->format_data.flags & FLAG_ZERO && data->format_data.precision >= 0)
		data->format_data.flags &= ~FLAG_ZERO;
	if (data->format_data.specifier == 'o'
		&& data->format_data.flags & FLAG_HASH
		&& data->format_data.precision > (int64_t)nbr_len)
		data->format_data.flags &= ~FLAG_HASH;
}

static bool	ft_x_header2(t_pf_data *data, uint64_t unbr)
{
	char	*base;
	char	*prefix;
	char	*nbr;

	if (data->format_data.specifier == 'x')
	{
		base = BASE_16;
		prefix = BASE_16_PREFIX;
	}
	else if (data->format_data.specifier == 'X')
	{
		base = BASE_16U;
		prefix = BASE_16U_PREFIX_CAP;
	}
	else if (data->format_data.specifier == 'o')
	{
		base = BASE_8;
		prefix = BASE_8_PREFIX;
	}
	else
		return (false);
	nbr = ft_nbrbase_nm(unbr, base);
	ft_x_preprocess(data, ft_strlen(nbr));
	return (ft_x_process(nbr, prefix, data), true);
}

bool	ft_x_header(t_pf_data *data)
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
	return (ft_x_header2(data, unbr));
}
