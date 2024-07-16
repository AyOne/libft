/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:15:43 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/16 22:20:49 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_n_header(t_data *data)
{
	ft_buffer_clear(data);
	if (data->format_data.length == LENGTH_NONE)
		*(va_arg(data->args, int *)) = data->total_count;
	else if (data->format_data.length == LENGTH_HH)
		*(va_arg(data->args, signed char *)) = data->total_count;
	else if (data->format_data.length == LENGTH_H)
		*(va_arg(data->args, short *)) = data->total_count;
	else if (data->format_data.length == LENGTH_L)
		*(va_arg(data->args, long *)) = data->total_count;
	else if (data->format_data.length == LENGTH_LL)
		*(va_arg(data->args, long long *)) = data->total_count;
	else if (data->format_data.length == LENGTH_J)
		*(va_arg(data->args, intmax_t *)) = data->total_count;
	else if (data->format_data.length == LENGTH_Z)
		*(va_arg(data->args, size_t *)) = data->total_count;
	else if (data->format_data.length == LENGTH_T)
		*(va_arg(data->args, ptrdiff_t *)) = data->total_count;
	return (true);
}
