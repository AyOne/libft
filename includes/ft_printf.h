/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:46:59 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/16 22:20:02 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <stddef.h>

# include <stdio.h>

# include "libft.h"

# define BUFF_SIZE 1024
# define FORMAT_TRIGGER '%'
# define DECIMAL_BASE "0123456789"
# define HEXA_BASE "0123456789abcdef"
# define HEXA_BASE_CAP "0123456789ABCDEF"
# define OCTAL_BASE "01234567"
# define BINARY_BASE "01"
# define HEXA_PREFIX "0x"
# define HEXA_PREFIX_CAP "0X"
# define OCTAL_PREFIX "0"
# define BINARY_PREFIX "0b"

typedef enum e_flags
{
	FLAG_MINUS	=	1 << 0,
	FLAG_PLUS	=	1 << 1,
	FLAG_SPACE	=	1 << 2,
	FLAG_HASH	=	1 << 3,
	FLAG_ZERO	=	1 << 4
}		t_flags;

typedef enum e_length
{
	LENGTH_NONE	=	0,
	LENGTH_HH	=	1,
	LENGTH_H	=	2,
	LENGTH_L	=	3,
	LENGTH_LL	=	4,
	LENGTH_J	=	5,
	LENGTH_Z	=	6,
	LENGTH_T	=	7,
	LENGTH_LF	=	8
}		t_length;

typedef struct s_format
{
	uint64_t	flags;
	int64_t		width;
	int64_t		precision;
	uint64_t	length;
	char		specifier;
}		t_format;

typedef struct s_data
{
	int			fd;
	va_list		args;
	t_format	format_data;
	size_t		format_index;
	char		buffer[BUFF_SIZE];
	size_t		buff_index;
	size_t		total_count;
	bool		ff;
	bool		strout;
	char		**str_output;
}	t_data;

typedef struct s_specifier
{
	char		specifier;
	bool		(*function)(t_data * data);
}	t_specifier;

void		ft_format(const char *format, t_data *data);

// === BUFFER ===
void		ft_buffer_format(const char *format, t_data *data);
void		ft_buffer_clear(t_data *data);
void		ft_buffer_str(const unsigned char *str, size_t len, t_data *data);
void		ft_buffer_char(const char c, size_t count, t_data *data);

// === SPECIFIERS ===
bool		ft_c_header(t_data *data);
bool		ft_i_header(t_data *data);
bool		ft_p_header(t_data *data);
bool		ft_percent(t_data *data);
bool		ft_s_header(t_data *data);
bool		ft_u_header(t_data *data);
bool		ft_x_header(t_data *data);
bool		ft_n_header(t_data *data);
t_specifier	*ft_get_specifier(void);

#endif
