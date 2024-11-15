/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:53:21 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/15 01:44:27 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <sys/stat.h>
# include <fcntl.h>

/* =============================== [DEFINES] ================================ */
# define PF_FTEXT		BIT_48
# define PF_FBG			BIT_49
# define PF_FBOLD		BIT_50
# define PF_FULINE		BIT_51
# define PF_FITALIC		BIT_52
# define PF_FBLINK		BIT_53
# define PF_FREVERSE	BIT_54
# define PF_FSTHROUGH	BIT_55

# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_16U "0123456789ABCDEF"
# define BASE_2 "01"
# define BASE_8 "01234567"

# define BIT_0	0x1
# define BIT_1	0x2
# define BIT_2	0x4
# define BIT_3	0x8
# define BIT_4	0x10
# define BIT_5	0x20
# define BIT_6	0x40
# define BIT_7	0x80
# define BIT_8	0x100
# define BIT_9	0x200
# define BIT_10	0x400
# define BIT_11	0x800
# define BIT_12	0x1000
# define BIT_13	0x2000
# define BIT_14	0x4000
# define BIT_15	0x8000
# define BIT_16	0x10000
# define BIT_17	0x20000
# define BIT_18	0x40000
# define BIT_19	0x80000
# define BIT_20	0x100000
# define BIT_21	0x200000
# define BIT_22	0x400000
# define BIT_23	0x800000
# define BIT_24	0x1000000
# define BIT_25	0x2000000
# define BIT_26	0x4000000
# define BIT_27	0x8000000
# define BIT_28	0x10000000
# define BIT_29	0x20000000
# define BIT_30	0x40000000
# define BIT_31	0x80000000
# define BIT_32	0x100000000
# define BIT_33	0x200000000
# define BIT_34	0x400000000
# define BIT_35	0x800000000
# define BIT_36	0x1000000000
# define BIT_37	0x2000000000
# define BIT_38	0x4000000000
# define BIT_39	0x8000000000
# define BIT_40	0x10000000000
# define BIT_41	0x20000000000
# define BIT_42	0x40000000000
# define BIT_43	0x80000000000
# define BIT_44	0x100000000000
# define BIT_45	0x200000000000
# define BIT_46	0x400000000000
# define BIT_47	0x800000000000
# define BIT_48	0x1000000000000
# define BIT_49	0x2000000000000
# define BIT_50	0x4000000000000
# define BIT_51	0x8000000000000
# define BIT_52	0x10000000000000
# define BIT_53	0x20000000000000
# define BIT_54	0x40000000000000
# define BIT_55	0x80000000000000
# define BIT_56	0x100000000000000
# define BIT_57	0x200000000000000
# define BIT_58	0x400000000000000
# define BIT_59	0x800000000000000
# define BIT_60	0x1000000000000000
# define BIT_61	0x2000000000000000
# define BIT_62	0x4000000000000000
# define BIT_63	0x8000000000000000

typedef int64_t			(*t_cmpfunc)(void *, void *);
typedef void			*(*t_applyfunc)(void *);
typedef void			(*t_delfunc)(void *);

/* ========================= [DOUBLE CHAINED LIST] ========================== */
// #region DOUBLE CHAINED LIST
// TODO: Add documentation

typedef struct s_dlist_node
{
	void				*content;
	struct s_dlist_node	*next;
	struct s_dlist_node	*prev;
}						t_dlist_node;

typedef struct s_dlist
{
	t_dlist_node	*head;
	t_dlist_node	*tail;
	size_t			size;
}						t_dlist;

typedef enum s_dlist_rtrn
{
	DLIST_CONTINUE	= 0,
	DLIST_BREAK		= 1 << 0,
	DLIST_DELETE	= 1 << 1,
}						t_dlist_rtrn;

typedef t_dlist_rtrn	(*t_iterfunc)(void *, size_t, void *);

/**
 * @brief The ft_dlstadd_back() function adds a new element at the end of the
 * list.
 * @param lst The list to add the element to.
 * @param new The new element to add.
 * @return The updated list.
 */
t_dlist		*ft_dlstadd_back(t_dlist *lst, void *new);

/**
 * @brief The ft_dlstadd_front() function adds a new element at the beginning of
 * the list.
 * @param lst The list to add the element to.
 * @param new The new element to add.
 * @return The updated list.
 */
t_dlist		*ft_dlstadd_front(t_dlist *lst, void *new);

/**
 * @brief The ft_dlstadd_at() function adds a new element at a specific index in
 * the list.
 * @param lst The list to add the element to.
 * @param content The content of the new element.
 * @param index The index to add the element at.
 * @return The updated list.
 */
t_dlist		*ft_dlstadd_at(t_dlist *lst, void *content, size_t index);

/**
 * @brief The ft_dlstclear() function clears the list and deletes its content
 * using the provided function.
 * @param lst The list to clear.
 * @param del The function to delete the content.
 */
void		ft_dlstclear(t_dlist *lst, void (*del)(void *));

/**
 * @brief The ft_dlstfree() function frees the list and its content using the
 * provided function.
 * @param lst The list to free.
 * @param del The function to delete the content.
 */
void		ft_dlstfree(t_dlist *lst, void (*del)(void *));

/**
 * @brief The ft_dlstfind() function finds an element in the list using the
 * provided comparison function.
 * @param lst The list to search.
 * @param content The content to find.
 * @param cmp The comparison function.
 * @return The found element or NULL if not found.
 */
void		*ft_dlstfind(t_dlist *lst, void *content, t_cmpfunc cmp);

/**
 * @brief The ft_dlstsize() function returns the size of the list.
 * @param lst The list to get the size of.
 * @return The size of the list.
 */
size_t		ft_dlstsize(t_dlist *lst);

/**
 * @brief The ft_dlstget() function gets the element at a specific index in the
 * list.
 * @param lst The list to get the element from.
 * @param index The index of the element.
 * @return The element at the specified index.
 */
void		*ft_dlstget(t_dlist *lst, size_t index);

/**
 * @brief The ft_dlstfirst() function returns the first element of the list.
 * @param lst The list to get the first element from.
 * @return The first element of the list.
 */
void		*ft_dlstfirst(t_dlist *lst);

/**
 * @brief The ft_dlstlast() function returns the last element of the list.
 * @param lst The list to get the last element from.
 * @return The last element of the list.
 */
void		*ft_dlstlast(t_dlist *lst);

/**
 * @brief The ft_dlstiter_from() function iterates over the list from a specific
 * index and applies the provided function.
 * @param lst The list to iterate over.
 * @param f The function to apply.
 * @param index The index to start iterating from.
 * @param args The arguments to pass to the function.
 */
void		ft_dlstiter_from(t_dlist *lst, t_iterfunc f, size_t index,
				void *args);

/**
 * @brief The ft_dlstiter() function iterates over the list and applies the
 * provided function.
 * @param lst The list to iterate over.
 * @param f The function to apply.
 * @param args The arguments to pass to the function.
 */
void		ft_dlstiter(t_dlist *lst, t_iterfunc f, void *args);

/**
 * @brief The ft_dlstmap() function creates a new list by applying the provided
 * function to each element of the list.
 * @param lst The list to map.
 * @param f The function to apply.
 * @param del The function to delete the content if needed.
 * @return The new list.
 */
t_dlist		*ft_dlstmap(t_dlist *lst, t_applyfunc f, t_delfunc del);

/**
 * @brief The ft_dlstnew() function creates a new empty list.
 * @return The new list.
 */
t_dlist		*ft_dlstnew(void);

/**
 * @brief The ft_dlstpop_front() function removes and returns the first element
 * of the list.
 * @param lst The list to pop the element from.
 * @return The popped element.
 */
void		*ft_dlstpop_front(t_dlist *lst);

/**
 * @brief The ft_dlstpop_back() function removes and returns the last element
 * of the list.
 * @param lst The list to pop the element from.
 * @return The popped element.
 */
void		*ft_dlstpop_back(t_dlist *lst);

/**
 * @brief The ft_dlstpop_at() function removes and returns the element at a
 * specific index in the list.
 * @param lst The list to pop the element from.
 * @param index The index of the element.
 * @return The popped element.
 */
void		*ft_dlstpop_at(t_dlist *lst, size_t index);

/**
 * @brief The ft_dlstto_array() function converts the list to an array.
 * @param dlst The list to convert.
 * @return The array of elements.
 */
void		**ft_dlstto_array(t_dlist *dlst);

/**
 * @brief The ft_dlstto_array_free() function converts the list to an array and
 * frees the list.
 * @param dlst The list to convert.
 * @param del The function to delete the content.
 * @return The array of elements.
 */
void		**ft_dlstto_array_free(t_dlist *dlst, void (*del)(void *));

// #endregion

/* ============================ [GET_NEXT_LINE] ============================= */
// #region GET_NEXT_LINE
/**
 * @brief The get_next_line() function reads a line from a file descriptor.
 * @param fd The file descriptor to read from.
 * @return The get_next_line() function returns the line read from the file
 * descriptor.
 * @note to avoid any leaks if not all lines are read for a given file
 * descriptor, close the file descriptor and call get_next_line() again.
 */
char		*get_next_line(int fd);
/**
 * @brief The gnl() function is an alias for the get_next_line() function.
 */
char		*gnl(int fd);

// #endregion

/* ================================= [MATH] ================================= */
// #region MATH
/**
 * @brief The abs() function computes the absolute value of an integer.
 * @param n The integer to compute the absolute value of.
 * @return The abs() function returns the absolute value of the integer.
 */
int64_t		ft_abs(int64_t n);
/**
 * @brief The min() function returns the smallest of the two integers.
 * @param a The first integer to compare.
 * @param b The second integer to compare.
 * @return The min() function returns the smallest of the two integers.
 */
int64_t		ft_min(int64_t a, int64_t b);
/**
 * @brief The max() function returns the largest of the two integers.
 * @param a The first integer to compare.
 * @param b The second integer to compare.
 * @return The max() function returns the largest of the two integers.
 */
int64_t		ft_max(int64_t a, int64_t b);
/**
 * @brief The minu() function returns the smallest of the two unsigned integers.
 * @param a The first unsigned integer to compare.
 * @param b The second unsigned integer to compare.
 * @return The minu() function returns the smallest of the two unsigned
 * integers.
 */
uint64_t	ft_minu(uint64_t a, uint64_t b);
/**
 * @brief The maxu() function returns the largest of the two unsigned integers.
 * @param a The first unsigned integer to compare.
 * @param b The second unsigned integer to compare.
 * @return The maxu() function returns the largest of the two unsigned integers.
 */
uint64_t	ft_maxu(uint64_t a, uint64_t b);

// #endregion

/* ================================ [MEMORY] ================================ */
// #region MEMORY
/**
 * @brief The bzero() function writes n zeroed bytes to the string s. If n is
 * zero, bzero() does nothing.
 * @param s The string to write to.
 * @param n The number of bytes to write.
 */
void		ft_bzero(void *s, size_t n);
/**
 * @brief The calloc() function allocates memory for an array of nmemb elements
 * of size bytes each and returns a pointer to the allocated memory. The memory
 * is set to zero. If nmemb or size is 0, then calloc() returns either NULL, or
 * a unique pointer value that can later be successfully passed to free().
 * @param nmemb The number of elements to allocate memory for.
 * @param size The size of each element.
 * @return The calloc() function returns a pointer to the allocated memory.
 */
void		*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief The memchr() function locates the first occurrence of c in memory area
 * s. The memchr() function returns a pointer to the located byte, or NULL if no
 * such byte exists within n bytes.
 * @param s The memory area to search.
 * @param c The character to search for.
 * @param n The number of bytes to search.
 * @return The memchr() function returns a pointer to the located byte, or NULL
 * if no such byte exists within n bytes.
 */
void		*ft_memchr(const void *s, int8_t c, size_t n);
/**
 * @brief The memcmp() function compares the first n bytes (each interpreted as
 * unsigned char) of the memory areas s1 and s2.
 * @param s1 The first memory area to compare.
 * @param s2 The second memory area to compare.
 * @param n The number of bytes to compare.
 * @return The memcmp() function returns an integer less than, equal to, or
 * greater than zero if the first n bytes of s1 is found, respectively, to be
 * less than, to match, or be greater than the first n bytes of s2.
 */
int32_t		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief The memcpy() function copies n bytes from memory area src to memory
 * area dst. If dst and src overlap, behavior is undefined. Applications in
 * which dst and src might overlap should use memmove(3) instead.
 * @param dst The destination to copy to.
 * @param src The source to copy from.
 * @param n The number of bytes to copy.
 * @return The memcpy() function returns the original value of dst.
 */
void		*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief The memdup() function allocates sufficient memory for a copy of the
 * memory area.
 * @param src The source memory area to copy.
 * @param size The size of the memory area to copy.
 * @return Pointer to the duplicated memory area, or NULL if allocation fails.
 */
void		*ft_memdup(const void *src, size_t size);
/**
 * @brief The memmove() function copies len bytes from string src to string dst.
 * The two strings may overlap; the copy is always done in a non-destructive
 * manner.
 * @param dst The destination to copy to.
 * @param src The source to copy from.
 * @param len The number of bytes to copy.
 * @return The memmove() function returns the original value of dst.
 */
void		*ft_memmove(void *dst, const void *src, size_t len);
/**
 * @brief The memset() function fills the first len bytes of the memory area
 * pointed to by b with the constant byte c.
 * @param b The memory area to fill.
 * @param c The byte to fill the memory area with.
 * @param len The number of bytes to fill.
 * @return The memset() function returns a pointer to the memory area b.
 */
void		*ft_memset(void *b, char c, size_t len);

// #endregion

/* ================================ [PRINTF] ================================ */
// #region PRINTF
/**
 * @brief The printf() function writes the output to stdout, under the control
 * of a format string that specifies how subsequent arguments are converted for
 * output.
 * @param format The format string.
 * @param ... The arguments to convert.
 * @return The printf() function returns the number of characters printed (not
 * including the null byte used to end output to strings).
 * @note for more information, you can refer to this link :
 * https://cplusplus.com/reference/cstdio/printf/
 */
int			ft_printf(const char *format, ...);
//			__attribute__((format(printf, 1, 2)));
/**
 * @brief The dprintf() function writes the output to the file descriptor fd,
 * under the control of a format string that specifies how subsequent arguments
 * are converted for output.
 * @param fd The file descriptor to write to.
 * @param format The format string.
 * @param ... The arguments to convert.
 * @return The dprintf() function returns the number of characters printed (not
 * including the null byte used to end output to strings).
 * @note for more information, you can refer to this link :
 * https://cplusplus.com/reference/cstdio/printf/
 */
int			ft_dprintf(int fd, const char *format, ...);
//			__attribute__((format(printf, 2, 3)));
/**
 * @brief The asprintf() function writes the output to a string allocated by
 * malloc(), under the control of a format string that specifies how subsequent
 * arguments are converted for output.
 * @param str The address of a pointer to the string to write to.
 * @param format The format string.
 * @param ... The arguments to convert.
 * @return The asprintf() function returns the number of characters printed (not
 * including the null byte used to end output to strings).
 * @note for more information, you can refer to this link :
 * https://cplusplus.com/reference/cstdio/printf/
 */
int			ft_asprintf(char **str, const char *format, ...);
//			__attribute__((format(printf, 2, 3)));

// #endregion

/* =============================== [STRINGS] ================================ */
// #region STRINGS
/**
 * @brief The atoi() function converts the initial portion of the string pointed
 * to by str to int representation.
 * @param str The string to convert.
 * @return The atoi() function returns the converted value.
 */
int64_t		ft_atoi(const char *str);
/**
 * @brief The isalnum() function tests for any character for which isalpha(3)
 * or isdigit(3) is true. The value of the argument must be representable as an
 * unsigned char or the value of EOF.
 * @param c The character to test.
 * @return The isalnum() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
 */
bool		ft_isalnum(char c);
/**
 * @brief The isalpha() function tests for any character for which isupper(3)
 * or islower(3) is true. The value of the argument must be representable as
 * an unsigned char or the value of EOF.
 * @param c The character to test.
 * @return The isalpha() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
 */
bool		ft_isalpha(char c);
/**
 * @brief The isascii() function tests for an ASCII character, which is any
 * character between 0 and octal 0177 inclusive.
 * @param c The character to test.
 * @return The isascii() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
 */
bool		ft_isascii(char c);
/**
 * @brief The isdigit() function tests for a decimal digit character.
 * Regardless of locale, this includes the following characters
 * only: '0' - '9'.
 * @param c The character to test.
 * @return The isdigit() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
 */
bool		ft_isdigit(char c);
/**
 * @brief The isprint() function tests for any printing character, including
 * space (' '). The value of the argument must be representable as an unsigned
 * char or the value of EOF.
 * @param c The character to test.
 * @return The isprint() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
 */
bool		ft_isprint(char c);
/**
 * @brief The itoa_nm() function returns a static string representing the
 * integer received as an argument without malloc.
 * @param n The integer to convert.
 * @return The itoa_nm() function returns the string representing the integer.
 * @note Do not free or store the returned string.
 */
char		*ft_itoa_nm(int32_t n);

/**
 * @brief The ft_ltoa_nm() function returns a static string representing the
 * long integer received as an argument without malloc.
 * @param n The long integer to convert.
 * @return The ft_ltoa_nm() function returns the string representing the long
 * integer.
 * @note Do not free or store the returned string.
 */
char		*ft_ltoa_nm(int64_t n);

/**
 * @brief The ft_uitoa_nm() function returns a static string representing the
 * unsigned integer received as an argument without malloc.
 * @param n The unsigned integer to convert.
 * @return The ft_uitoa_nm() function returns the string representing the
 * unsigned integer.
 * @note Do not free or store the returned string.
 */
char		*ft_uitoa_nm(uint32_t n);

/**
 * @brief The ft_ultoa_nm() function returns a static string representing the
 * unsigned long integer received as an argument without malloc.
 * @param n The unsigned long integer to convert.
 * @return The ft_ultoa_nm() function returns the string representing the
 * unsigned long integer.
 * @note Do not free or store the returned string.
 */
char		*ft_ultoa_nm(uint64_t n);

/**
 * @brief The itoa() function allocates and returns a string representing the
 * integer received as an argument.
 * @param n The integer to convert.
 * @return The itoa() function returns the string representing the integer.
 */
char		*ft_itoa(int32_t n);

/**
 * @brief The ft_ltoa() function allocates and returns a string representing the
 * long integer received as an argument.
 * @param n The long integer to convert.
 * @return The ft_ltoa() function returns the string representing the long
 * integer.
 */
char		*ft_ltoa(int64_t n);

/**
 * @brief The ft_uitoa() function allocates and returns a string representing
 * the
 * unsigned integer received as an argument.
 * @param n The unsigned integer to convert.
 * @return The ft_uitoa() function returns the string representing the unsigned
 * integer.
 */
char		*ft_uitoa(uint32_t n);

/**
 * @brief The ft_ultoa() function allocates and returns a string representing
 * the
 * unsigned long integer received as an argument.
 * @param n The unsigned long integer to convert.
 * @return The ft_ultoa() function returns the string representing the unsigned
 * long integer.
 */
char		*ft_ultoa(uint64_t n);

/**
 * @brief The split() function allocates and returns an array of strings
 * obtained by splitting 's' using the character 'c' as a delimiter. The array
 * must be ended by a NULL pointer.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return The split() function returns the array of new strings.
 */
char		**ft_split(char const *s, char c);
/**
 * @brief The strchr() function locates the first occurrence of c (converted to
 * a char) in the string pointed to by s. The terminating null character is
 * considered to be part of the string; therefore if c is '\0', the functions
 * locate the terminating '\0'.
 * @param s The string to search.
 * @param c The character to search for.
 * @return The strchr() function returns a pointer to the located character, or
 * NULL if the character does not appear in the string.
 */
char		*ft_strchr(const char *s, char c);
/**
 * @brief Locates the first occurrence of a character in a string, 
 * but only within the first 'size' characters. This function searches for the
 * first occurrence of the character 'c' in the string 's', but only within the
 * first 'size' characters of 's'.
 * @param s The string to be searched.
 * @param c The character to be located.
 * @param size The maximum number of characters to search.
 * @return A pointer to the first occurrence of the character 'c' 
 * in the string 's', or NULL if the character is not found 
 * within the first 'size' characters.
 */
char		*ft_strnchr(const char *s, char c, size_t size);
/**
 * @brief The strdup() function allocates sufficient memory for a copy of the
 * string s1, does the copy, and returns a pointer to it. The pointer may
 * subsequently be used as an argument to the function free(3).
 * @param s The string to duplicate.
 * @return The strdup() function returns a pointer to the duplicated string.
 */
char		*ft_strdup(const char *s);
/**
 * @brief the striteri() function applies the function 'f' to each character of
 * the string 's', and passing its index as first argument. Each character is
 * passed by address to 'f' to be modified if necessary.
 * @param s The string to iterate.
 * @param f The function to apply.
 * @return The striteri() function returns the new string.
 */
void		ft_striteri(char *s, void (*f)(uint32_t, char *));
/**
 * @brief The strjoin() function allocates and returns a new string, which is
 * the result of the concatenation of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The strjoin() function returns the new string.
 */
char		*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief The strlcat() function concatenates strings.
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return Total length of the string that would have been created.
 */
size_t		ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @brief The strlcpy() function copies strings.
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return Length of src (the string it tried to create).
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
/**
 * @brief The strlen() function calculates the length of the string s, excluding
 * the terminating null byte ('\0').
 * @param s The string to calculate the length of.
 * @return The strlen() function returns the number of bytes in the string s.
 */
size_t		ft_strlen(const char *s);
/**
 * @brief The strmapi() function applies the function 'f' to each character of
 * the string 's' to create a new string resulting from successive applications
 * of 'f'.
 * @param s The string to map.
 * @param f The function to apply.
 * @return The strmapi() function returns the new string.
 */
char		*ft_strmapi(char const *s, char (*f)(uint32_t, char));
/**
 * @brief The strncmp() function compares the two strings s1 and s2. It compares
 * not more than n characters. Because strncmp() is designed for comparing
 * strings rather than binary data, characters that appear after a '\0'
 * character are not compared.
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The number of characters to compare.
 * @return The strncmp() function returns an integer greater than, equal to, or
 * less than 0, according as the string s1 is greater than, equal to, or less
 * than the string s2. The comparison is done using unsigned characters, so that
 * '\200' is greater than '\0'.
 */
int32_t		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief The strnstr() function locates the first occurrence of the null-
 * terminated string needle in the string haystack, where not more than len
 * characters are searched. Characters that appear after a '\0' character are
 * not searched.
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @param len The number of characters to search.
 * @return The strnstr() function returns a pointer to the located string, or
 * NULL if the string is not found.
 */
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
/**
 * @brief The strrchr() function locates the last occurrence of c (converted to
 * a char) in the string pointed to by s. The terminating null character is
 * considered to be part of the string; therefore if c is '\0', the functions
 * locate the terminating '\0'.
 * @param s The string to search.
 * @param c The character to search for.
 * @return The strrchr() function returns a pointer to the located character, or
 * NULL if the character does not appear in the string.
 */
char		*ft_strrchr(const char *s, char c);
/**
 * @brief The strtrim() function allocates and returns a copy of 's1' with the
 * characters specified in 'set' removed from the beginning and the end of the
 * string.
 * @param s1 The string to trim.
 * @param set The set of characters to trim.
 * @return The strtrim() function returns the trimmed string.
 */
char		*ft_strtrim(char const *s1, char const *set);
/**
 * @brief The substr() function allocates and returns a substring from the
 * string 's'. The substring begins at index 'start' and is of maximum size
 * 'len'.
 * @param s The string to create the substring from.
 * @param start The start index of the substring.
 * @param len The maximum size of the substring.
 * @return The substr() function returns the substring.
 */
char		*ft_substr(char const *s, uint32_t start, size_t len);
/**
 * @brief The tolower() function converts an upper-case letter to the
 * corresponding lower-case letter. The argument must be representable as an
 * unsigned char or the value of EOF.
 * @param c The character to convert.
 * @return If the argument is an upper-case letter, the tolower() function
 * returns the corresponding lower-case letter if there is one; otherwise, the
 * argument is returned unchanged.
 */
char		ft_tolower(char c);
/**
 * @brief The toupper() function converts a lower-case letter to the
 * corresponding upper-case letter. The argument must be representable as an
 * unsigned char or the value of EOF.
 * @param c The character to convert.
 * @return If the argument is a lower-case letter, the toupper() function
 * returns the corresponding upper-case letter if there is one; otherwise, the
 * argument is returned unchanged.
 */
char		ft_toupper(char c);
// #endregion

/* ================================ [UTILS] ================================= */
// #region UTILS
/**
 * @brief The ft_nbrbase() function converts a number to a string in a given
 * base.
 * @param nbr The number to convert.
 * @param base The string containing the base characters.
 * @return The string representation of the number in the given base.
 */
char		*ft_nbrbase(uint64_t nbr, char *base);
/**
 * @brief The ft_nbrbase_nm() function converts a number to a string without
 * malloc.
 * @param nbr The number to convert.
 * @param base The string containing the base characters.
 * @return A static string containing the number in the given base.
 * @note Do not free or store the returned string.
 */
char		*ft_nbrbase_nm(uint64_t nbr, char *base);
/**
 * @brief Calculates the length of a number in a given base.
 * @param nbr The number to calculate the length of.
 * @param base The string containing the base characters.
 * @return The length of the number when expressed in the given base.
 */
size_t		ft_nbrlen(uint64_t nbr, char *base);
/**
 * @brief The t_int() function returns the first integer if the condition is
 * true, otherwise the second integer.
 * @param condition The condition to check.
 * @param a The first integer.
 * @param b The second integer.
 * @return The t_int() function returns the first integer if the condition is
 * true, otherwise the second integer.
 */
int64_t		ft_t_int(bool condition, int64_t a, int64_t b);
/**
 * @brief The t_uint() function returns the first unsigned integer if the
 * condition is true, otherwise the second unsigned integer.
 * @param condition The condition to check.
 * @param a The first unsigned integer.
 * @param b The second unsigned integer.
 * @return The t_uint() function returns the first unsigned integer if the
 * condition is true, otherwise the second unsigned integer.
 */
uint64_t	ft_t_uint(bool condition, uint64_t a, uint64_t b);
/**
 * @brief The t_double() function returns the first double if the condition is
 * true, otherwise the second double.
 * @param condition The condition to check.
 * @param a The first double.
 * @param b The second double.
 * @return The t_double() function returns the first double if the condition is
 * true, otherwise the second double.
 */
double		ft_t_double(bool condition, double a, double b);
/**
 * @brief The t_ptr() function returns the first pointer if the condition is
 * true, otherwise the second pointer.
 * @param condition The condition to check.
 * @param a The first pointer.
 * @param b The second pointer.
 * @return The t_ptr() function returns the first pointer if the condition is
 * true, otherwise the second pointer.
 */
void		*ft_t_ptr(bool condition, void *a, void *b);
/**
 * @brief The qsort() function sorts an array of 'size' elements using the
 * quicksort algorithm.
 * @param array The array to sort.
 * @param size The number of elements in the array.
 */
void		ft_qsort(int64_t *array, size_t size);
/**
 * @brief The qsort_cmp() function sorts an array using quicksort algorithm.
 * @param array Array of pointers to be sorted.
 * @param size Number of elements in the array.
 * @param cmp Comparison function returning negative if first should be before
 * second, zero if equal, positive if first should be after second.
 */
void		ft_qsort_cmp(void **array, size_t size, t_cmpfunc cmp);
/**
 * @brief The xorshift64() function generates pseudo-random numbers.
 * @return A high-quality pseudo-random 64-bit value.
 * @note Must call ft_setseed() or ft_init_random() before first use.
 */
uint64_t	ft_xorshift64(void);
/**
 * @brief The ft_setseed() function sets the seed for the xorshift64 algorithm.
 * @param seed The seed to set.
 */
void		ft_setseed(uint64_t seed);
/**
 * @brief The ft_init_random() function initializes the seed for the xorshift64
 * algorithm.
 * @note The seed is initialized using /dev/random. If /dev/random is not
 * available, the seed is initialized using the address of the function
 * ft_init_random.
 */
void		ft_init_random(void);

// #endregion

#endif
