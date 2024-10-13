/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:20:49 by moutdili          #+#    #+#             */
/*   Updated: 2024/10/13 06:14:07 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>

# define BUFFER_SIZE 1024

int	print_char_buffered(char c, char *buffer, int *index);
int	print_str(const char *str, char *buffer, int *index);
int	print_number(long n, char *buffer, int *index);
int	print_unsigned(unsigned long n, char *buffer, int *index);
int	print_hex(unsigned long n, char *buffer, int *index, int uppercase);
int	print_pointer(void *ptr, char *buffer, int *index);
int	handle_format(char specifier, va_list args, char *buffer, int *index);
int	process_char(const char **format, va_list args, char *buffer, int *index);
int	ft_printf(const char *format, ...);

#endif
