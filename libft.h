/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:53:21 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 15:46:35 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/**
 * @brief The isalpha() function tests for any character for which isupper(3)
 * or islower(3) is true. The value of the argument must be representable as
 * an unsigned char or the value of EOF.
 * @param c The character to test.
 * @return The isalpha() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
*/
int		ft_isalpha(int c);
/**
 * @brief The isdigit() function tests for a decimal digit character.
 * Regardless of locale, this includes the following characters
 * only: '0' - '9'.
 * @param c The character to test.
 * @return The isdigit() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
*/
int		ft_isdigit(int c);
/**
 * @brief The isalnum() function tests for any character for which isalpha(3)
 * or isdigit(3) is true. The value of the argument must be representable as an
 * unsigned char or the value of EOF.
 * @param c The character to test.
 * @return The isalnum() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
*/
int		ft_isalnum(int c);
/**
 * @brief The isascii() function tests for an ASCII character, which is any
 * character between 0 and octal 0177 inclusive.
 * @param c The character to test.
 * @return The isascii() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
*/
int		ft_isascii(int c);
/**
 * @brief The isprint() function tests for any printing character, including
 * space (' '). The value of the argument must be representable as an unsigned
 * char or the value of EOF.
 * @param c The character to test.
 * @return The isprint() function returns zero if the character tests false and
 * returns non-zero if the character tests true.
*/
int		ft_isprint(int c);
/**
 * @brief The strlen() function calculates the length of the string s, excluding
 * the terminating null byte ('\0').
 * @param s The string to calculate the length of.
 * @return The strlen() function returns the number of bytes in the string s.
*/
size_t	ft_strlen(const char *s);
/**
 * @brief The memset() function fills the first len bytes of the memory area
 * pointed to by b with the constant byte c.
 * @param b The memory area to fill.
 * @param c The byte to fill the memory area with.
 * @param len The number of bytes to fill.
 * @return The memset() function returns a pointer to the memory area b.
*/
void	*ft_memset(void *b, int c, size_t len);
/**
 * @brief The bzero() function writes n zeroed bytes to the string s. If n is
 * zero, bzero() does nothing.
 * @param s The string to write to.
 * @param n The number of bytes to write.
*/
void	ft_bzero(void *s, size_t n);
/**
 * @brief The memcpy() function copies n bytes from memory area src to memory
 * area dst. If dst and src overlap, behavior is undefined. Applications in
 * which dst and src might overlap should use memmove(3) instead.
 * @param dst The destination to copy to.
 * @param src The source to copy from.
 * @param n The number of bytes to copy.
 * @return The memcpy() function returns the original value of dst.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief The memmove() function copies len bytes from string src to string dst.
 * The two strings may overlap; the copy is always done in a non-destructive
 * manner.
 * @param dst The destination to copy to.
 * @param src The source to copy from.
 * @param len The number of bytes to copy.
 * @return The memmove() function returns the original value of dst.
*/
void	*ft_memmove(void *dst, const void *src, size_t len);
/**
 * @brief The strlcpy() function copies up to size - 1 characters from the NUL-
 * terminated string src to dst, NUL-terminating the result.
 * @param dst The destination to copy to.
 * @param src The source to copy from.
 * @param size The size of the destination buffer.
 * @return The strlcpy() function returns the total length of the string it
 * tried to create.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
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
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @brief The toupper() function converts a lower-case letter to the
 * corresponding upper-case letter. The argument must be representable as an
 * unsigned char or the value of EOF.
 * @param c The character to convert.
 * @return If the argument is a lower-case letter, the toupper() function
 * returns the corresponding upper-case letter if there is one; otherwise, the
 * argument is returned unchanged.
*/
int		ft_toupper(int c);
/**
 * @brief The tolower() function converts an upper-case letter to the
 * corresponding lower-case letter. The argument must be representable as an
 * unsigned char or the value of EOF.
 * @param c The character to convert.
 * @return If the argument is an upper-case letter, the tolower() function
 * returns the corresponding lower-case letter if there is one; otherwise, the
 * argument is returned unchanged.
*/
int		ft_tolower(int c);
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
char	*ft_strchr(const char *s, int c);
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
char	*ft_strrchr(const char *s, int c);
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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
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
void	*ft_memchr(const void *s, int c, size_t n);
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
int		ft_memcmp(const void *s1, const void *s2, size_t n);
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
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/**
 * @brief The atoi() function converts the initial portion of the string pointed
 * to by str to int representation.
 * @param str The string to convert.
 * @return The atoi() function returns the converted value.
*/
int		ft_atoi(const char *str);
/**
 * @brief The calloc() function allocates memory for an array of nmemb elements
 * of size bytes each and returns a pointer to the allocated memory. The memory
 * is set to zero. If nmemb or size is 0, then calloc() returns either NULL, or
 * a unique pointer value that can later be successfully passed to free().
 * @param nmemb The number of elements to allocate memory for.
 * @param size The size of each element.
 * @return The calloc() function returns a pointer to the allocated memory.
*/
void	*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief The strdup() function allocates sufficient memory for a copy of the
 * string s1, does the copy, and returns a pointer to it. The pointer may
 * subsequently be used as an argument to the function free(3).
 * @param s The string to duplicate.
 * @return The strdup() function returns a pointer to the duplicated string.
*/
char	*ft_strdup(const char *s);
/**
 * @brief The substr() function allocates and returns a substring from the
 * string 's'. The substring begins at index 'start' and is of maximum size
 * 'len'.
 * @param s The string to create the substring from.
 * @param start The start index of the substring.
 * @param len The maximum size of the substring.
 * @return The substr() function returns the substring.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief The strjoin() function allocates and returns a new string, which is
 * the result of the concatenation of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The strjoin() function returns the new string.
*/
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief The strtrim() function allocates and returns a copy of 's1' with the
 * characters specified in 'set' removed from the beginning and the end of the
 * string.
 * @param s1 The string to trim.
 * @param set The set of characters to trim.
 * @return The strtrim() function returns the trimmed string.
*/
char	*ft_strtrim(char const *s1, char const *set);
/**
 * @brief The split() function allocates and returns an array of strings
 * obtained by splitting 's' using the character 'c' as a delimiter. The array
 * must be ended by a NULL pointer.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return The split() function returns the array of new strings.
*/
char	**ft_split(char const *s, char c);
/**
 * @brief The itoa() function allocates and returns a string representing the
 * integer received as an argument.
 * @param n The integer to convert.
 * @return The itoa() function returns the string representing the integer.
*/
char	*ft_itoa(int n);
/**
 * @brief The strmapi() function applies the function 'f' to each character of
 * the string 's' to create a new string resulting from successive applications
 * of 'f'.
 * @param s The string to map.
 * @param f The function to apply.
 * @return The strmapi() function returns the new string.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief The putchar_fd() function outputs the character 'c' to the given file
 * descriptor.
 * @param c The character to output.
 * @param fd The file descriptor to output to.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
/**
 * @brief The putchar_fd() function outputs the character 'c' to the given file
 * descriptor.
 * @param c The character to output.
 * @param fd The file descriptor to output to.
*/
void	ft_putchar_fd(char c, int fd);
/**
 * @brief The putstr_fd() function outputs the string 's' to the given file
 * descriptor.
 * @param s The string to output.
 * @param fd The file descriptor to output to.
*/
void	ft_putstr_fd(char *s, int fd);
/**
 * @brief The putendl_fd() function outputs the string 's' to the given file
 * descriptor, followed by a newline.
 * @param s The string to output.
 * @param fd The file descriptor to output to.
*/
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief The putnbr_fd() function outputs the integer 'n' to the given file
 * descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor to output to.
*/
void	ft_putnbr_fd(int n, int fd);

#endif
