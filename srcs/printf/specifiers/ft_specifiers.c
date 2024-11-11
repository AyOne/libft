/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:22:57 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/11 01:48:23 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// this will be removed and put in a function later

t_pf_specifier	*ft_get_specifier(void)
{
	static const t_pf_specifier	specifiers[] = {
	{'c', ft_c_header},
	{'s', ft_s_header},
	{'d', ft_i_header},
	{'i', ft_i_header},
	{'u', ft_u_header},
	{'x', ft_x_header},
	{'X', ft_x_header},
	{'o', ft_x_header},
	{'p', ft_p_header},
	{'n', ft_n_header},
	{'%', ft_percent},
	{0, NULL}
	};

	return ((t_pf_specifier *)specifiers);
}
