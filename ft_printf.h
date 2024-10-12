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

#include <stdarg.h>
#include <stddef.h>

int print_char(char c);
int print_str(char *s, char *buffer, int *index);
int print_unsigned(unsigned int n, char *buffer, int *index);
int print_hex(unsigned int n, int uppercase, char *buffer, int *index);
int ft_printf(const char *format, ...);

#endif

