/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 05:17:38 by moutdili          #+#    #+#             */
/*   Updated: 2024/10/12 05:30:20 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>  // Pour les va_list, va_start, etc.
#include <stddef.h>

// Déclaration des fonctions
int ft_printf(const char *format, ...);
void flush_buffer(char *buffer, int *index);
int print_char_buffered(char c, char *buffer, int *index);
int print_str(char *s, char *buffer, int *index);
int print_number_base(unsigned long n, int base, char *range, char *buffer, int *index);
int print_unsigned(unsigned int n, char *buffer, int *index);
int print_hex(unsigned int n, int uppercase, char *buffer, int *index);
int print_pointer(void *ptr, char *buffer, int *index);
int handle_format(char specifier, va_list args, char *buffer, int *index);

#endif
