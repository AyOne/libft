/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:53:21 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/18 21:11:10 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>

/* =============================== [DEFINES] ================================ */

# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_16U "0123456789ABCDEF"
# define BASE_2 "01"
# define BASE_8 "01234567"

typedef int64_t			(*t_cmpfunc)(void *, void *);
typedef void			*(*t_applyfunc)(void *);
typedef void			(*t_delfunc)(void *);

/* ========================= [DOUBLE CHAINED LIST] ========================== */
// #region DOUBLE CHAINED LIST

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

t_dlist		*ft_dlstadd_back(t_dlist *lst, void *new);
t_dlist		*ft_dlstadd_front(t_dlist *lst, void *new);
void		ft_dlstclear(t_dlist *lst, void (*del)(void *));
void		ft_dlstfree(t_dlist *lst, void (*del)(void *));
void		*ft_dlstfind(t_dlist *lst, void *content, t_cmpfunc cmp);
size_t		ft_dlstsize(t_dlist *lst);
void		*ft_dlstget(t_dlist *lst, size_t index);
void		*ft_dlstfirst(t_dlist *lst);
void		*ft_dlstlast(t_dlist *lst);
void		ft_dlstiter_from(t_dlist *lst, t_iterfunc f, size_t index,
				void *args);
void		ft_dlstiter(t_dlist *lst, t_iterfunc f, void *args);
t_dlist		*ft_dlstmap(t_dlist *lst, t_applyfunc f, t_delfunc del);
t_dlist		*ft_dlstnew(void);
void		*ft_dlstpop_front(t_dlist *lst);
void		*ft_dlstpop_back(t_dlist *lst);
void		*ft_dlstpop_at(t_dlist *lst, size_t index);

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

/* =========================== [CHAINED LIST] =============================== */
// #region CHAINED LIST
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/**
 * @brief The lstnew() function allocates and returns a new element. The
 * variable 'content' is initialized with the value of the parameter 'content'.
 * The variable 'next' is initialized to NULL.
 * @param content The content to create the new element with.
 * @return The lstnew() function returns the new element.
 */
t_list		*ft_lstnew(void *content);
/**
 * @brief The lstadd_front() function adds the element 'new' at the beginning of
 * the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void		ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief The lstsize() function counts the number of elements in a list.
 * @param lst The beginning of the list.
 * @return The lstsize() function returns the number of elements in the list.
 */
size_t		ft_lstsize(t_list *lst);
/**
 * @brief The lstlast() function returns the last element of the list.
 * @param lst The beginning of the list.
 * @return The lstlast() function returns the last element of the list.
 */
t_list		*ft_lstlast(t_list *lst);
/**
 * @brief The lstadd_back() function adds the element 'new' at the end of the
 * list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief The lstdelone() function takes as a parameter an element and frees the
 * memory of the element's content using the function 'del' given as a parameter
 * and free the element. The memory of 'next' must not be freed.
 * @param lst The element to free.
 * @param del The address of the function used to delete the content.
 */
void		ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief The lstdel() function takes as a parameter the address of a pointer to
 * an element and frees the memory of this element and all its successors using
 * the function 'del' and free(). Finally, the pointer must be set to NULL.
 * @param lst The address of a pointer to the first link of a list.
 * @param del The address of the function used to delete the content.
 */
void		ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief The lstiter() function iterates the list 'lst' and applies the
 * function 'f' to the content of each element.
 * @param lst The beginning of the list.
 * @param f The address of the function to apply.
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief The lstmap() function iterates the list 'lst' and applies the function
 * 'f' to the content of each element. Creates a new list resulting of the
 * successive applications of the function 'f'. The 'del' function is used to
 * delete the content of an element if needed.
 * @param lst The beginning of the list.
 * @param f The address of the function to apply.
 * @param del The address of the function used to delete the content.
 * @return The lstmap() function returns the new list.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

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
 * @return The minu() function returns the smallest of the two unsigned integers.
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
int			ft_printf(const char *format, ...)
			__attribute__((format(printf, 1, 2)));
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
int			ft_dprintf(int fd, const char *format, ...)
			__attribute__((format(printf, 2, 3)));
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
int			ft_asprintf(char **str, const char *format, ...)
			__attribute__((format(printf, 2, 3)));

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
char		*ft_itoa_nm(int64_t n);
/**
 * @brief The itoa() function allocates and returns a string representing the
 * integer received as an argument.
 * @param n The integer to convert.
 * @return The itoa() function returns the string representing the integer.
 */
char		*ft_itoa(int64_t n);
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
 * @brief The strlcat() function appends the NUL-terminated string src to the
 * end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL
 * terminating the result.
 * @param dst The destination to append to.
 * @param src The source to append from.
 * @param size The size of the destination buffer.
 * @return The strlcat() function returns the total length of the string it
 * tried to create.
 */
size_t		ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @brief The strlcpy() function copies up to size - 1 characters from the NUL-
 * terminated string src to dst, NUL-terminating the result.
 * @param dst The destination to copy to.
 * @param src The source to copy from.
 * @param size The size of the destination buffer.
 * @return The strlcpy() function returns the total length of the string it
 * tried to create.
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
 * @param base The base to convert the number to.
 * @return The ft_nbrbase() function returns the string representation of the
 * number in the given base.
 */
char		*ft_nbrbase(uint64_t nbr, char *base);
/**
 * @brief The ft_nbrbase_nm() function converts a number to a string in a given
 * base without malloc.
 * @param nbr The number to convert.
 * @param base The base to convert the number to.
 * @return The ft_nbrbase_nm() function returns the string representation of the
 * number in the given base.
 * @note Do not free or store the returned string.
 */
char		*ft_nbrbase_nm(uint64_t nbr, char *base);
/**
 * @brief The ft_nbrlen() function calculates the length of a number in a given
 * base.
 * @param nbr The number to calculate the length of.
 * @param base The base of the number.
 * @return The ft_nbrlen() function returns the length of the number in the given
 * base.
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

// #endregion

#endif
