/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:46:59 by gbetting          #+#    #+#             */
/*   Updated: 2025/03/13 13:13:33 by gbetting         ###   ########.fr       */
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
# define BASE_16_PREFIX "0x"
# define BASE_16U_PREFIX_CAP "0X"
# define BASE_8_PREFIX "0"
# define BASE_2_PREFIX "0b"

typedef struct s_color
{
	uint8_t		text_blue;
	uint8_t		text_green;
	uint8_t		text_red;
	uint8_t		background_blue;
	uint8_t		background_green;
	uint8_t		background_red;
	uint16_t	flags;
}				t_color;

typedef union u_pf_color
{
	uint64_t	raw_data;
	t_color		color;
}	t_pf_color;

typedef enum e_pf_flags
{
	FLAG_MINUS	=	BIT_0,
	FLAG_PLUS	=	BIT_1,
	FLAG_SPACE	=	BIT_2,
	FLAG_HASH	=	BIT_3,
	FLAG_ZERO	=	BIT_4,
	FLAG_COLOR	=	BIT_5
}		t_pf_flags;

typedef enum e_pf_length
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
}		t_pf_length;

typedef struct s_pf_format
{
	uint64_t	flags;
	int64_t		width;
	int64_t		precision;
	uint64_t	length;
	char		specifier;
}		t_pf_format;

typedef struct s_pf_data
{
	int			fd;
	va_list		args;
	t_pf_format	format_data;
	size_t		format_index;
	char		buffer[BUFF_SIZE];
	size_t		buff_index;
	size_t		total_count;
	bool		ff;
	bool		fd_error;
	bool		strout;
	char		**str_output;
}	t_pf_data;

typedef struct s_pf_specifier
{
	char		specifier;
	bool		(*function)(t_pf_data * data);
}	t_pf_specifier;

void			ft_format(const char *format, t_pf_data *data);
int				ft_printf_process(const char *format, t_pf_data *data);

// === BUFFER ===
void			ft_buffer_format(const char *format, t_pf_data *data);
void			ft_buffer_clear(t_pf_data *data);
void			ft_buffer_str(const unsigned char *str, size_t len,
					t_pf_data *data);
void			ft_buffer_char(const char c, size_t count, t_pf_data *data);

// === COLOR ===
void			ft_color(t_pf_data *data);
void			ft_endcolor(t_pf_data *data);

// === SPECIFIERS ===
bool			ft_c_header(t_pf_data *data);
bool			ft_i_header(t_pf_data *data);
bool			ft_p_header(t_pf_data *data);
bool			ft_percent(t_pf_data *data);
bool			ft_s_header(t_pf_data *data);
bool			ft_u_header(t_pf_data *data);
bool			ft_x_header(t_pf_data *data);
bool			ft_n_header(t_pf_data *data);
t_pf_specifier	*ft_get_specifier(void);

#endif
