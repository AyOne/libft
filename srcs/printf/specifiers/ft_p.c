/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:59:31 by gbetting          #+#    #+#             */
/*   Updated: 2025/03/13 13:08:01 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_p_process(const char *nbr, const char *prefix, t_pf_data *data)
{
	int64_t	nbrlen;
	int64_t	len;
	int64_t	prefix_len;
	bool	sign;

	prefix_len = 0;
	nbrlen = ft_strlen(nbr);
	len = ft_max(nbrlen, data->format_data.precision);
	sign = prefix != NULL;
	if (sign)
		prefix_len = ft_strlen(prefix);
	if (sign && data->format_data.flags & FLAG_ZERO)
		ft_buffer_str((unsigned char *)prefix, prefix_len, data);
	if (!(data->format_data.flags & FLAG_MINUS)
		&& data->format_data.width > (len + prefix_len))
		ft_buffer_char(ft_t_int(data->format_data.flags & FLAG_ZERO, '0', ' '),
			data->format_data.width - (len + prefix_len), data);
	if (sign && !(data->format_data.flags & FLAG_ZERO))
		ft_buffer_str((unsigned char *)prefix, prefix_len, data);
	if (nbrlen != len)
		ft_buffer_char('0', len - nbrlen, data);
	ft_buffer_str((unsigned char *)nbr, nbrlen, data);
	if (data->format_data.flags & FLAG_MINUS
		&& data->format_data.width > (len + prefix_len))
		ft_buffer_char(' ', data->format_data.width - (len + prefix_len), data);
}

bool	ft_p_header(t_pf_data *data)
{
	uint64_t	unbr;

	if (data->format_data.length != LENGTH_NONE)
		return (false);
	unbr = va_arg(data->args, uint64_t);
	if (unbr == 0)
		return (ft_p_process("(nil)", NULL, data), true);
	return (ft_p_process(ft_nbrbase_nm(unbr, BASE_16),
			BASE_16_PREFIX, data), true);
}
