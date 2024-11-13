/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:16:47 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/13 23:35:21 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_color_text(t_pf_data *data, t_pf_color color)
{
	char	*str;

	ft_buffer_str((unsigned char *)";38;2;", 7, data);
	str = ft_itoa_nm(color.color.text_red);
	ft_buffer_str((unsigned char *)str, ft_strlen(str), data);
	ft_buffer_char(';', 1, data);
	str = ft_itoa_nm(color.color.text_green);
	ft_buffer_str((unsigned char *)str, ft_strlen(str), data);
	ft_buffer_char(';', 1, data);
	str = ft_itoa_nm(color.color.text_blue);
	ft_buffer_str((unsigned char *)str, ft_strlen(str), data);
}

static void	ft_color_background(t_pf_data *data, t_pf_color color)
{
	char	*str;

	ft_buffer_str((unsigned char *)";48;2;", 7, data);
	str = ft_itoa_nm(color.color.background_red);
	ft_buffer_str((unsigned char *)str, ft_strlen(str), data);
	ft_buffer_char(';', 1, data);
	str = ft_itoa_nm(color.color.background_green);
	ft_buffer_str((unsigned char *)str, ft_strlen(str), data);
	ft_buffer_char(';', 1, data);
	str = ft_itoa_nm(color.color.background_blue);
	ft_buffer_str((unsigned char *)str, ft_strlen(str), data);
}

static void	ft_color_flags(t_pf_data *data, t_pf_color color)
{
	if (color.color.flags & (PF_FBOLD >> 48))
		ft_buffer_str((unsigned char *)";1", 2, data);
	if (color.color.flags & (PF_FULINE >> 48))
		ft_buffer_str((unsigned char *)";4", 2, data);
	if (color.color.flags & (PF_FITALIC >> 48))
		ft_buffer_str((unsigned char *)";3", 2, data);
	if (color.color.flags & (PF_FBLINK >> 48))
		ft_buffer_str((unsigned char *)";5", 2, data);
	if (color.color.flags & (PF_FREVERSE >> 48))
		ft_buffer_str((unsigned char *)";7", 2, data);
	if (color.color.flags & (PF_FSTHROUGH >> 48))
		ft_buffer_str((unsigned char *)";9", 2, data);
}

void	ft_color(t_pf_data *data)
{
	t_pf_color	color;

	color = (t_pf_color)va_arg(data->args, uint64_t);
	if (color.color.flags == 0)
		return ;
	ft_buffer_str((unsigned char *)"\033[0", 3, data);
	ft_color_flags(data, color);
	if (color.color.flags & (PF_FTEXT >> 48))
		ft_color_text(data, color);
	if (color.color.flags & (PF_FBG >> 48))
		ft_color_background(data, color);
	ft_buffer_char('m', 1, data);
}

void	ft_endcolor(t_pf_data *data)
{
	ft_buffer_str((unsigned char *)"\033[0m", 4, data);
}
